#ifndef DATAPROCESSOR_H_INCLUDED
#define DATAPROCESSOR_H_INCLUDED

#include "Vector.h"
#include <map>
#include "BST.h"
#include "singleWeatherStat.h"
#include <string>
#include <fstream>

class dataProcessor
{
private:
    std::map<int, Bst<singleWeatherStat>> database;

    int WASTindex = -1;
    int Sindex = -1;
    int Tindex = -1;
    int SRindex = -1;

    void openCSV(const std::string &csv);
    void parsing(std::ifstream &infile);
    void collectData(std::ifstream &infile);

public:
    void openfile(const std::string &filename);
    const std::map<int, Bst<singleWeatherStat>>& getDatabase() const;
    std::string cleanString(std::string s);
};

#endif // DATAPROCESSOR_H_INCLUDED
