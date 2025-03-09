#include "ScriptFile.h"
#include "FileSubsystem.h"
#include <iostream>
#include <sstream>

ScriptFile::ScriptFile(const MyString& name, Directory* parent) : File(name, parent) {}

void ScriptFile::executeFile() const {
    std::cout << "Executing Script File: " << getName() << "\n";

    std::istringstream stream(getData());
    MyString command;

    while (std::getline(stream, command)) {
        std::cout << "Executing Command: " << command << "\n";
        // Here, you would call the FileSubsystem to execute the command
        // For example: FileSubsystem::executeCommand(command);
    }
}