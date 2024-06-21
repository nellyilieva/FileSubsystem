#pragma once
#include "Command.h"

class CreateFileCommand : public Command {
private:
	MyString name;

public:
	CreateFileCommand(const MyString& name);

	CreateFileCommand(const CreateFileCommand& other) = delete;
	CreateFileCommand& operator=(const CreateFileCommand& other) = delete;

	void execute(FileSubsystem* fs) override;
};