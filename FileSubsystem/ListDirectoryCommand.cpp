#include "ListDirectoryCommand.h"

ListDirectoryCommand::ListDirectoryCommand(const MyString& path) : path(path) {}

void ListDirectoryCommand::execute(FileSubsystem* fs) {
    if (!fs) {
        throw std::runtime_error("FileSubsystem is null!");
    }
    fs->list(path);
}