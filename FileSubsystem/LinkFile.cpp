#include "LinkFile.h"
#include <iostream>
#include "FileSubsystem.h" // Assuming FileSubsystem handles file execution

LinkFile::LinkFile(const MyString& name, Directory* parent, const MyString& targetPath) : File(name, parent), targetPath(targetPath) {}

void LinkFile::executeFile() const {
    std::cout << "Executing Link File: " << getName() << "\n";
    std::cout << "Target Path: " << targetPath << "\n";

    File* targetFile = getParentDirectory()->findFile(targetPath);
    if (targetFile) {
        std::cout << "Executing Target File: " << targetFile->getName() << "\n";
        targetFile->executeFile();
    }
    else {
        std::cerr << "Error: Target file not found.\n";
    }
}