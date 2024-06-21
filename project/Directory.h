#pragma once
#include <iostream>
#include "FileSystemEntity.h"
#include "Vector.hpp"

class Directory : public FileSystemEntity {
private:
	Vector<FileSystemEntity> entities;

public:
	Directory(const MyString& _name);
	~Directory();
};