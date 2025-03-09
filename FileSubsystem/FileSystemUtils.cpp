#include "FileSystemUtils.h"

void FileSystemUtils::saveFileSystem(const Directory* root, const MyString& filename) {
    MyString serializedData = root->serialize();

    std::ofstream outFile(filename.c_str(), std::ios::binary);
    if (!outFile) {
        throw std::runtime_error("Failed to open file for writing");
    }

    outFile.write(serializedData.c_str(), serializedData.getSize());
    outFile.close();
}

Directory* FileSystemUtils::loadFileSystem(const MyString& filename) {
    std::ifstream inFile(filename.c_str(), std::ios::binary);
    if (!inFile) {
        throw std::runtime_error("Failed to open file for reading");
    }

    inFile.seekg(0, std::ios::end);
    size_t fileSize = inFile.tellg();
    inFile.seekg(0, std::ios::beg);

    char* buffer = new char[fileSize + 1];
    inFile.read(buffer, fileSize);
    buffer[fileSize] = '\0';

    MyString serializedData(buffer);
    delete[] buffer;

    return Directory::deserialize(serializedData);
}