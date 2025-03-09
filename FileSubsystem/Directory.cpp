#include "Directory.h"
#include "File.h"
#include "HelperFunctions.h"
#include <iostream>

void Directory::copyFrom(const Directory& other) {
	for (int i = 0; i < other.directories.getSize(); i++) {
		Directory* d = new Directory(*other.directories[i]);
		directories.pushBack(d);
	}

	parent = other.parent;

	for (int i = 0; i < other.files.getSize(); i++) {
		File* f = new File(*other.files[i]);
		files.pushBack(f);
	}
}

void Directory::moveFrom(Directory&& other) {
	directories = std::move(other.directories);
	other.directories.clear();

	parent = other.parent;
	other.parent = nullptr;

	files = std::move(other.files);
	other.files.clear();
}

void Directory::free() {
	for (int i = 0; i < directories.getSize(); i++) {
		delete directories[i];
	}

	directories.clear();

	parent = nullptr;

	for (int i = 0; i < files.getSize(); i++) {
		delete files[i];
	}

	files.clear();
}

Directory::Directory(const MyString& _name) : FileSystemEntity(_name) {}

Directory::Directory(const MyString& _name, Directory* _parent) : FileSystemEntity(_name), parent(parent) {}

Directory::~Directory() {
	free();
}

Directory::Directory(const Directory& other) : FileSystemEntity(other) {
    copyFrom(other);
}

Directory& Directory::operator=(const Directory& other) {
    if (this != &other) {
        FileSystemEntity::operator=(other);
        free();
        copyFrom(other);
    }
    return *this;
}

Directory::Directory(Directory&& other) noexcept : FileSystemEntity(std::move(other)) {
    moveFrom(std::move(other));
}

Directory& Directory::operator=(Directory&& other) noexcept {
    if (this != &other) {
        FileSystemEntity::operator=(std::move(other));
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

Directory* Directory::getParentDirectory() const {
	return parent;
}


Directory* Directory::findDirectoryRecursion(const Vector<MyString>& elements, size_t idx) {
	if (idx >= elements.getSize()) {
		return this; //current directory; reached the end of the path; base case
	}

	for (int i = 0; i < directories.getSize(); i++) {
		if (directories[i]->getName() == elements[idx]) {
			return directories[i]->findDirectoryRecursion(elements, idx + 1);
		}
	}

	return nullptr;
}

Directory* Directory::findDirectory(const MyString& path) {   //path -> directories separeted by /
	Vector<MyString> elements = splitPath(path);

	return findDirectoryRecursion(elements, 0);
}


File* Directory::findFile(const MyString& path) {
	Vector<MyString> elements = splitPath(path);

	return findFileRecursion(elements, 0, this);
}

File* Directory::findFileRecursion(const Vector<MyString>& elements, size_t idx, Directory* currentDir) {
	if (idx >= elements.getSize()) {
		return nullptr;
	}

	const MyString& currentName = elements[idx];

	Directory* nextDir = currentDir->findDirByName(currentName);
	if (nextDir) {
		return findFileRecursion(elements, idx + 1, nextDir);
	}
	else {
		File* foundFile = currentDir->findFileByName(currentName);
		if (foundFile) {
			if (idx == elements.getSize() - 1) {
				return foundFile;
			}
			else {
				return nullptr;
			}
		}
		else {
			return nullptr;
		}
	}
}


Vector<Directory*> Directory::getDirectories() const {
	return directories;
}

Vector<File*> Directory::getFiles() const {
	return files;
}

void Directory::addDirectory(Directory* d) {
	directories.pushBack(d);
}

void Directory::addFile(File* f) {
	files.pushBack(f);
}

void Directory::removeDirectory(const MyString& name) {
	for (int i = 0; i < directories.getSize(); i++) {
		if (directories[i]->getName() == name) {
			delete directories[i];
			directories.erase(i);
			return;
		}
	}
}

void Directory::removeFile(const MyString& name) {
	for (int i = 0; i < files.getSize(); i++) {
		if (files[i]->getName() == name) {
			delete files[i];
			files.erase(i);
			return;
		}
	}
}

void Directory::printInfo() const {
	FileSystemEntity::printInfo();

	for (size_t i = 0; i < directories.getSize(); i++) {
		std::cout << " Directory: ";
		directories[i]->printInfo();
		std::cout << "\n";
	}

	for (size_t i = 0; i < files.getSize(); i++) {
		std::cout << "  ";
		files[i]->printInfo();
		std::cout << "\n";
	}
}

Vector<MyString> Directory::getAbsolutePath() const {
	Vector<MyString> elements;

	const Directory* currDirectory = this;

	while (currDirectory != nullptr) {
		elements.pushBack(currDirectory->getName());
		currDirectory = currDirectory->parent;
	}

	return elements;
}

bool Directory::checkName(const MyString& name) const {
	for (int i = 0; i < directories.getSize(); i++) {
		if (directories[i]->getName() == name) {
			return true;
		}
	}

	for (int i = 0; i < files.getSize(); i++) {
		if (files[i]->getName() == name) {
			return true;
		}
	}

	for (int i = 0; i < directories.getSize(); i++) {  //recursion to check every directory/file
		if (directories[i]->checkName(name)) {
			return true;
		}
	}

	return false;
}

 Directory* Directory::findDirByName(const MyString& name) const {
	for (size_t i = 0; i < directories.getSize(); i++) {
		if (directories[i]->getName() == name) {
			return directories[i];
		}
	}
	return nullptr;
}

File* Directory::findFileByName(const MyString& name) const {
	for (size_t i = 0; i < files.getSize(); i++) {
		if (files[i]->getName() == name) {
			return files[i];
		}
	}
	return nullptr;
}
<<<<<<< HEAD:FileSubsystem/Directory.cpp

MyString Directory::serialize() const {
	MyString serializedData = name + "\n";

	serializedData += creationDate + "\n";
	serializedData += modificationDate + "\n";

	serializedData += MyString(intToStr(directories.getSize()).c_str()) + "\n";

	for (size_t i = 0; i < directories.getSize(); i++) {
		serializedData += directories[i]->serialize();
	}

	serializedData += MyString(intToStr(files.getSize()).c_str()) + "\n";

	for (size_t i = 0; i < files.getSize(); i++) {
		serializedData += files[i]->getName() + "\n";
		serializedData += files[i]->getCreationDate() + "\n";
		serializedData += files[i]->getModificationDate() + "\n";
		serializedData += files[i]->getData() + "\n";
	}

	return serializedData;
}

Directory* Directory::deserialize(const MyString& data, Directory* parent) {
	Vector<MyString> lines = data.split('\n');
	size_t index = 0;

	MyString dirName = lines[index++];

	Directory* dir = new Directory(dirName, parent);

	dir->creationDate = lines[index++];
	dir->modificationDate = lines[index++];

	int numDirectories = std::stoi(lines[index++].c_str());

	for (int i = 0; i < numDirectories; i++) {
		Directory* subDir = deserialize(lines[index++], dir);
		dir->addDirectory(subDir);
	}

	int numFiles = std::stoi(lines[index++].c_str());

	for (int i = 0; i < numFiles; i++) {
		MyString fileName = lines[index++];
		MyString fileCreationDate = lines[index++];
		MyString fileModificationDate = lines[index++];
		MyString fileData = lines[index++];

		File* file = new File(fileName, dir);
		file->creationDate = fileCreationDate;
		file->modificationDate = fileModificationDate;
		file->data = fileData;

		dir->addFile(file);
	}

	return dir;
}

=======
>>>>>>> 56db1ce39d3031aa3d17038c21d9d0b1a5960551:project/Directory.cpp
