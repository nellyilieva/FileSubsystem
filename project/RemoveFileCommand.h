#pragma once
#include "Command.h"

class RemoveFileCommand : public Command {
private:
	MyString path;

public:
	RemoveFileCommand(const MyString& path);

	RemoveFileCommand(const RemoveFileCommand& other) = delete;
	RemoveFileCommand& operator=(const RemoveFileCommand& other) = delete;

	void execute(FileSubsystem* fs) override;
};