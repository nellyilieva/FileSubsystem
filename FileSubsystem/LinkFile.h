#pragma once
#include <iostream>
#include "File.h"

class LinkFile : public File {
public:
    LinkFile(const MyString& name, Directory* parent, const MyString& targetPath);
    void executeFile() const override;

private:
    MyString targetPath;
};