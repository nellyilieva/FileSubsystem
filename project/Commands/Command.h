#pragma once
#include "FileSubsystem.h"

class Command {
public:
	virtual ~Command() = default;
	void virtual execute(FileSubsystem* fs) = 0;
};