#include <iostream>
#include <fstream>
#include <string>
#include "ex1.h"
using namespace std;

/**
 * @file main.cpp
 * @brief main program of the coin change management
 *
 * this program reads currency records from a text file, allows
 * users to search for a customer's change breakdown, and exports
 * results to a CSV file upon exit.
 */



int main() {
    readfile();
    console();
    return 0;
}
/**
 * @brief main function of the program.
 *
 * calls readfile() to load data from coins.txt,
 * then launches the console() interface.
 *
 * @return int returns 0 when the program finishes successfully.
 */
