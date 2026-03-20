/**
 * @file regi.cpp
 * @brief Implementation of the Registration class.
 * @author Doheon
 * @date 2026-03-19
 */
#include "regi.h"

Registration::Registration()
{
    studentId = 0;
    semester  = 0;
    count     = 0;
}

unsigned Registration::GetCredits() const
{
    unsigned sum = 0;
    for( unsigned i = 0; i < count; i++ )
        sum += result[i].GetUnit().GetCredits();  // Result -> Unit -> credits
    return sum;
}

//not a member function
istream & operator >>( istream & input, Registration & R )
//input — the name you gave it (a var)
//infile is the actual stream object from main(). The parameter input becomes a reference to it
//so when the function body does input >> R.studentId, it's really reading from infile.
//Same goes for R — it's just the parameter name for whatever Registration object was passed in on the right side of >>
{
    input >> R.studentId;
    input >> R.semester;
    input >> R.count;
    for( unsigned i = 0; i < R.count; i++ )
        input >> R.result[i];   // calls operator>>(istream&, Result&
        //results[0] → { unit: {ICT001, D, 3},  mark: 72.5 }
    return input;
}

ostream & operator <<( ostream & output, const Registration & R )
{
    output << "Student ID: " << R.studentId << '\n'
       << "Semester:   " << R.semester  << '\n';
    for( unsigned i = 0; i < R.count; i++ )
        output << R.result[i] << '\n';   // calls operator<<(ostream&, constResult&)
    return output;
}
