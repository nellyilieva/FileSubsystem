#include "TextFile.h"
#include <iostream>

TextFile::TextFile(const MyString& name, Directory* parent) : File(name, parent) {}

void TextFile::executeFile() const {
	std::cout << getData() << "/n";
}