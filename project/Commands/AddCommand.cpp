#include "AddCommand.h"


AddCommand::AddCommand(const MyString& str, const MyString& name) : str(str), name(name) {}

void AddCommand::execute(FileSubsystem* fs) {
	fs->add(str, name);
}