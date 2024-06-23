#pragma once
#include <iostream>
#include "FileSystemEntity.h"
#include "Directory.h"

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
	void printInfo() const override;

	Directory* getParentDirectory() const;
};