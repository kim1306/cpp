/**
 * @file regi.cpp
 * @brief Implementation of the Registration class.
 * @author Doheon
 * @date 2026-03-19
 */
#include "regi.h"
unsigned Registration::GetCredits() const
{
    unsigned sum = 0;
    for( unsigned i = 0; i < count; i++ )
        sum += result[i].GetUnit().GetCredits();
    return sum;
}

istream & operator >>( istream & input, Registration & R )
{
    input >> R.studentId >> R.semester >> R.count;
    for( unsigned i = 0; i < R.count; i++ )
        input >> R.result[i];
    return input;
}

ostream & operator <<( ostream & output, const Registration & R )
{
    output << "Student ID: " << R.studentId << '\n'
           << "Semester:   " << R.semester  << '\n';
    for( unsigned i = 0; i < R.count; i++ )
        output << R.result[i] << '\n';
    return output;
}
