#include "HelperFunctions.h"

MyString numberToMonth(int n) {
    switch (n) {
    case 1:
        return "January";
    case 2:
        return "February";
    case 3:
        return "March";
    case 4:
        return "April";
    case 5:
        return "May";
    case 6:
        return "June";
    case 7:
        return "July";
    case 8:
        return "August";
    case 9:
        return "September";
    case 10:
        return "October";
    case 11:
        return "November";
    case 12:
        return "December";
    }
}

MyString intToStr(int num) {
    if (num == 0) {
        return "0";
    }

    MyString result;

    while (num > 0) {
        char digit = '0' + (num % 10);
        result += digit;
        num /= 10;
    }

    return result;
}

Vector<MyString> splitPath(const MyString& path) {
    Vector<MyString> elements;
    MyString separator("/");

    int start = 0;
    int length = path.getSize();
    int sepPos = 0;

    while (sepPos < length) {
        while (sepPos < length && path[sepPos] != '/') {
            sepPos++;
        }

        if (sepPos > start) {
            elements.pushBack(path.substr(start, sepPos - start));
        }

        start = sepPos + 1;
        sepPos++;
    }

    if (start < length) {
        elements.pushBack(path.substr(start,length));
    }

    return elements;
}

Vector<MyString> MyString::split(char delimiter) const {
    Vector<MyString> result;
    size_t start = 0;
    size_t end = find(delimiter);

    while (end != MyString::npos) {
        result.pushBack(substr(start, end - start));
        start = end + 1;
        end = find(delimiter, start);
    }

    result.pushBack(substr(start, end));
    return result;
}