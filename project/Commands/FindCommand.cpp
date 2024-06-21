#include "FindCommand.h"


FindCommand::FindCommand(const MyString& path, const MyString& str) : path(path), str(str) {}

void FindCommand::execute(FileSubsystem* fs) {
	fs->find(path, str);
}