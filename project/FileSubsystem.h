#pragma once
#include <iostream>
#include "Directory.h"

class FileSubsystem {
private:
	Directory* root;
public:
	~FileSubsystem();
};