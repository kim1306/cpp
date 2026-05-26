#include <iostream>
#include <fstream>
#include <sstream>
#include "dataProcessor.h"
#include "singleWeatherStat.h"
#include "BST.h"
#include "date.h"
#include <string>
using namespace std;

void dataProcessor::openfile(const string &filename)
{
    ifstream openTxt(filename);
    if (!openTxt)
    {
        cerr << "failed to open file\n";
        return;
    }
    string csv;
    while (getline(openTxt, csv))
    {
        openCSV("data/" + csv);
    }
    openTxt.close();
}

void dataProcessor::openCSV(const string &csv)
{
    ifstream infile(csv);
    if (!infile)
    {
        cerr << "failed to open file " << csv << endl;
        return;
    }
    parsing(infile);
    infile.close();
}

void dataProcessor::parsing(ifstream &infile)
{
    string headers, column;
    int index = 0;
    getline(infile, headers);
    stringstream ss(headers);
    while (getline(ss, column, ','))
    {
        string cleanedStr = cleanString(column);
        if (cleanedStr == "WAST") WASTindex = index;
        if (cleanedStr == "S")    Sindex    = index;
        if (cleanedStr == "T")    Tindex    = index;
        if (cleanedStr == "SR")   SRindex   = index;
        index++;
    }
    collectData(infile);
}

void dataProcessor::collectData(ifstream &infile)
{
    string line, value;
    while (getline(infile, line))
    {
        stringstream ss(line);
        int index = 0;
        singleWeatherStat temporaryRecord;

        while (getline(ss, value, ','))
        {
            if (index == WASTindex)
            {
                // format: 1/03/2015 9:40
                stringstream ssWast(value);
                string datePart, timePart;
                ssWast >> datePart >> timePart;
                int d, m, y, hr, min;
                char sep;
                stringstream(datePart) >> d >> sep >> m >> sep >> y;
                stringstream(timePart) >> hr >> sep >> min;
                temporaryRecord.d.setDay(d);
                temporaryRecord.d.setMonth(m);
                temporaryRecord.d.setYear(y);
                temporaryRecord.t.setHour(hr);
                temporaryRecord.t.setMinute(min);
            }
            else if (index == Sindex)
            {
                stringstream(value) >> temporaryRecord.windSpeed;
            }
            else if (index == Tindex)
            {
                stringstream(value) >> temporaryRecord.temperature;
            }
            else if (index == SRindex)
            {
                stringstream(value) >> temporaryRecord.solarRadiation;
            }
            index++;
        }


        int recordYear = temporaryRecord.d.getYear();
        Bst<singleWeatherStat>& myTree = database[recordYear];
        myTree.insert(temporaryRecord);
    }
}

const std::map<int, Bst<singleWeatherStat>>& dataProcessor::getDatabase() const
{
    return database;
}

string dataProcessor::cleanString(string s)
{
    string result;
    for (char c : s)
    {
        if (c >= 65 && c <= 122) //in ASCII, chars(including capital)
            result += c;
    }
    return result;
}
