#pragma once
#include "Directory.h"
#include <fstream>
#include <iostream>

class FileSystemUtils {
public:
    static void saveFileSystem(const Directory* root, const MyString& filename);
    static Directory* loadFileSystem(const MyString& filename);
};