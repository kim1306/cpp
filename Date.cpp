/**
 * @file date.cpp
 * @brief Implementation of the Date class.
 * @author Doheon
 * @date 2026-03-24
 */
#include "date.h"
#include <iomanip>   // setw, setfill for zero-padded output (e.g. 06 not 6)

// Returns the number of days in a given month.
// February is always 28 and 31 for other months
unsigned Date::DaysInMonth( unsigned m)
{
    switch( m )
    {
        case 1:  return 31;  // January
        case 2:  return 28;  // February
        case 3:  return 31;  // March
        case 4:  return 31;  // April
        case 5:  return 31;  // May
        case 6:  return 31;  // June
        case 7:  return 31;  // July
        case 8:  return 31;  // August
        case 9:  return 31;  // September
        case 10: return 31;  // October
        case 11: return 31;  // November
        case 12: return 31;  // December
        default: return 0;   // invalid month
    }
}

// Default: set to the sentinel date 1/1/1900
Date::Date() : day(1), month(1), year(1900)
{}

// Parameterized: validate all three fields before storing.
// If anything is invalid, the field falls back to its default value.
Date::Date( unsigned d, unsigned m, unsigned y )
    : day(1), month(1), year(1900)
{
    SetYear(y);
    SetMonth(m);
    SetDay(d);
}

// Day must be >= 1 and <= the number of days in the current month.
void Date::SetDay( unsigned d )
{
    if( d >= 1 && d <= DaysInMonth(month) )
        day = d;
    // else: leave unchanged
}

// Month must be 1-12.
void Date::SetMonth( unsigned m )
{
    if( m >= 1 && m <= 12 )
        month = m;
    // else: leave unchanged
}

// Year must be in a reasonable range
void Date::SetYear( unsigned y )
{
    if( y >= 1900 && y <= 2200 )
        year = y;
    // else: leave unchanged
}

// Returns true only when day, month, and year all form a real calendar date.
bool Date::IsValid() const
{
    if( month < 1 || month > 12 )                     return false;
    if( year  < 1900 )                                return false;
    if( day   < 1 || day > DaysInMonth(month)) return false;
    return true;
}

// Reads three unsigned integers: day month year
// e.g.  15 06 2024
istream & operator >>( istream & input, Date & D )
{
    unsigned d, m, y;
    input >> d >> m >> y;
    D.SetYear(y);
    D.SetMonth(m);
    D.SetDay(d);
    return input;
}

// Writes date as DD/MM/YYYY with zero-padded day and month.
// e.g.  05/06/2024
ostream & operator <<( ostream & output, const Date & D )
{
    output << setfill('0')
           << setw(2) << D.day   << '/'
           << setw(2) << D.month << '/'
           << setw(4) << D.year;
    return output;
}
