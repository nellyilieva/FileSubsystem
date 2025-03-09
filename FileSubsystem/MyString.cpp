#include "MyString.h"
#include <cstring>
#include <algorithm>
#pragma warning (disable : 4996)


static unsigned roundToPowerOfTwo(unsigned v)
{
    v--;
    v |= v >> 1;
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;
    v++;
    return v;
}

static unsigned dataToAllocByStringLen(unsigned stringLength)
{
    return std::max(roundToPowerOfTwo(stringLength + 1), 16u);
}

MyString::MyString() : MyString("") {}

MyString::MyString(const char* data)
{
    _size = std::strlen(data);
    _allocatedDataSize = dataToAllocByStringLen(_size);
    _data = new char[_allocatedDataSize];
    std::strcpy(_data, data);
}

MyString::MyString(size_t stringLength)
{
    _allocatedDataSize = dataToAllocByStringLen(stringLength);
    _data = new char[_allocatedDataSize];
    _size = 0;
    _data[0] = '\0';
}

MyString::MyString(const MyString& other)
{
    copyFrom(other);
}
MyString::MyString(MyString&& other) noexcept
{
    moveFrom(std::move(other));
}


void MyString::moveFrom(MyString&& other)
{
    _data = other._data;
    other._data = nullptr;

    _size = other._size;
    other._size = 0;

    _allocatedDataSize = other._allocatedDataSize;
    other._allocatedDataSize = 0;
}


MyString& MyString::operator=(const MyString& other)
{
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

MyString& MyString::operator=(MyString&& other) noexcept
{
    if (this != &other)
    {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}


MyString::~MyString()
{
    free();
}

MyString MyString::substr(size_t start, size_t length) const {
    if (start >= _size) {
        return MyString();
    }

    length = std::min(length, _size - start);

    MyString str(length);

    for (size_t i = 0; i < length; i++) {
        str._data[i] = _data[start + i];
    }

    str._data[length] = '\0';
    str._size = length;

    return str;
}

bool MyString::isSubstr(const MyString& subString) {
    if (subString.getSize() > _size) {
        return false;
    }
    if (subString.getSize() == _size && subString == *this) {
        return true;
    }
    for (int i = 0; i < _size - subString.getSize(); i++) {
        MyString current = substr(i, i + subString.getSize());
        if (current == subString) {
            return true;
        }
    }
    return false;
}

size_t MyString::getCapacity() const
{
    return _allocatedDataSize - 1;
}

size_t MyString::getSize() const
{
    return _size;
}

const char* MyString::c_str() const
{
    return _data;
}

MyString& MyString::operator+=(const MyString& other)
{
    if (getSize() + other.getSize() + 1 > _allocatedDataSize)
        resize(dataToAllocByStringLen(getSize() + other.getSize()));

    // we need to use strncat instead of strcat, because strcat will not work for str += str 
    // (the terminating zero of str will be destroyed by the first char)
    std::strncat(_data, other._data, other.getSize());

    _size = getSize() + other.getSize();
    return *this;
}

MyString& MyString::operator+=(char ch)
{
    if (getSize() + 1 + 1 > _allocatedDataSize)
        resize(dataToAllocByStringLen(getSize() + 1));

    // we need to use strncat instead of strcat, because strcat will not work for str += str 
    // (the terminating zero of str will be destroyed by the first char)
    std::strncat(_data, &ch, 1);

    _size = getSize() + 1;
    return *this;
}

char& MyString::operator[](size_t index)
{
    return _data[index]; // no security check!!
}

const char& MyString::operator[](size_t index) const
{
    return _data[index]; // no security check!!
}

std::ostream& operator<<(std::ostream& os, const MyString& obj)
{
    return os << obj._data;
}

std::istream& operator>>(std::istream& is, MyString& ref)
{
    char buff[1024];
    is >> buff;
    size_t buffStringSize = std::strlen(buff);

    if (buffStringSize > ref.getCapacity())
        ref.resize(dataToAllocByStringLen(buffStringSize));

    strcpy(ref._data, buff);
    ref._size = buffStringSize;
    return is;
}

void MyString::resize(unsigned newAllocatedDataSize)
{
    char* newData = new char[newAllocatedDataSize + 1];
    std::strcpy(newData, _data);
    delete[] _data;
    _data = newData;
    _allocatedDataSize = newAllocatedDataSize;
}

void MyString::free()
{
    delete[] _data;
}

void MyString::copyFrom(const MyString& other)
{
    _allocatedDataSize = other._allocatedDataSize;
    _data = new char[_allocatedDataSize];
    std::strcpy(_data, other._data);
    _size = other._size;
}

MyString operator+(const MyString& lhs, const MyString& rhs)
{
    MyString result(lhs.getSize() + rhs.getSize());
    result += lhs;
    result += rhs;
    return result;
}

MyString MyString::substr(size_t start, size_t length) const {
    if (start >= _size) {
        return MyString();
    }

    length = std::min(length, _size - start);

    MyString result(length);
    for (size_t i = 0; i < length; i++) {
        result._data[i] = _data[start + i];
    }

    result._data[length] = '\0';
    result._size = length;

    return result;
}

bool MyString::isSubstr(const MyString& subString) const {
    if (subString._size > _size) {
        return false;
    }

    for (size_t i = 0; i <= _size - subString._size; i++) {
        bool match = true;
        for (size_t j = 0; j < subString._size; j++) {
            if (_data[i + j] != subString._data[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            return true;
        }
    }

    return false;
}

size_t MyString::find(const MyString& str, size_t pos) const {
    if (str._size > _size || pos > _size - str._size) {
        return MyString::npos;
    }

    for (size_t i = pos; i <= _size - str._size; i++) {
        bool match = true;
        for (size_t j = 0; j < str._size; j++) {
            if (_data[i + j] != str._data[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            return i;
        }
    }

    return MyString::npos;
}

MyString MyString::trim() const {
    size_t start = 0;
    while (start < _size && std::isspace(_data[start])) {
        start++;
    }

    size_t end = _size;
    while (end > start && std::isspace(_data[end - 1])) {
        end--;
    }

    return substr(start, end - start);
}

bool MyString::isEmpty() const {
    return _size == 0;
}

bool operator==(const MyString& lhs, const MyString& rhs)
{
    return std::strcmp(lhs.c_str(), rhs.c_str()) == 0;
}

bool operator!=(const MyString& lhs, const MyString& rhs)
{
    return std::strcmp(lhs.c_str(), rhs.c_str()) != 0;
}

bool operator<(const MyString& lhs, const MyString& rhs)
{
    return std::strcmp(lhs.c_str(), rhs.c_str()) < 0;
}

bool operator<=(const MyString& lhs, const MyString& rhs)
{
    return std::strcmp(lhs.c_str(), rhs.c_str()) <= 0;
}

bool operator>(const MyString& lhs, const MyString& rhs)
{
    return std::strcmp(lhs.c_str(), rhs.c_str()) > 0;
}

bool operator>=(const MyString& lhs, const MyString& rhs)
{
    return std::strcmp(lhs.c_str(), rhs.c_str()) >= 0;
}