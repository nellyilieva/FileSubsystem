#include "RemoveFileCommand.h"

RemoveFileCommand::RemoveFileCommand(const MyString& path) : path(path) {}

void RemoveFileCommand::execute(FileSubsystem* fs) {
    if (!fs) {
        throw std::runtime_error("FileSubsystem is null!");
    }
    try {
        fs->removeFile(path);
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
}