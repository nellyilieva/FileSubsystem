#include "ChangeDirectoryCommand.h"

ChangeDirectoryCommand::ChangeDirectoryCommand(const MyString& path) : path(path) {}

void ChangeDirectoryCommand::execute(FileSubsystem* fs) {
	fs->changeDirectory(path);
}