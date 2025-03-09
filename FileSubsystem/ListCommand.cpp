#include "ListCommand.h"

void ListCommand::execute(FileSubsystem* fs) {
    if (!fs) {
        throw std::runtime_error("FileSubsystem is null!");
    }
    fs->list();
}