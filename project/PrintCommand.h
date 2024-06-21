#pragma once
#include "Command.h"

class PrintCommand : public Command {
private:
	MyString str;
public:
	PrintCommand(const MyString& str);

	PrintCommand(const PrintCommand& other) = delete;
	PrintCommand& operator=(const PrintCommand& other) = delete;

	void execute(FileSubsystem* fs) override;
};
