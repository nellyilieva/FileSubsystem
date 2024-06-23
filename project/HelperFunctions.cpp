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