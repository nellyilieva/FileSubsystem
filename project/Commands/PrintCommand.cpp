#include "PrintCommand.h"

PrintCommand::PrintCommand(const MyString& str) : str(str) {}

void PrintCommand::execute(FileSubsystem* fs) {
	fs->print(str);
}