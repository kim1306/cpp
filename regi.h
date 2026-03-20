/**
 * @file regi.h
 * @brief Registration class definition for Murdoch University Student Registration.
 * @author Doheon
 * @date 2026-03-19
 */
#ifndef REGI_H
#define REGI_H
#include "unit.h"
#include <iostream>
using namespace std;

/**
 * @brief Constant for the maximum number of units a student can take.
 */

/**
 * @class Registration
 * @brief Manages a student's enrollment, including ID, semester, and a list of Units.
 */
class Registration {
public:
    /**
     * @brief Default constructor. Initialises studentId, semester, and count to zero.
     */
    Registration();

    /**
     * @brief Calculates total credits from all enrolled units.
     * @return unsigned total credits.
     */
    unsigned GetCredits() const;

    /**
     * @brief Returns the number of units currently in the registration.
     * @return unsigned unit count.
     */
    unsigned GetCount() const;


    friend ostream & operator <<( ostream & os,    const Registration & R );
    friend istream & operator >>( istream & input,       Registration & R );

private:
    long     studentId;
    unsigned semester;
    unsigned count;
    Unit     units[10]; //when you declare Unit units[10] as a class member like this,
                        //the Unit objects are created automatically when a Registration object is created — no new or separate construction needed.
};

inline unsigned Registration::GetCount() const
{
    return count;
}

#endif // REGI_H
