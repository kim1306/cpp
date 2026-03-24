/**
 * @file unit.cpp
 * @brief Implementation of the Unit class.
 * @author Doheon
 * @date 2026-03-19
 */
/**
 * KEY CHANGE from C-string version:
 *   operator>> previously did:  input >> U.unitName  (char array — risk of overflow)
 *   Now it does:                input >> U.unitName  (std::string — safe, any length)
 *   The code looks identical but std::string's operator>> handles memory automatically.
 */
#include "unit.h"

istream & operator >>( istream & input, Unit & U )
{
    // std::string >> reads one whitespace-delimited token.
    // No buffer size, no strncpy, no null terminator needed.
    input >> U.unitName >> U.section >> U.credits;
    return input;
}

ostream & operator <<( ostream & output, const Unit & U )
{
    output << "  Unit:    " << U.unitName << '\n'
           << "  Section: " << U.section  << '\n'
           << "  Credits: " << U.credits  << '\n';
    return output;
}
