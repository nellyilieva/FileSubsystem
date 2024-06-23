#pragma once
#include <iostream>
#include "FileSystemEntity.h"
#include "Vector.hpp"

class Directory : public FileSystemEntity {
private:
	Vector<FileSystemEntity*> entities;
	Directory* parent;

public:
	Directory(const MyString& _name);
	Directory(const MyString& _name, Directory* _parent);
	~Directory();

	//copy and move semantics!!!!!!!

	Vector<FileSystemEntity*> getEntities() const;

	Directory* getParentDirectory() const;

	Directory* findDirectory(const MyString& name); //check again

	void addEntity(FileSystemEntity* entity);
	//void removeEntity(FileSystemEntity* entity);

	bool isDirectory() const override;

	void printInfo() const override;
};