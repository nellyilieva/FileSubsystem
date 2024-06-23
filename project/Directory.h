#pragma once
#include <iostream>
#include "FileSystemEntity.h"
#include "File.h"
#include "Vector.hpp"

class Directory : public FileSystemEntity {
private:
	Vector<Directory*> directories;
	Vector<File*> files;
	Directory* parent;

	void copyFrom(const Directory& other);
	void moveFrom(Directory&& other);
	void free();

	Directory* findDirectoryRecursion(const Vector<MyString>& elements, size_t idx);

public:
	Directory(const MyString& _name);
	Directory(const MyString& _name, Directory* _parent);
	~Directory();

    Directory(const Directory& other);
    Directory& operator=(const Directory& other);
	Directory(Directory&& other) noexcept;
	Directory& operator=(Directory&& other) noexcept;

	Vector<Directory*> getDirectories() const;
	Vector<File*> getFiles() const;

	Directory* getParentDirectory() const;

	Directory* findDirectory(const MyString& path);

	void addDirectory(Directory* d);
	void addFile(File* f);

	void removeDirectory(const MyString& name);
	void removeFile(const MyString& name);

	//bool isDirectory() const override;

	void printInfo() const override;

	Vector<MyString> getAbsolutePath() const;

	bool checkName(const MyString& name) const;
};