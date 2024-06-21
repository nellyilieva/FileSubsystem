#pragma once
#include "Command.h"

class AbsolutePathCommand : public Command {
public:
	AbsolutePathCommand() = default;

	AbsolutePathCommand(const AbsolutePathCommand& other) = delete;
	AbsolutePathCommand& operator=(const AbsolutePathCommand& other) = delete;

	void execute(FileSubsystem* fs) override;
};