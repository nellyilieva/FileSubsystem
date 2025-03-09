#pragma once
#include "Command.h"


class ExitCommand : public Command {
public:
	ExitCommand() = default;

	ExitCommand(const ExitCommand& other) = delete;
	ExitCommand& operator=(const ExitCommand& other) = delete;

	void execute(FileSubsystem* fs) override;
};