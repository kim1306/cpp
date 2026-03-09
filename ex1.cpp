#include "ex1.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/**
 * @file ex1.cpp
 * @brief implementation of coin change calculations and file operations.
 *
 * this file contains the inner works of functions declared in ex1.h.
 */

#include "ex1.h"

int US[4] = {50, 25, 10, 1};
int AU[4] = {50, 20, 10, 5};
int EU[4] = {20, 10, 5, 1};

int globalCounts[4] = {0, 0, 0, 0};

account records[100];
int recordCount = 0;

void calculate(int amount, string currency) {
    int* coinSet = nullptr; //safer way to initialising a pointer variable

    if (currency == "AU$") coinSet = AU;
    else if (currency == "US$") coinSet = US;
    else if (currency == "EUR") coinSet = EU;

    for (int i = 0; i < 4; i++) globalCounts[i] = 0;

    if (coinSet == nullptr) return;

    for (int i = 0; i < 4; i++) {
        globalCounts[i] = amount / coinSet[i];
        amount %= coinSet[i];
    }
}


void CSVfile() {
    ofstream outputFile("records.csv");
    if (!outputFile.is_open()) {
        cerr << "error creating a csv file!" << endl;
        return;
    }

    for (int i = 0; i < recordCount; i++) {
        calculate(records[i].amount, records[i].currency);
        // format: Jane, the change for 55 cents in AU$ is 1,0,0,1
        outputFile << records[i].name << ", the change for " << records[i].amount
                << " cents in " << records[i].currency << " is " << ","
                << globalCounts[0] << "," << globalCounts[1] << ","
                << globalCounts[2] << "," << globalCounts[3] << endl;
    }

    outputFile.close();
}

void searchname() {
    string target;
    cout << "enter name: ";
    cin >> target;

    //view part that need to be deleted later
    bool found = false;
    for (int i = 0; i < recordCount; i++) {
        if (records[i].name == target) {
            found = true;
            cout << "\ncustomer: " << records[i].name << " \n" << records[i].amount
                 << " cents in " << records[i].currency <<endl;

            calculate(records[i].amount, records[i].currency);
            cout << "change: ";
            int* coinSet = nullptr;
            if (records[i].currency == "AU$") coinSet = AU;
            else if (records[i].currency == "US$") coinSet = US;
            else if (records[i].currency == "EUR") coinSet = EU;

            for (int j = 0; j < 4; j++) {
                if (globalCounts[j] > 0) {
                    cout << coinSet[j] << "cents: " << globalCounts[j] << "    ";
                }
            }
            cout << endl;
        }
    }

    if (!found) cout << "no records found" << endl;
}

void updateRecord(string name, int amount, string currency) {
    bool duplicate = false;

    for (int i = 0; i < recordCount; i++) {
        if (records[i].name == name && records[i].currency == currency) {
            records[i].amount += amount;
            duplicate = true;
            break;
        }
    }

    if (!duplicate && recordCount < 100) {
    records[recordCount] = {name, amount, currency};
        recordCount++;
    }
}

void Extraction(string line) {
    if (line.empty()) return; //empty() is used to check if container or string is empty

    string words[10];
    int wordCount = 0;
    string currentWord = "";

    for (char ch : line) {
        if (ch == ' ') {
            if (!currentWord.empty()) {
                words[wordCount] = currentWord;
                wordCount++;
                currentWord = "";

            }
        } else {
            currentWord += ch;
        }
    }
    if (!currentWord.empty()) words[wordCount] = currentWord;//the last token

  //only possible bc i know how data is stored in the txt file
        string name = words[0];
        int amount = stoi(words[1]); //str to int converter
        string currency = words[wordCount];
        updateRecord(name, amount, currency);
}

void readfile() {
    ifstream inputfile("coins.txt");
    if (!inputfile.is_open()) {
        cerr << "Error opening file!" << endl;
        return;
    }

    string line;
    while (getline(inputfile, line)) {
        Extraction(line);
    }
    inputfile.close();
}

void console() {
    int answer;
    while (true) {
        cout << "\n1. Enter Name\n2. Exit" << endl;
        cin >> answer;

        if (answer == 1) {
            searchname();
        } else {
            CSVfile();
            break;
        }
    }
}
