/**
 * @file main.cpp
 * @brief Student Registration System - Main Entry Point.
 * @author Doheon
 * @date 2026-03-19
 *
 */
#include "unit.h"
#include "regi.h"
#include "result.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream infile( "rinput.txt" );
    if( !infile ) return -1;

    Registration R;

    infile >> R;   //cpmputer looks for an operator>> that takes an istream&
                   //and a Registration& — and calls it.

    ofstream ofile( "routput.txt" );

    ofile << R     // calls operator<<(ostream&, const Registration&)
        << "Number of units  = " << R.GetCount()   << '\n'
        << "Total credits    = " << R.GetCredits() << '\n';

    return 0;
}
