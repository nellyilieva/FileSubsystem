#include "RemoveFileCommand.h"

RemoveFileCommand::RemoveFileCommand(const MyString& path) : path(path) {}

void RemoveFileCommand::execute(FileSubsystem* fs) {
	//exceptions here???
	fs->removeFile(path);
}