#include "date.h"

date::date() : day(21), month(10), year(2000) {}

date::date(int d, int m, int y) : day(d), month(m), year(y) {}

void date::setDay(int d)   { day = d; }
void date::setMonth(int m) { month = m; }
void date::setYear(int y)  { year = y; }

int date::getDay() const   { return day; }
int date::getMonth() const { return month; }
int date::getYear() const  { return year; }

bool date::operator<(const date& other) const {
    if (year != other.year) return year < other.year;
    if (month != other.month) return month < other.month;
    return day < other.day;
}

bool date::operator>(const date& other) const {
    if (year != other.year) return year > other.year;
    if (month != other.month) return month > other.month;
    return day > other.day;
}

bool date::operator==(const date& other) const {
    return (year == other.year && month == other.month && day == other.day);
}


