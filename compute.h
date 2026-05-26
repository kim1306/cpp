#ifndef COMPUTE_H_INCLUDED
#define COMPUTE_H_INCLUDED

#include <map>
#include "BST.h"
#include "singleWeatherStat.h"
#include <string>


class compute
{
private:
    const std::map<int, Bst<singleWeatherStat>>& database;

public:
    compute(const std::map<int, Bst<singleWeatherStat>>& db) : database(db) {}
    float getAvgWind(int month, int year);
    float getStdevWind(int month, int year);
    float getAvgTemp(int month, int year);
    float getStdevTemp(int month, int year);
    float getTotalSolarRad(int month, int year);
    double getSPCC(int month, const std::string& type);
};

#endif // COMPUTE_H_INCLUDED
