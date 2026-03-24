/**
 * @file regi.h
 * @brief Registration class definition for Murdoch University Student Registration.
 * @author Doheon
 * @date 2026-03-19
 */
#ifndef REGI_H
#define REGI_H
#include "unit.h"
#include "result.h"
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
     * @brief Gets the student id.
     * @return const long pointer to the student ID.
     */
    long GetstudentId() const;

    /**
     * @brief Sets the student Id.
     * @param id The new student id as id
     */
    void SetstudentId( long id );


             /**
     * @brief Gets the semester.
     * @return const long pointer to the semester.
     */
    unsigned Getsemester() const;

    /**
     * @brief Sets the semester.
     * @param The new semster as sem
     */
    void Setsemester( unsigned sem );



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
    Result result[10];
};

inline Registration::Registration()
    : studentId(0), semester(0), count(0){}

inline long Registration::GetstudentId () const
{
    return studentId;
}
inline void Registration::SetstudentId( long id )
{
    studentId=id;
}

inline unsigned Registration::Getsemester () const
{
    return semester;
}
inline void Registration::Setsemester( unsigned sem )
{
    semester=sem;
}

inline unsigned Registration::GetCount() const
{
    return count;
}

#endif // REGI_H
