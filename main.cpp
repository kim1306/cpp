#include <iostream>
#include <iomanip>
#include <map>
#include "BST.h"
#include "date.h"
#include "Time.h"
#include "singleWeatherStat.h"
#include "dataProcessor.h"
#include "compute.h"

using namespace std;


void displayAllData(const std::map<int, Bst<singleWeatherStat>>& database)
{
    cout << "\n" << endl;
    cout << "ALL LOADED DATA" << endl;
    cout << "\n"<< endl;

    if (database.empty()) {
        cout << "No data loaded." << endl;
        return;
    }


for (auto it = database.begin(); it != database.end(); ++it) {
    int year = it->first;
    const Bst<singleWeatherStat>& bst = it->second;

        const Vector<singleWeatherStat>& records = bst.getAll();

        cout << "\nyear " << year << " \n have n data, n=" << records.getSize() << endl;


        for (int i = 0; i < records.getSize(); i++) {
            cout << "  ";
            records[i].display();
            cout << endl;
        }
    }
}


int displayMainMenu()
{
    cout << "\n"<< endl;
    cout << "\n1. display all data" << endl;
    cout << "2. average wind speed" << endl;
    cout << "3. wind speed std deviation" << endl;
    cout << "4. average temperature" << endl;
    cout << "5. temperature std deviation" << endl;
    cout << "6. total solar radiation" << endl;
    cout << "7. Pearson correlation" << endl;
    cout << "8. exit" << endl;
    cout << "\nenter choice ";

    int choice;
    cin >> choice;
    cin.ignore();
    return choice;
}

int getMonth()
{
int month;
    while (true) {
        cout << "enter month: ";
        cin >> month;
        cin.ignore();

        if (month >= 1 && month <= 12) {
            break;
            }

        cout << "invalid month." << endl;
    }

    return month;
}

int getYear(){
int year;

    while (true) {
        cout << "enter year";
        cin >> year;
        cin.ignore();

        if (year >= 1900 && year <= 2100) {
            break;
            }

        cout << "invalid year." << endl;
    }

    return year;
    }

string getCorrelationType()
{
    string type;
    while (true) {
        cout << "enter type \nst= wind-temp, sr =wind-solar, tr =temp-solar ";
        getline(cin, type);

        if (type == "ST" || type == "st" ||
            type == "SR" || type == "sr" ||
            type == "TR" || type == "tr") {
            break;
        }

        cout << "invalid type" << endl;
    }

    return type;
}



void handleAvgWind(compute& analyzer)
{
    int month = getMonth();
    int year = getYear();

    float avg = analyzer.getAvgWind(month, year);
    cout << "\naverage wind speed for month " << month
         << " in year " << year << ": " << avg << " km/h" << endl;
}

void handleStdevWind(compute& analyzer)
{
    int month = getMonth();
    int year = getYear();

    float stdev = analyzer.getStdevWind(month, year);
    cout << "\nwind speed std deviation for month " << month
         << " in year " << year << ": " << stdev << " km/h" << endl;
}

void handleAvgTemp(compute& analyzer)
{
    int month = getMonth();
    int year = getYear();

    float avg = analyzer.getAvgTemp(month, year);
    cout << "\naverage temperature for month " << month
         << " in year " << year << ": " << avg << " C" << endl;
}

void handleStdevTemp(compute& analyzer)
{
    int month = getMonth();
    int year = getYear();

    float stdev = analyzer.getStdevTemp(month, year);
    cout << "\ntemperature std deviation for month " << month
         << " in year " << year << ": " << stdev << " C" << endl;
}

void handleTotalSolar(compute& analyzer)
{
    int month = getMonth();
    int year = getYear();

    float total = analyzer.getTotalSolarRad(month, year);
    cout << "\ntotal solar radiation for month " << month
         << " in year " << year << ": " << total << " kWh/m*m" << endl;
}

void handleCorrelation(compute& analyzer)
{
    int month = getMonth();
    string type = getCorrelationType();

    double correlation = analyzer.getSPCC(month, type);
    cout << fixed << setprecision(4);
    cout << "\npearson correlation (" << type << ") for month "
         << month << ": " << correlation << endl;
}


int main()
{
    cout << "\n";
    cout << "weather program with sPcc" << endl;

    dataProcessor loader;

    try {
        loader.openfile("data/data_source.txt");
        cout << "data loaded successfully!" << endl;
    } catch (const exception& e) {
        cerr << "error loading data: " << e.what() << endl;
        return 1;
    }
    const std::map<int, Bst<singleWeatherStat>>& database = loader.getDatabase();


    compute analyzer(database);

    bool running = true;
    while (running) {
        int choice = displayMainMenu();

        switch (choice) {
            case 1:
                displayAllData(database);
                break;
            case 2:
                handleAvgWind(analyzer);
                break;
            case 3:
                handleStdevWind(analyzer);
                break;
            case 4:
                handleAvgTemp(analyzer);
                break;
            case 5:
                handleStdevTemp(analyzer);
                break;
            case 6:
                handleTotalSolar(analyzer);
                break;
            case 7:
                handleCorrelation(analyzer);
                break;
            case 8:
                running = false;
                cout << "\nexiting... " << endl;
                break;
            default:
                cout << "invalid choice." << endl;
        }
    }

    return 0;
}
