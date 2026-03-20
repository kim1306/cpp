/**
 * @file result.h
 * @brief Result class definition — pairs a Unit with a mark.
 * @author Doheon
 * @date 2026-03-19
 */
#ifndef RESULT_H
#define RESULT_H

#include "unit.h"
#include <iostream>
using namespace std;

/**
 * @class Result
 * @brief Stores one Unit object and the floating-point mark achieved for it.
 *
 * Registration holds an array of Result objects instead of Unit objects.
 * Result accesses Unit data only through Unit's public interface (GetCredits,operator<<, etc.)
 */
class Result {
public:
    /**
     * @brief Default constructor. Initialises mark to 0.
     */
    Result();

    /**
     * @brief Parameterized constructor.
     * @param u    The Unit associated with this result.
     * @param mark The mark achieved (0.0 – 100.0).
     */
    Result( const Unit & u, float mark );

    /**
     * @brief Returns a copy of the Unit stored in this result.
     * @return Unit
     */
    Unit  GetUnit() const;

    /**
     * @brief Returns the mark for this result.
     * @return float
     */
    float GetMark() const;


    /**
     * @brief Replaces the stored Unit.
     * @param u New Unit value.
     */
    void SetUnit( const Unit & u );

    /**
     * @brief Sets the mark for this result.
     * @param mark New mark value.
     */
    void SetMark( float mark );

    friend ostream & operator <<( ostream & output,    const Result & res );
    friend istream & operator >>( istream & input,       Result & res );

private:
    Unit  unit;   // composition: Result owns one Unit
    float mark;
};

inline Unit Result::GetUnit() const
{
    return unit;
}

inline float Result::GetMark() const
{
    return mark;
}

inline void Result::SetUnit( const Unit & u )
{
    unit = u;
}

inline void Result::SetMark( float m )
{
    mark = m;
}

#endif // RESULT_H
