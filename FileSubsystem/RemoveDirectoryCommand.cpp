#include "RemoveDirectoryCommand.h"

RemoveDirectoryCommand::RemoveDirectoryCommand(const MyString& path) : path(path) {}

void RemoveDirectoryCommand::execute(FileSubsystem* fs) {
    if (!fs) {
        throw std::runtime_error("FileSubsystem is null!");
    }
    try {
        fs->removeDirectory(path);
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
}