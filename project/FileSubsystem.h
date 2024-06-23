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

	void changeDirectory(const MyString& path);                   //cd
	void list() const;                                            //ls
	void list(const MyString& path) const;                        //ls
	void printDirectoryPath() const;                              //pwd
	void makeDirectory(const MyString& name);                     //mkdir
	void removeDirectory(const MyString& path);                   //rmdir

	void createFile(const MyString& name);                        //touch
	void removeFile(const MyString& path);                        //rm	
	void exec(const MyString& path);                              //exec
	void rewrite(const MyString& str, const MyString& name);      //echo
	void add(const MyString& str, const MyString& name);          //echo

	void find(const MyString& path, const MyString& str) const;   //find
	void print(const MyString& str) const;                        //echo
	
	void exit();                                                  //exit
};