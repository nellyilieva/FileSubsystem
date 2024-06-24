#include "Runner.h"
#include "FileSubsystem.h"

void run() {
	FileSubsystem fs;
	std::cout << fs.getRoot() << "/n";

	MyString command;

	while (true) {
		std::cin >> command;

		if (command == "cd") {
			char buff[1024];
			std::cin.ignore();
			std::cin.getline(buff, 1024);
			MyString input = buff;
			fs.changeDirectory(buff);
		}

		else if (command == "ls") {
			fs.list();
		}

		else if (command == "ls<") {
			char buff[1024];
			std::cin.ignore();
			std::cin.getline(buff, 1024);
			MyString input = buff;
			fs.list(buff);
		}

		else if (command == "pwd") {
			fs.printDirectoryPath();
		}

		else if (command == "mkdir") {
			char buff[1024];
			std::cin.ignore();
			std::cin.getline(buff, 1024);
			MyString input = buff;
			fs.makeDirectory(buff);
		}

		else if (command == "rmdir") {
			char buff[1024];
			std::cin.ignore();
			std::cin.getline(buff, 1024);
			MyString input = buff;
			fs.removeDirectory(buff);
		}

		else if (command == "mkdir") {
			char buff[1024];
			std::cin.ignore();
			std::cin.getline(buff, 1024);
			MyString input = buff;
			fs.makeDirectory(buff);
		}


		else if (command == "touch") {
			char buff[1024];
			std::cin.ignore();
			std::cin.getline(buff, 1024);
			MyString input = buff;
			fs.createFile(buff);
		}

		else if (command == "rm") {
			char buff[1024];
			std::cin.ignore();
			std::cin.getline(buff, 1024);
			MyString input = buff;
			fs.removeFile(buff);
		}

		else if (command == "echo") {
			char buff[1024];
			std::cin.ignore();
			std::cin.getline(buff, 1024);
			MyString input = buff;
			fs.print(input);
		}
	}
}