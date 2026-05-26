/*#include <iostream>
#include "view.h"
using namespace std;



void visit(const date& d) {
    std::cout << d.getDay() << "/" << d.getMonth()<< "/" << d.getYear() << std::endl;
}
void visit(const int& i) {
    std::cout << i << std::endl;
}

int view::openMenu()
{


    int choice;

    cout<<"option1: select year and month to get average speed and standard deviation for the wind \n";
    cout<<"option2: select year and month to get average and standard deviation of temperature\n";
    //cout<<"option3: solar radiation in KWh/m*m\n";
    cout<<"option3: PEARSON value for ST, SR, TR\n";
    cout<<"option4: select a year to print all data above in each month\n";
    cout<<"option5: terminate the program\n";

    cout<< "please select option:";
    cin>>choice;
    cout<<"\n\n";
    return choice;
}

void view::displayWindstats(float avg,float stdev)
{
    cout<<"average speed and standard deviation for the wind: "<<avg<<" and "<<stdev<<endl;
}
void view::displayTemperatureStats(float avg, float stdev)
{
    cout<<"average and standard deviation for the temperature: "<<avg<<" and "<<stdev<<endl;
}




void view::displaySpcc(int month, int year, float s_t, float s_r, float t_r) {
    std::cout << "\n--- Sample Pearson Correlation Coefficients ---" << std::endl;
    std::cout << "Month/Year: " << month << "/" << year << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "Pairing                  Coefficient (r)" << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << std::fixed;
    std::cout.precision(2);

    std::cout << "Wind Speed & Temp (S_T): " << s_t << std::endl;
    std::cout << "Wind Speed & Solar (S_R):" << s_r << std::endl;
    std::cout << "Temp & Solar (T_R):      " << t_r << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;
}
/*void view::displayTotalSR(float sum)
{
    cout<<"the total of solar radiation in kmh/(m*m) is: "<<sum<<endl;
}


void view::terminate()
{
    cout<<"ending the program.. press any key to exit"<<endl;
}
int view::AskMonth()
{
    int M;
    cout<<"enter a month: "<<endl;
    cin>>M;
    return M;
}
int view::AskYear()
{
    int Y;
    cout<<"enter a year: "<<endl;
    cin>>Y;
    return Y;
}
void view::ChoiceError()
{
    cout<<"you need to select between 1 and 5!"<<endl;
}


void view::MonthlyWeatherStatsHeader(int year)
{
    cout<<"annual summary for "<<year<<endl;
    cout<<"month: | average wind speed(standard deviation), average temperature(standard deviation), total solar radiation"<<endl;
}
void view::displayMonthlyRow(int month, float Wavg, float Wstd, float Tavg, float Tstd, float SR)
{
    printf("%d :\n%.1f (%.1f)\t%.1f (%.1f)\t%.1f\n", month, Wavg,Wstd,Tavg,Tstd, SR);

}

void view::displaySpcc(int month, double st, double sr, double tr)
{
    std::cout << "\n";
    std::cout << "SPCC for Month: "
              << month << "\n";

    std::cout << "Spcc value for  (Wind Speed and Temperature)       : "<< st << "\n";

    std::cout << "Spcc value for (Wind Speed and Solar Radiation)   : "<< sr << "\n";

    std::cout << "Spcc value for (Temperature and Solar Radiation)  : "<< tr << "\n";
}
*/
