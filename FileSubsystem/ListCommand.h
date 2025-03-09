#pragma once
#include "Command.h"

class ListCommand : public Command {
public:
	ListCommand() = default;

	ListCommand(const ListCommand& other) = delete;
	ListCommand& operator=(const ListCommand& other) = delete;

	void execute(FileSubsystem* fs) override;
};