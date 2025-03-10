#include "FileSubsystem.h"

FileSubsystem::FileSubsystem() {
	root = new Directory("root");
	currentDirectory = root;
}

FileSubsystem::FileSubsystem(Directory* d) : root(d), currentDirectory(d) {}

FileSubsystem::~FileSubsystem() {
	delete root;
}

Directory* FileSubsystem::getRoot() const {
	return root;
}

Directory* FileSubsystem::getCurrentDirectory() const {
	return currentDirectory;
}

void FileSubsystem::changeDirectory(const MyString& path) {
	if (path == "..") {
		if (currentDirectory && currentDirectory->getParentDirectory()) {
			currentDirectory = currentDirectory->getParentDirectory();
		}
		else {
			throw std::runtime_error("At root directory!");
		}
	}
	else {
		Directory* d = currentDirectory->findDirectory(path);

		if (d) {
			currentDirectory = d;
		}
		else {
			throw std::runtime_error("Directory not found!");
		}
	}
}

void FileSubsystem::list() const {
	currentDirectory->printInfo();
}

void FileSubsystem::list(const MyString& path) const {
	Directory* d = root->findDirectory(path);        //the path must start from the root
	if (d) {
		d->printInfo();
	}
	else {
		throw std::runtime_error("Directory not found!");
	}
}

void FileSubsystem::printDirectoryPath() const {
	Vector<MyString> elements = currentDirectory->getAbsolutePath();
	for (int i = elements.getSize() - 1; i >= 0; i--) {
		std::cout << elements[i];
		if (i > 0) {
			std::cout << "/";
		}
	}
	std::cout << "/n";
}

void FileSubsystem::makeDirectory(const MyString& name) {
	if (currentDirectory->checkName(name)) {
		throw std::runtime_error("Same name!");
	}
	else {
		Directory* d = new Directory(name, currentDirectory);
		currentDirectory->addDirectory(d);
	}
}

void FileSubsystem::removeDirectory(const MyString& path) {
	Directory* d = root->findDirectory(path);
	if (!d) {
		throw std::runtime_error("Do not exist!");
	}
	if (!d->getDirectories().empty() || !d->getFiles().empty()) {
		throw std::runtime_error("Has files/directories in it!");
	}

	Directory* parent = d->getParentDirectory();
	if (parent) {
		parent->removeDirectory(d->getName());
	}
	else {
		throw std::runtime_error("Parent do not exist!");
	}
}

File* FileSubsystem::getFileType(const MyString& name, Directory* currentDirectory) {
	size_t length = name.getSize();

	if (length >= 3 && name[length - 3] == '.' && name[length - 2] == 's' && name[length - 1] == 'h') {
		return new ScriptFile(name, currentDirectory);
	}
	else if (length >= 4 && name[length - 4] == '.' && name[length - 3] == 'l' && name[length - 2] == 'n' && name[length - 1] == 'k') {
		return new LinkFile(name, currentDirectory);
	}
	else {
		return new TextFile(name, currentDirectory);
	}
}

void FileSubsystem::createFile(const MyString& name) {
	FileSystemEntity* e = currentDirectory->findDirByName(name);
	if (e) {
		e->updateModificationDate();
		return;
	}
	e = currentDirectory->findFileByName(name);
	if (e) {
		e->updateModificationDate();
		return;
	}
	File* newFile = getFileType(name, currentDirectory);
	currentDirectory->addFile(newFile);
}

void FileSubsystem::removeFile(const MyString& path) {
	Vector<MyString> elements = splitPath(path);
	File* f = root->findFile(path);

	if (f) {
		Directory* parentDir = f->getParentDirectory();
		if (parentDir) {
			parentDir->removeFile(f->getName());
		}
		else {
			throw std::runtime_error("Parent do not exist!");
		}
	}
	else {
		throw std::runtime_error("Do not exist!");
	}
}

void FileSubsystem::exec(const MyString& path) {
	File* file = currentDirectory->findFile(path);
	if (file) {
		file->executeFile();
	}
	else {
		throw std::runtime_error("File not found!");
	}
}

void FileSubsystem::rewrite(const MyString& str, const MyString& name) {
	File* file = currentDirectory->findFileByName(name);
	if (file) {
		file->setData(str);
	}
	else {
		throw std::runtime_error("File not found!");
	}
}

void FileSubsystem::add(const MyString& str, const MyString& name) {
	File* file = currentDirectory->findFileByName(name);
	if (file) {
		file->setData(file->getData() + str);
	}
	else {
		throw std::runtime_error("File not found!");
	}
}

void FileSubsystem::find(const MyString& path, const MyString& str) const {
	Directory* dir = root->findDirectory(path);
	if (!dir) {
		throw std::runtime_error("Directory not found!");
	}

	Vector<FileSystemEntity*> entities;
	entities = dir->getFiles();
	for (size_t i = 0; i < entities.getSize(); i++) {
		if (entities[i]->getName().isSubstr(str)) {
			std::cout << "File: " << entities[i]->getName() << "\n";
		}
	}

	entities = dir->getDirectories();
	for (size_t i = 0; i < entities.getSize(); i++) {
		if (entities[i]->getName().isSubstr(str)) {
			std::cout << "Directory: " << entities[i]->getName() << "\n";
		}
	}

	Vector<Directory*> subDirs = dir->getDirectories();
	for (size_t i = 0; i < subDirs.getSize(); i++) {
		find(subDirs[i]->getName(), str);
	}
}

void FileSubsystem::print(const MyString& str) const {
	std::cout << str.c_str() << "/n";
}

void FileSubsystem::exit() {
	MyString serializedData = root->serialize();

	std::ofstream outFile("filesystem.dat", std::ios::binary);
	if (!outFile) {
		throw std::runtime_error("Failed to save file system!");
	}

	outFile.write(serializedData.c_str(), serializedData.getSize());
	outFile.close();

	std::cout << "File system saved. Exiting...\n";
}