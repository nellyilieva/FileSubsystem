#include "CreateFileCommand.h"

CreateFileCommand::CreateFileCommand(const MyString& name) : name(name) {}

void CreateFileCommand::execute(FileSubsystem* fs) {
    if (!fs) {
        throw std::runtime_error("FileSubsystem is null!");
    }
    try {
        fs->createFile(name);
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
}