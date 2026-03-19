#include "ex1.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

int US[4] = {50, 25, 10, 1};
int AU[4] = {50, 20, 10, 5};
int EU[4] = {20, 10, 5, 1};

int globalCounts[4] = {0, 0, 0, 0};

account records[100];
int recordCount = 0;

void calculate(int amount, char* currency) {
    int* coinSet = nullptr;

    if (strcmp(currency, "AU$") == 0) coinSet = AU;
    else if (strcmp(currency, "US$") == 0) coinSet = US;
    else if (strcmp(currency, "EUR") == 0) coinSet = EU;

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
        outputFile << records[i].name << ", the change for " << records[i].amount
                << " cents in " << records[i].currency << " is " << ","
                << globalCounts[0] << "," << globalCounts[1] << ","
                << globalCounts[2] << "," << globalCounts[3] << endl;
    }

    outputFile.close();
}

void searchname() {
    char target[100];
    cout << "enter name: ";
    cin >> target;

    bool found = false;
    for (int i = 0; i < recordCount; i++) {
        if (strcmp(records[i].name, target) == 0) {
            found = true;
            cout << "\ncustomer: " << records[i].name << " \n" << records[i].amount
                 << " cents in " << records[i].currency << endl;

            calculate(records[i].amount, records[i].currency);
            cout << "change: ";
            int* coinSet = nullptr;
            if (strcmp(records[i].currency, "AU$") == 0) coinSet = AU;
            else if (strcmp(records[i].currency, "US$") == 0) coinSet = US;
            else if (strcmp(records[i].currency, "EUR") == 0) coinSet = EU;

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

void updateRecord(char* name, int amount, char* currency) {
    bool duplicate = false;

    for (int i = 0; i < recordCount; i++) {
        if (strcmp(records[i].name, name) == 0 && strcmp(records[i].currency, currency) == 0) {
            records[i].amount += amount;
            duplicate = true;
            break;
        }
    }

    if (!duplicate && recordCount < 100) {
        strncpy(records[recordCount].name, name, sizeof(records[recordCount].name) - 1);
        records[recordCount].name[sizeof(records[recordCount].name) - 1] = '\0';

        records[recordCount].amount = amount;

        strncpy(records[recordCount].currency, currency, sizeof(records[recordCount].currency) - 1);
        records[recordCount].currency[sizeof(records[recordCount].currency) - 1] = '\0';

        recordCount++;
    }
}

void Extraction(char* line) {
    if (line == nullptr || line[0] == '\0') return;

    char* words[10];
    int wordCount = 0;

char lineCopy[256];
int j = 0;
int start = 0;

for (int i = 0; line[i] != '\0'; i++) {
    if (line[i] == ' ') {
        lineCopy[j] = '\0';
        words[wordCount++] = &lineCopy[start];
        start = j + 1;
        j++;
    } else {
        lineCopy[j++] = line[i];
    }
}
// capture last word
lineCopy[j] = '\0';
words[wordCount++] = &lineCopy[start];
    if (wordCount < 3) return;

    char* name = words[0];
    int amount = atoi(words[1]);
    char* currency = words[wordCount - 1];

    updateRecord(name, amount, currency);
}

void readfile() {
    ifstream inputfile("coins.txt");
    if (!inputfile.is_open()) {
        cerr << "Error opening file!" << endl;
        return;
    }

    char line[256];
    while (inputfile.getline(line, sizeof(line))) {
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
