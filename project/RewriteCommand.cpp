#include "RewriteCommand.h"


RewriteCommand::RewriteCommand(const MyString& str, const MyString& name) : str(str), name(name) {}

void RewriteCommand::execute(FileSubsystem* fs) {
	fs->rewrite(str, name);
}