#include "AddCommand.h"


AddCommand::AddCommand(const MyString& str, const MyString& name) : str(str), name(name) {}

void AddCommand::execute(FileSubsystem* fs) {
    if (!fs) {
        throw std::runtime_error("FileSubsystem is null!");
    }
    try {
        fs->add(str, name);
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
}