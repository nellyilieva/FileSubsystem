#include "FileSystemEntity.h"
#include <iostream>

FileSystemEntity::FileSystemEntity(const MyString& _name) : name(_name) {
	creationDate = time(nullptr);
	modificationDate = creationDate;
}

const MyString& FileSystemEntity::getName() const {
	return name;
}

time_t FileSystemEntity::getCreationDate() const {
	return creationDate;
}

time_t FileSystemEntity::getModificationDate() const {
	return modificationDate;
}