#include "LinkFile.h"
#include <iostream>

LinkFile::LinkFile(const MyString& name, Directory* parent) : File(name, parent) {}

void LinkFile::executeFile() const {
	Vector<MyString> elements = splitPath(getData());

	
}