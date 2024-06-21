#include "File.h"
#include <iostream>

File::File(const MyString& _name) : FileSystemEntity(_name), data("") {}

const MyString& File::getData() const {
	return data;
}

bool File::isDirectory() const {
	return false;
}