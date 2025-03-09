#pragma once
#include "FileSubsystem.h"

class Command {
public:
    virtual ~Command() = default;
    virtual void execute(FileSubsystem* fs, const MyString& args) = 0;
};