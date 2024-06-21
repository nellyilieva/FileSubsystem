#pragma once
#include "Command.h"

class MakeDirectoryCommand : public Command {
private:
	MyString name;

public:
	MakeDirectoryCommand(const MyString& path);

	MakeDirectoryCommand(const MakeDirectoryCommand& other) = delete;
	MakeDirectoryCommand& operator=(const MakeDirectoryCommand& other) = delete;

	void execute(FileSubsystem* fs) override;
};