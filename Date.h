/**
 * @file date.h
 * @brief Date class definition for Murdoch University Student Registration.
 * @author Doheon
 * @date 2026-03-24
 *
 * @details
 * Date stores a calendar date as three separate fields: day, month, year.
 * It is used by Result to record when a unit mark was obtained.
 * All three fields are validated on set — invalid values are rejected
 * and the field is left unchanged.
 */
#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
using namespace std;

/**
 * @class Date
 * @brief Represents a calendar date as day, month, and year.
 *
 * @details
 * Stores dates in the range 1/1/1900 to 31/12/9999.
 * Month and day are validated against legal ranges.
 * Leap year is accounted for in February day validation.
 *
 * Input format  (operator>>): DD MM YYYY   e.g.  15 06 2024
 * Output format (operator<<): DD/MM/YYYY   e.g.  15/06/2024
 */
class Date {
public:
    /**
     * @brief Default constructor.
     *        Initialises date to 1/1/1900.
     */
    Date();

    /**
     * @brief Parameterized constructor.
     * @param d  Day of the month (1–31).
     * @param m  Month (1–12).
     * @param y  Year (1900–9999).
     * @note    Invalid values are silently replaced with the default (1/1/1900).
     */
    Date( unsigned d, unsigned m, unsigned y );



    /**
     * @brief Gets the day of the month.
     * @return unsigned day (1–31).
     */
    unsigned GetDay()   const;

    /**
     * @brief Gets the month.
     * @return unsigned month (1–12).
     */
    unsigned GetMonth() const;

    /**
     * @brief Gets the year.
     * @return unsigned year.
     */
    unsigned GetYear()  const;


    /**
     * @brief Sets the day of the month.
     * @param d New day value (1–31, must be valid for current month/year).
     *          Rejected silently if out of range.
     */
    void SetDay  ( unsigned d );

    /**
     * @brief Sets the month.
     * @param m New month value (1–12).
     *          Rejected silently if out of range.
     */
    void SetMonth( unsigned m );

    /**
     * @brief Sets the year.
     * @param y New year value (1900–9999).
     *          Rejected silently if out of range.
     */
    void SetYear ( unsigned y );


    /**
     * @brief Checks whether the current day/month/year combination is valid.
     * @return true if the date is a real calendar date, false otherwise.
     */
    bool IsValid() const;

    /**
     * @brief Reads a date from a stream in DD MM YYYY format.
     * @param input Input stream.
     * @param D     Date object to populate.
     * @return istream& for chaining.
     */
    friend istream & operator >>( istream & input,       Date & D );

    /**
     * @brief Writes a date to a stream in DD/MM/YYYY format.
     * @param output Output stream.
     * @param D      Date object to print.
     * @return ostream& for chaining.
     */
    friend ostream & operator <<( ostream & output, const Date & D );

private:
    unsigned day;
    unsigned month;
    unsigned year;

    /**
     * @brief Returns the number of days in a given month.
     * @param m Month (1–12).
     * @return unsigned days in that month.
     */
    static unsigned DaysInMonth( unsigned m);

};


inline unsigned Date::GetDay()   const { return day;   }
inline unsigned Date::GetMonth() const { return month; }
inline unsigned Date::GetYear()  const { return year;  }

#endif // DATE_H
