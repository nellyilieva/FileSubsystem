#include "ChangeDirectoryCommand.h"

ChangeDirectoryCommand::ChangeDirectoryCommand(const MyString& path) : path(path) {}

void ChangeDirectoryCommand::execute(FileSubsystem* fs) {
    if (!fs) {
        throw std::runtime_error("FileSubsystem is null!");
    }
    fs->changeDirectory(path);
}