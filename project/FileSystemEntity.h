#pragma once
#include <iostream>
#include <ctime>
#include "MyString.h"

class FileSystemEntity {
private:
	MyString name;
	time_t creationDate;    //Time from lectures???
	time_t modificationDate;  //neshto otdelno za time i date???

public:
	FileSystemEntity(const MyString& _name);
	virtual ~FileSystemEntity() = default;

	const MyString& getName() const;
	time_t getCreationDate() const;  //do we need get
	time_t getModificationDate() const;

	void printDate() const; //month - words; ?enum

	virtual bool isDirectory() const = 0;
};
