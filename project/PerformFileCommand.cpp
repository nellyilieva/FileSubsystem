#include "PerformFileCommand.h"

PerformFileCommand::PerformFileCommand(const MyString& path) : path(path) {}

void PerformFileCommand::execute(FileSubsystem* fs) {
	fs->exec(path);
}