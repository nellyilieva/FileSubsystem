#include "Time.h"

MyString Time::getCurrentTime() {

    //get current local time
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);

    int month = now->tm_mon + 1;
    int day = now->tm_mday;
    int hour = now->tm_hour;
    int minute = now->tm_min;

    MyString time;

    time += numberToMonth(month);
    time += " ";

    if (day < 10) time += '0';
    time += MyString(intToStr(day).c_str());
    time += " ";

    if (hour < 10) time += '0';
    time += MyString(intToStr(hour).c_str());
    time += ":";

    if (minute < 10) time += '0';
    time += MyString(intToStr(minute).c_str());

    return time;
}