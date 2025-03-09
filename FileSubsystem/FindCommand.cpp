#include "FindCommand.h"


FindCommand::FindCommand(const MyString& path, const MyString& str) : path(path), str(str) {}

void FindCommand::execute(FileSubsystem* fs) {
	if (!fs) {
        throw std::runtime_error("FileSubsystem is null!");
    }
    try {
        fs->find(path, str);
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
}