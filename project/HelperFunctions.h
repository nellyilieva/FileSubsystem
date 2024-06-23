#pragma once
#include <ctime>
#include <iostream>
#include "MyString.h"
#include "Vector.hpp"

MyString numberToMonth(int n);
MyString intToStr(int num);
Vector<MyString> splitPath(const MyString& path);