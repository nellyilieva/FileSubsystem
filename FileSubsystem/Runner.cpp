#include "Runner.h"
#include "ChangeDirectoryCommand.h"
#include "ListCommand.h"
#include "ListDirectoryCommand.h"
#include "AbsolutePathCommand.h"
#include "MakeDirectoryCommand.h"
#include "RemoveDirectoryCommand.h"
#include "CreateFileCommand.h"
#include "RemoveFileCommand.h"
#include "PerformFileCommand.h"
#include "RewriteCommand.h"
#include "AddCommand.h"
#include "FindCommand.h"
#include "PrintCommand.h"
#include "ExitCommand.h"
#include <iostream>
#include <sstream>

void run() {
    FileSubsystem fs;
    std::cout << "Welcome to the File System Terminal!\n";
    std::cout << "Type 'exit' to quit.\n";

    while (true) {
        std::cout << fs.getCurrentDirectory()->getName() << "> ";
        MyString input;
        std::getline(std::cin, input);

        if (input.isEmpty()) {
            continue;=
        }

        std::istringstream iss(input.c_str());
        MyString command;
        iss >> command;

        try {
            if (command == "cd") {
                MyString path;
                iss >> path;
                ChangeDirectoryCommand cdCommand(path);
                cdCommand.execute(&fs);
            }
            else if (command == "ls") {
                MyString path;
                iss >> path;
                if (path.isEmpty()) {
                    ListCommand lsCommand;
                    lsCommand.execute(&fs);
                }
                else {
                    ListDirectoryCommand lsDirCommand(path);
                    lsDirCommand.execute(&fs);
                }
            }
            else if (command == "pwd") {
                AbsolutePathCommand pwdCommand;
                pwdCommand.execute(&fs);
            }
            else if (command == "mkdir") {
                MyString dirName;
                iss >> dirName;
                MakeDirectoryCommand mkdirCommand(dirName);
                mkdirCommand.execute(&fs);
            }
            else if (command == "rmdir") {
                MyString dirPath;
                iss >> dirPath;
                RemoveDirectoryCommand rmdirCommand(dirPath);
                rmdirCommand.execute(&fs);
            }
            else if (command == "touch") {
                MyString fileName;
                iss >> fileName;
                CreateFileCommand touchCommand(fileName);
                touchCommand.execute(&fs);
            }
            else if (command == "rm") {
                MyString filePath;
                iss >> filePath;
                RemoveFileCommand rmCommand(filePath);
                rmCommand.execute(&fs);
            }
            else if (command == "exec") {
                MyString filePath;
                iss >> filePath;
                PerformFileCommand execCommand(filePath);
                execCommand.execute(&fs);
            }
            else if (command == "echo") {
                MyString text;
                std::getline(iss, text);
                if (text.find(">>") != MyString::npos) {

                    size_t pos = text.find(">>");
                    MyString fileContent = text.substr(0, pos).trim();
                    MyString fileName = text.substr(pos + 2).trim();
                    AddCommand addCommand(fileContent, fileName);
                    addCommand.execute(&fs);
                }
                else if (text.find(">") != MyString::npos) {

                    size_t pos = text.find(">");
                    MyString fileContent = text.substr(0, pos).trim();
                    MyString fileName = text.substr(pos + 1).trim();
                    RewriteCommand rewriteCommand(fileContent, fileName);
                    rewriteCommand.execute(&fs);
                }
                else {

                    PrintCommand printCommand(text.trim());
                    printCommand.execute(&fs);
                }
            }
            else if (command == "find") {
                MyString path, searchStr;
                iss >> path >> searchStr;
                FindCommand findCommand(path, searchStr);
                findCommand.execute(&fs);
            }
            else if (command == "exit") {
                ExitCommand exitCommand;
                exitCommand.execute(&fs);
                break;
            }
            else {
                std::cerr << "Unknown command: " << command << "\n";
            }
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << "\n";
        }
    }
}