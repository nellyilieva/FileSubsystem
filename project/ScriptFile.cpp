#include "ScriptFile.h"
#include <iostream>
#include <sstream>

ScriptFile::ScriptFile(const MyString& name, Directory* parent) : File(name, parent) {}

void ScriptFile::executeFile() const {
	
}