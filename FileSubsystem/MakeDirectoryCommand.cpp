#include "MakeDirectoryCommand.h"

MakeDirectoryCommand::MakeDirectoryCommand(const MyString& path) : name(name) {}

void MakeDirectoryCommand::execute(FileSubsystem* fs) {
    if (!fs) {
        throw std::runtime_error("FileSubsystem is null!");
    }
    try {
        fs->makeDirectory(name);
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
}