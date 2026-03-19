#ifndef EX1_H_INCLUDED
#define EX1_H_INCLUDED

#include <iostream>
#include <fstream>
#include <cstring> // for cstring functions
using namespace std;

/**
 * @file ex1.h
 * @brief header file containing structures, global variables, and function prototypes.
 */

//extern tells the compiler that the variable is in somewhere else ( only just declaring it in here)
extern int US[4];
extern int AU[4];
extern int EU[4];

extern int globalCounts[4];

struct account { // str -> char arrays to use cstring function
    char name[100];
    int amount;
    char currency[10];
};

extern account records[100];
extern int recordCount;

void calculate(int amount, char* currency);
/**
 * @brief calculates the optimal coin change for a given amount for the selected currency type
 *
 * optimal coin change will be temporarily stored in globalCounts variablle
 *
 * @param amount = amount of money in cents.
 * @param currency = currency type.
 */

void CSVfile();
/**
 * @brief it writes all records to a CSV file.
 *
 * output file: records.csv
 */

void searchname();
/**
 * @brief searches for a customer record by name and displays their change.
 */

void updateRecord(char* name, int amount, char* currency);
/**
 * @brief updates or inserts a data set in the records list.
 *
 * If the same customer and currency already exist, the amount is added.
 *
 * @param name = customer name
 * @param amount = amount in cents
 * @param currency =currency type
 */

void Extraction(char* line);
/**
 * @brief extracts only necessary data from a line in the input file.
 *
 *
 * @param line =a line from the input file
 */

void readfile();
/**
 * @brief reads data from "coins.txt." line by line
 */

void console();

/**
 * @brief it provides a console menu for user interaction.
 */


#endif // EX1_H_INCLUDED
