#pragma once
#include "Command.h"

class RewriteCommand : public Command {
private:
	MyString str;
	MyString name;
public:
	RewriteCommand(const MyString& str, const MyString& name);

	RewriteCommand(const RewriteCommand& other) = delete;
	RewriteCommand& operator=(const RewriteCommand& other) = delete;

	void execute(FileSubsystem* fs) override;
};
