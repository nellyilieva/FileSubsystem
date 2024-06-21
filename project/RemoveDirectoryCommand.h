#pragma once
#include "Command.h"

class RemoveDirectoryCommand : public Command {
private:
	MyString path;

public:
	RemoveDirectoryCommand(const MyString& path);

	RemoveDirectoryCommand(const RemoveDirectoryCommand& other) = delete;
	RemoveDirectoryCommand& operator=(const RemoveDirectoryCommand& other) = delete;

	void execute(FileSubsystem* fs) override;
};