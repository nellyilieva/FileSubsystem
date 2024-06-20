#pragma once
#include <iostream>
#include "File.h"

class ScriptFile : public File {
public:
	ScriptFile(const MyString& _name);
	void execute();
};