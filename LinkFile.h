#pragma once
#include <iostream>
#include "File.h"

class LinkFile : public File {
public:
	LinkFile(const MyString& _name);
};