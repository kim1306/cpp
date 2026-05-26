#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <iostream>

class date
{
public:
    date();
    date(int d, int m, int y);

    void setDay(int d);
    void setMonth(int m);
    void setYear(int y);

    int getDay() const;
    int getMonth() const;
    int getYear() const;

    bool operator<(const date& other) const;
    bool operator>(const date& other) const;
    bool operator==(const date& other) const;

private:
    int day;
    int month;
    int year;
};


#endif // DATE_H_INCLUDED
