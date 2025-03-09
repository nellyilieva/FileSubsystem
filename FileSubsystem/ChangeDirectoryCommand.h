#pragma once
#include "Command.h"

class ChangeDirectoryCommand : public Command {
private:
	MyString path;

public:
	ChangeDirectoryCommand(const MyString& path);

	ChangeDirectoryCommand(const ChangeDirectoryCommand& other) = delete;
	ChangeDirectoryCommand& operator=(const ChangeDirectoryCommand& other) = delete;

	void execute(FileSubsystem* fs) override;
};