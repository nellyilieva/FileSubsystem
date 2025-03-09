#pragma once
#include "Command.h"

class ListDirectoryCommand : public Command {
private:
	MyString path;

public:
	ListDirectoryCommand(const MyString& path);

	ListDirectoryCommand(const ListDirectoryCommand& other) = delete;
	ListDirectoryCommand& operator=(const ListDirectoryCommand& other) = delete;

	void execute(FileSubsystem* fs) override;
};