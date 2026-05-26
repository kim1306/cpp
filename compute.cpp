#include <iostream>
#include <cmath>
#include <map>
#include "compute.h"
#include "Vector.h"


float compute::getAvgWind(int month, int year)
{
    auto it = database.find(year);
    if (it == database.end()) {
        return 0.0f;
    }
    const Vector<singleWeatherStat>& records = it->second.getAll();
    float sum = 0.0f;
    int count = 0;

    for (int i = 0; i < records.getSize(); i++) {
        if (records[i].d.getMonth() == month) {
            sum += records[i].windSpeed;
            count++;
        }
    }

    if (count == 0) return 0.0f;
    return (3.6f * sum / count);
}

float compute::getStdevWind(int month, int year)
{
    auto it = database.find(year);
    if (it == database.end()) {
        return 0.0f;
    }

    float avg = getAvgWind(month, year) / 3.6f;  // convert back to m/s
    const Vector<singleWeatherStat>& records = it->second.getAll();

    float variance_sum = 0.0f;
    int count = 0;

    for (int i = 0; i < records.getSize(); i++) {
        if (records[i].d.getMonth() == month) {
            float deviation = records[i].windSpeed - avg;
            variance_sum += (deviation * deviation);
            count++;
        }
    }

    if (count == 0) return 0.0f;
    return 3.6f * std::sqrt(variance_sum / count);
    }

float compute::getAvgTemp(int month, int year)
{

    auto it = database.find(year);
    if (it == database.end()) {
        return 0.0f;
    }

    const Vector<singleWeatherStat>& records = it->second.getAll();

    float sum = 0.0f;
    int count = 0;

    for (int i = 0; i < records.getSize(); i++) {
        if (records[i].d.getMonth() == month) {
            sum += records[i].temperature;
            count++;
        }
    }

    if (count == 0) return 0.0f;
    return (sum / count);
}

float compute::getStdevTemp(int month, int year)
{

    auto it = database.find(year);
    if (it == database.end()) {
        return 0.0f;
    }

    float avg = getAvgTemp(month, year);

    const Vector<singleWeatherStat>&records = it->second.getAll();

    float variance_sum = 0.0f;
    int count = 0;

    for (int i = 0; i < records.getSize(); i++) {
        if (records[i].d.getMonth() == month) {
            float deviation = records[i].temperature - avg;
            variance_sum += (deviation * deviation);
            count++;
        }
    }

    if (count == 0) return 0.0f;
    return std::sqrt(variance_sum / count);
}

float compute::getTotalSolarRad(int month, int year)
{
    auto it = database.find(year);
    if (it == database.end()) {
        return 0.0f;
    }

    const Vector<singleWeatherStat>& records = it->second.getAll();

    float sum = 0.0f;
    int count = 0;

    for (int i = 0; i < records.getSize(); i++) {
        if (records[i].d.getMonth() == month) {
            sum += records[i].solarRadiation;
            count++;
        }
    }

    if (count == 0) return 0.0f;
    return (sum / 6.0f) / 1000.0f;  // convert to kWh/m^2
}

double compute::getSPCC(int month, const std::string& type)
{

    Vector<double> X;
    Vector<double> Y;

    for (auto it = database.begin(); it != database.end(); ++it) {
        const Vector<singleWeatherStat> &records = it->second.getAll();


        for (int i = 0; i < records.getSize(); i++) {
            if (records[i].d.getMonth() != month) {
                continue;
            }


            if (type == "ST" || type == "st") {
                X.addRecord(records[i].windSpeed);
                Y.addRecord(records[i].temperature);
            } else if (type == "SR" || type == "sr") {
                X.addRecord(records[i].windSpeed);
                Y.addRecord(records[i].solarRadiation);
            } else if (type == "TR" || type == "tr") {
                X.addRecord(records[i].temperature);
                Y.addRecord(records[i].solarRadiation);
            }
        }
    }

    int n = X.getSize();
    if (n == 0 || n != Y.getSize()) return 0.0;


    double sum_X = 0, sum_Y = 0, sum_XY = 0, sum_X2 = 0, sum_Y2 = 0;

    for (int i = 0; i < n; i++) {
        sum_X  += X[i];
        sum_Y  += Y[i];
        sum_XY += X[i] * Y[i];
        sum_X2 += X[i] * X[i];
        sum_Y2 += Y[i] * Y[i];
    }

    double numerator   = (n * sum_XY) - (sum_X * sum_Y);
    double denominator = std::sqrt(((n * sum_X2) - (sum_X * sum_X)) *
                                   ((n * sum_Y2) - (sum_Y * sum_Y)));
    if (denominator ==0.0) return 0.0;

    return numerator / denominator;
}
