#pragma once
#include "Command.h"

class PerformFileCommand : public Command {
private:
	MyString path;

public:
	PerformFileCommand(const MyString& path);

	PerformFileCommand(const PerformFileCommand& other) = delete;
	PerformFileCommand& operator=(const PerformFileCommand& other) = delete;

	void execute(FileSubsystem* fs) override;
};