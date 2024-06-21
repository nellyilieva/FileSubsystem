#pragma once
#include <iostream>
#include "FileSystemEntity.h"

class File : public FileSystemEntity {
private:
	MyString data;
public:
	File(const MyString& _name);
	const MyString& getData() const;
};