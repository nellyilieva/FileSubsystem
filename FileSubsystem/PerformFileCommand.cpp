#include "PerformFileCommand.h"

PerformFileCommand::PerformFileCommand(const MyString& path) : path(path) {}

void PerformFileCommand::execute(FileSubsystem* fs) {
    if (!fs) {
        throw std::runtime_error("FileSubsystem is null!");
    }
    try {
        fs->exec(path);
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
}