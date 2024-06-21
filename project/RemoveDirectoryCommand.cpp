#include "RemoveDirectoryCommand.h"

RemoveDirectoryCommand::RemoveDirectoryCommand(const MyString& path) : path(path) {}

void RemoveDirectoryCommand::execute(FileSubsystem* fs) {
	//exceptions here???
	fs->removeDirectory(path);
}