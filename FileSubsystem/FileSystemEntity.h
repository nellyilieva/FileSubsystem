#pragma once
#include <iostream>
#include "MyString.h"
#include "Time.h"

class FileSystemEntity {
protected:
	MyString name;
	MyString creationDate;
	MyString modificationDate;

public:
	FileSystemEntity(const MyString& _name);
	virtual ~FileSystemEntity() = default;

	const MyString& getName() const;
	const MyString& getCreationDate() const;
	const MyString& getModificationDate() const;

	virtual void printInfo() const = 0;

	void updateModificationDate();
};
