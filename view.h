/*
#ifndef VIEW_H_INCLUDED
#define VIEW_H_INCLUDED
#include "date.h"

//view 'class', to separate model and controller, low coupling-> reuseability, maintainability
class view
{
public:
    int openMenu();


    void visit(const date& d);
    void visit(const int& i);

    void displayWindstats(float avg,float stdev);

    void displayTemperatureStats(float avg,float stdev);
    void displaySpcc(int month, int year, float s_t, float s_r, float t_r);

//    void displayTotalSR(float sum);

    void terminate();

    int AskMonth();

    int AskYear();
    void ChoiceError();
    void MonthlyWeatherStatsHeader(int year);
    void displayMonthlyRow(int month, float Wavg, float Wstd, float Tavg, float Tstd, float SR);

    void displaySpcc(int month, double st, double sr, double tr);
};


#endif // VIEW_H_INCLUDED
*/
