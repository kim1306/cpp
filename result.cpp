/**
 * @file result.cpp
 * @brief Implementation of the Result class.
 * @author [Your Name]
 * @date 2026-03-19
 */
#include "result.h"
Result::Result() : mark( 0.0f )
{
}

Result::Result( const Unit & u, float m ) : unit( u ), mark( m )
{//a member initializer list. The :
//The initializer list version constructs unit directly with the value of u in one step, which is more efficient.
}

istream & operator >>( istream & input, Result & res )
{
    //unit is declared as a Unit object inside Result
    input >> res.unit >> res.mark;   // reads unit fields by calling operator>>(istream&, const Unit&)
    return input;
}

ostream & operator <<( ostream & output, const Result & res )
{
    output << res.unit                          // calls operator<<(ostream&, const Unit&)
       << "  Mark:    " << res.mark << '\n';
    return output;
}
