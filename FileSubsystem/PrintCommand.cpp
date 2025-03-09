#include "PrintCommand.h"

PrintCommand::PrintCommand(const MyString& str) : str(str) {}

void PrintCommand::execute(FileSubsystem* fs) {
    if (!fs) {
        throw std::runtime_error("FileSubsystem is null!");
    }
    fs->print(str);
}