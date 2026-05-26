#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

#include <iostream>

class Time
{
private:
    int hour;
    int minute;

public:

    Time();
    Time(int h, int m);
    int getHour() const;
    int getMinute() const;
    void setHour(int h);
    void setMinute(int m);

    bool operator<(const Time& other) const;
    bool operator>(const Time& other) const;
    bool operator==(const Time& other) const;
};

#endif // TIME_H_INCLUDED
