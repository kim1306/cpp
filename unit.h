/**
 * @file unit.h
 * @brief Unit class definition for Murdoch University Student Registration.
 * @author Doheon
 * @date 2026-03-19
 */
#ifndef UNIT_H
#define UNIT_H
#include <iostream>
#include <string>

using namespace std;


/**
 * @class Unit
 * @brief Represents a single unit, including name, section, and credit points.
 */
class Unit {
private:
    string   unitName;
    char     section;
    int      credits;

public:
    /**
     * @brief Default constructor. Initialises all fields to empty/zero.
     */
    Unit();

    /**
     * @brief Parameterized constructor.
     * @param nam   The unit code/name as a std::string (e.g. "ICT283").
     * @param sect  The section identifier character.
     * @param cred  The number of credit points.
     */
    Unit( const string & nam, char sect, unsigned cred );
//const char* for the name is essentially saying:
//give me the address of the first character, and I'll read along until I hit the null terminator \0

     /**
     * @brief Gets the unit name/code.
     * @return const char* pointer to the unit name string.
     */
    const string& GetUnitName() const;

    /**
     * @brief Sets the unit name/code.
     * @param nam The new unit name as a std::string (e.g. "ICT283").
     *            Truncated silently if longer than UnitNameSize - 1.
     */
    void SetUnitName( const string& nam );

    /**
     * @brief Gets the section identifier.
     * @return char The section character.
     */
    char GetSection() const;

    /**
     * @brief Sets the section identifier.
     * @param sect The new section character.
     */
    void SetSection( char sect );


    /**
     * @brief Gets the number of credits for this unit.
     * @return unsigned number of credits.
     */
    unsigned GetCredits() const;

    /**
     * @brief Sets the number of credits for this unit.
     * @param cred The new credit value.
     */
    void SetCredits( unsigned cred );

    // Overloaded stream operators for file I/O
    friend ostream & operator <<( ostream & os,    const Unit & U );
    friend istream & operator >>( istream & input,       Unit & U );
    //The friend keyword here means:
    //"this function is not a member of the class, but it's allowed to access the class's private members directly."

};

//why Inline implementations in header?
//For tiny functions like a simple getter/setter, this avoids the overhead of a function call — which matters in performance-sensitive code.
// The compiler needs to see the function's full body at the point where it's called
//If the body is hidden away in a .cpp file, the compiler can't do that when compiling a different .cpp file that uses Unit
inline Unit::Unit()
: unitName(""), section('\0'), credits(0){}
inline Unit::Unit(const string &nam, char sect, unsigned cred)
: unitName(nam), section(sect), credits((int)cred){}

inline const string& Unit::GetUnitName() const
{
    return unitName;
}
inline void Unit::SetUnitName( const string& nam )
{
unitName=nam;
}


inline char Unit::GetSection() const
{
    return section;
}
inline void Unit::SetSection( char sect )
{
    section = sect;
}


inline unsigned Unit::GetCredits() const
{
    return (unsigned)credits;
}

inline void Unit::SetCredits( unsigned cred )
{
    credits = (int)cred;
}

#endif // UNIT_H
