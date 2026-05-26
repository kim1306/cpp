#include "time.h"


Time::Time() : hour(0), minute(0) {}
Time::Time(int h, int m) : hour(h), minute(m) {}

int Time::getHour() const { return hour; }
int Time::getMinute() const { return minute; }
void Time::setHour(int h) { hour = h; }
void Time::setMinute(int m) { minute = m; }

bool Time::operator<(const Time& other) const
{
    if (hour != other.hour) return hour < other.hour;
    return minute < other.minute;
}

bool Time::operator>(const Time& other) const
{
    if (hour != other.hour) return hour > other.hour;
    return minute > other.minute;
}

bool Time::operator==(const Time& other) const
{
    return hour == other.hour && minute == other.minute;
}
