#include "ExitCommand.h"

void ExitCommand::execute(FileSubsystem* fs) {
    if (!fs) {
        throw std::runtime_error("FileSubsystem is null!");
    }
    fs->exit();
}