#include "File.h"
#include "Directory.h"
#include <iostream>

void File::free() {
    delete parent;
    parent = nullptr;
}

void File::copyFrom(const File& other) {
    parent = new Directory(*other.parent);
}

void File::moveFrom(File&& other) noexcept {
    parent = other.parent;
    other.parent = nullptr;
}

File::File(const MyString& _name, Directory* _parent) : FileSystemEntity(_name), parent(_parent) {}

File::File(const File& other) : FileSystemEntity(other) {
    copyFrom(other);
}

File& File::operator=(const File& other) {
    if (this != &other) {
        FileSystemEntity::operator=(other);
        free();
        copyFrom(other);
    }
    return *this;
}

File::File(File&& other) noexcept : FileSystemEntity(std::move(other)) {
    moveFrom(std::move(other));
}

File& File::operator=(File&& other) noexcept {
    if (this != &other) {
        FileSystemEntity::operator=(std::move(other));
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

File::~File() {
    free();
}

const MyString& File::getData() const {
	return data;
}

void File::setData(const MyString& newData) {
    data = newData;
}

void File::printInfo() const {
    std::cout << "File: " << getName() << "\n";
}

//void File::executeFile() const {
//    std::cout << "Executing File: " << getName() << "\n";
//}

Directory* File::getParentDirectory() const {
    return parent;
}