#pragma once
#include <iostream>
#include "File.h"

class ScriptFile : public File {
public:
	ScriptFile(const MyString& name, Directory* parent);
	void executeFile() const override;
};