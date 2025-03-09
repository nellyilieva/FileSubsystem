#pragma once
#include <iostream>
#include "FileSystemEntity.h"

class Directory;

class File : public FileSystemEntity {
private:
	MyString data;
	Directory* parent;

	void copyFrom(const File& other);
	void moveFrom(File&& other) noexcept;
	void free();

public:
	File(const MyString& name, Directory* parent);
	File(const File& other);
	File& operator=(const File& other);
	File(File&& other) noexcept;
	File& operator=(File&& other) noexcept;
	~File();

	const MyString& getData() const;
	void setData(const MyString& newData);

	void printInfo() const override;

	//virtual void executeFile() const;

	Directory* getParentDirectory() const;
};