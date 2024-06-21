#include "CreateFileCommand.h"

CreateFileCommand::CreateFileCommand(const MyString& name) : name(name) {}

void CreateFileCommand::execute(FileSubsystem* fs) {
	fs->createFile(name);
}