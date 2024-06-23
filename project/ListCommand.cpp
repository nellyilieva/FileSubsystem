#include "ListCommand.h"

void ListCommand::execute(FileSubsystem* fs) {
	fs->list();
}