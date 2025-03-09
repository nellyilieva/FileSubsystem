#pragma once
#include <iostream>
#include "Directory.h"
#include "File.h"
#include "TextFile.h"
#include "ScriptFile.h"
#include "LinkFile.h"

class FileSubsystem {
private:
	Directory* root;
	Directory* currentDirectory;

	File* getFileType(const MyString& name, Directory* currentDirectory);

public:
	FileSubsystem();
	FileSubsystem(Directory* d);
	~FileSubsystem();

	Directory* getRoot() const;
	Directory* getCurrentDirectory() const;

	void changeDirectory(const MyString& path);
	void list() const;
	void list(const MyString& path) const;
	void printDirectoryPath() const;
	void makeDirectory(const MyString& name);
	void removeDirectory(const MyString& path);

	void createFile(const MyString& name);
	void removeFile(const MyString& path);	
	void exec(const MyString& path);
	void rewrite(const MyString& str, const MyString& name);
	void add(const MyString& str, const MyString& name);

	void find(const MyString& path, const MyString& str) const;
	void print(const MyString& str) const;
	
	void exit();
};