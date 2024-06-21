#pragma once
#include "Command.h"

class AddCommand : public Command {
private:
	MyString str;
	MyString name;
public:
	AddCommand(const MyString& str, const MyString& name);

	AddCommand(const AddCommand& other) = delete;
	AddCommand& operator=(const AddCommand& other) = delete;

	void execute(FileSubsystem* fs) override;
};
