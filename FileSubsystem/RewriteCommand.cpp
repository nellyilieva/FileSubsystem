#include "RewriteCommand.h"


RewriteCommand::RewriteCommand(const MyString& str, const MyString& name) : str(str), name(name) {}

void RewriteCommand::execute(FileSubsystem* fs) {
    if (!fs) {
        throw std::runtime_error("FileSubsystem is null!");
    }
    try {
        fs->rewrite(str, name);
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
}