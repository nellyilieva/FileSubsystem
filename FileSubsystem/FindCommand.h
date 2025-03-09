#pragma once
#include "Command.h"

class FindCommand : public Command {
private:
	MyString path;
	MyString str;
public:
	FindCommand(const MyString& path, const MyString& str);

	FindCommand(const FindCommand& other) = delete;
	FindCommand& operator=(const FindCommand& other) = delete;

	void execute(FileSubsystem* fs) override;
};
