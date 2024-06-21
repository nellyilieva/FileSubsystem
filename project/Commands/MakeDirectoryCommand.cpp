#include "MakeDirectoryCommand.h"

MakeDirectoryCommand::MakeDirectoryCommand(const MyString& path) : name(name) {}

void MakeDirectoryCommand::execute(FileSubsystem* fs) {
	//exceptions here???
	fs->makeDirectory(name);
}