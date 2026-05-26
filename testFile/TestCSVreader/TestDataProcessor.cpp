
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "../../dataProcessor.h"
#include "../../Vector.h"
#include "../../singleWeatherStat.h"

using namespace std;

void processing_Test1(const string &filename);//check what CSVs are in the text file
void processing_Test2();//finding WAST, S, T, SR
void processing_Test3();//storing one line into Records

void dataProcessorTests() {
    const string sourceFile = "../../data/data_source.txt";

    cout << "4. tesing DataProcessor class" << endl << endl;

    processing_Test1(sourceFile);
    processing_Test2();
    processing_Test3();


}


void processing_Test1(const string &filename) {
    cout << "test: reading CSV list"<< endl;
    ifstream infile(filename);
    if (!infile) {
        cout << "result: fail!! source file not found!" << endl << endl;
        return;
    }
    string csvName;
    int count = 0;
    while (getline(infile, csvName)) {
        if (!csvName.empty()) {
            cout << "  found CSV file: " << csvName << endl;
            count++;
        }
    }
    cout << "result: Pass "<< endl << endl;
}

void processing_Test2() {
    cout << "test: header parsing" << endl;
    string tempHeaderFile = "temp_header.csv";
    ofstream outfile(tempHeaderFile);
    outfile << "T,SR,WAST,S";
    outfile.close();

    string headers;
    string column;
    int WAST = -1;
    int S = -1;
    int T = -1;
    int SR = -1;
    int index=0;

    ifstream infile(tempHeaderFile);
    if(getline(infile, headers)){
    stringstream ss(headers);

    while(getline(ss,column,',')){
        if (column == "WAST"){
            WAST = index;
        }
        if (column == "S"){
            S = index;
        }
        if (column == "T"){
            T = index;
        }
        if (column == "SR"){
            SR = index;
        }
        index++;
    }
    }
    infile.close();
    cout << "expected indexes: WAST=2, S=3, T=0, SR=1"<< endl;
    cout<<" actual: WAST=" << WAST << ", S=" << S << ", T=" << T << ", SR=" << SR << endl << endl;

}


void processing_Test3() {
    cout << "test: storing one line into Records" << endl;

    dataProcessor dp;
    string testfile = "test_single.csv";
    ofstream outfile(testfile);
    outfile << "WAST,S,T,SR\n";
    outfile << "1/03/2015 9:40,10.5,22.3,500\n";
    outfile.close();

    dp.openCSV(testfile);
    const Vector<singleWeatherStat>& records = dp.getAllRecords();

    if (records.getSize() == 1) {
        cout << "  record stored successfully." << endl;
        cout << "  wind Speed: " << records[0].windSpeed << " (expected 10.5)" << endl;
        cout << "  temp: " << records[0].temperature << " (expected 22.3)" << endl;
}
}
