/**
 * @file unit.cpp
 * @brief Implementation of the Unit class.
 * @author Doheon
 * @date 2026-03-19
 */
#include "unit.h"
#include <cstring>

Unit::Unit()
{
    unitName[0] = '\0';
    section     = '\0';
    credits     = 0;
}

Unit::Unit( const char* nam, char sect, unsigned cred )
{
    // strncpy copies at most UnitNameSize-1 characters, then force null'\0'
    // so unitName is always a valid C-string regardless of input.
    strncpy( unitName, nam, UnitNameSize - 1 );
    unitName[UnitNameSize - 1] = '\0';

    section = sect;
    credits = cred;
}

istream & operator >>( istream & input, Unit & U )
{
    input >> U.unitName >> U.section >> U.credits;
    return input;
}

ostream & operator <<( ostream & output, const Unit & U )
{
    output << "  Unit:    " << U.unitName  << '\n'
       << "  Section: " << U.section  << '\n'
       << "  Credits: " << U.credits  << '\n';
    return output;
}
