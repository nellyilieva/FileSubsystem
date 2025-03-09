#include "AbsolutePathCommand.h"

void AbsolutePathCommand::execute(FileSubsystem* fs) {
    if (!fs) {
        throw std::runtime_error("FileSubsystem is null!");
    }
    fs->printDirectoryPath();
}