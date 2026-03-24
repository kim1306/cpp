/**
 * @file result.cpp
 * @brief Implementation of the Result class.
 * @author Doheon
 * @date 2026-03-24
 */
#include "result.h"

istream & operator >>( istream & input, Result & res )
{
 input >> res.unit >> res.date >> res.mark;
    return input;
}

ostream & operator <<( ostream & output, const Result & res )
{
   output << res.unit
           << "  Date:    " << res.date << '\n'
           << "  Mark:    " << res.mark << '\n';
    return output;
}
