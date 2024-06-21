#include "ListDirectoryCommand.h"

ListDirectoryCommand::ListDirectoryCommand(const MyString& path) : path(path) {}

void ListDirectoryCommand::execute(FileSubsystem* fs) {
	fs->list(path);
}