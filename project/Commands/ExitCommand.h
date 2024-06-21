#pragma once
#include "Command.h"


class ExitCommand : public Command {
public:
	ExitCommand() = default;

	void execute(FileSubsystem* fs) override;
};