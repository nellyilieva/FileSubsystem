#include "FileSubsystem.h"

FileSubsystem::FileSubsystem() : root(nullptr), currentDirectory(nullptr) {} //check again

FileSubsystem::FileSubsystem(Directory* d) : root(d), currentDirectory(d) {}

FileSubsystem::~FileSubsystem() {
	delete root;
}

void FileSubsystem::changeDirectory(const MyString& path) {
	if (path == "..") {
		if (currentDirectory->getParentDirectory() != nullptr) {
			currentDirectory = currentDirectory->getParentDirectory();
		}
		else {
			throw std::exception("At root directory!");
		}
	}
	else {
		Directory* d = currentDirectory->findDirectory(path);

		if (d != nullptr) {
			currentDirectory = d;
		}

		else {
			throw std::runtime_error("Directory not found!");
		}
	}
}