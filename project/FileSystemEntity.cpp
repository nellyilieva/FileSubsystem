#include "FileSystemEntity.h"
#include "HelperFunctions.h"
#include <iostream>

FileSystemEntity::FileSystemEntity(const MyString& _name) : name(_name), creationDate(Time::getCurrentTime()), modificationDate(Time::getCurrentTime()) {}

const MyString& FileSystemEntity::getName() const {
	return name;
}

const MyString& FileSystemEntity::getCreationDate() const {
	return creationDate;
}

const MyString& FileSystemEntity::getModificationDate() const {
	return modificationDate;
}

void FileSystemEntity::printInfo() const {
	std::cout << getCreationDate() << " " << getName() << "\n";
	std::cout << "Last modification at: " << getModificationDate() << "\n";
}

void FileSystemEntity::updateModificationDate() {
	modificationDate = Time::getCurrentTime();
}

