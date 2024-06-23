#include "Directory.h"

Directory::Directory(const MyString& _name) : FileSystemEntity(_name) {}

Directory::Directory(const MyString& _name, Directory* _parent) : FileSystemEntity(_name), parent(parent) {}

Directory::~Directory() {
	for (int i = 0; i < entities.getSize(); i++) {
		delete entities[i];
	}
}

bool Directory::isDirectory() const {
	return true;
}

Directory* Directory::getParentDirectory() const {
	return parent;
}

Directory* Directory::findDirectory(const MyString& name) {
	for (int i = 0; i < entities.getSize(); i++) {
		if (entities[i]->isDirectory() && entities[i]->getName() == name) {
			return dynamic_cast<Directory*>(entities[i]);
		}
	}

	return nullptr;
}

Vector<FileSystemEntity*> Directory::getEntities() const {
	return entities;
}

void Directory::addEntity(FileSystemEntity* entity) {
	entities.pushBack(entity);
}

//void Directory::removeEntity(FileSystemEntity* entity) {
//	entities.
//}

void Directory::printInfo() const {
	for (int i = 0; i < entities.getSize(); i++) {
		entities[i]->FileSystemEntity::printInfo();
	}
}