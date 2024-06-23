#include "FileSubsystem.h"

FileSubsystem::FileSubsystem() {     //check again
	root = new Directory("root");
	currentDirectory = root;
}

FileSubsystem::FileSubsystem(Directory* d) : root(d), currentDirectory(d) {}

FileSubsystem::~FileSubsystem() {
	delete root;
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

void FileSubsystem::createFile(const MyString& name) {

}

void FileSubsystem::removeFile(const MyString& path) {

}