#pragma once
#include <iostream>
#include "File.h"

class TextFile : public File {
public:
	TextFile(const MyString& name, Directory* parent);
};