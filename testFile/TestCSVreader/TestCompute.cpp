
#include "../../compute.h"
#include "../../Vector.h"
#include "../../singleWeatherStat.h"
#include <iostream>
#include <cmath>

using namespace std;

void compute_Test1(); //average wind speed (with km/h conversion)
void compute_Test2(); //average temperature
void compute_Test3(); //total solar radiation (with kWh conversion)
void compute_Test4(); //standard deviation logic

// Helper function to compare floats
bool IsSame(float actual, float expected);

//--------------------------------------------------------------------

void computeTests()
{
    cout << "5. testing COMPUTE class" << endl << endl;

    compute_Test1();
    compute_Test2();
    compute_Test3();
    compute_Test4();

}

//--------------------------------------------------------------------

void compute_Test1()
{
    cout << "test one: average wind speed calculation" << endl;
    // when wind = 10 m/s.
    // expected: 10 * 3.6 = 36.0 km/h
    Vector<singleWeatherStat> data;
    singleWeatherStat s1, s2;
    s1.d = date(1, 1, 2020);
    s1.windSpeed = 10.0f;
    data.addRecord(s1);
    s2.d = date(1, 1, 2020);
    s2.windSpeed = 20.0f;
    data.addRecord(s2);
    compute calculator(data);
    float result = calculator.getAvgWind(1, 2020);

    //(36+72)/2 ==54
    cout << "expected: 54.0, actual: " << result << endl;
    if (IsSame(result, 54.0f)) cout << "result: pass" << endl << endl;
    else cout << "result: fail" << endl << endl;
}

//--------------------------------------------------------------------

void compute_Test2()
{
    cout << "test two: average temperature" << endl;
    Vector<singleWeatherStat> data;
    singleWeatherStat s1, s2;
    s1.d = date(1, 3, 2022); s1.temperature = 20.0f;
    data.addRecord(s1);
    s2.d = date(15, 3, 2022); s2.temperature = 30.0f;
    data.addRecord(s2);
    compute calculator(data);
    float result = calculator.getAvgTemp(3, 2022);

        cout << "expected: 25.0, actual: " << result << endl;
    if (IsSame(result, 25.0f)) cout << "result: pass" << endl << endl;
    else cout << "result: fail" << endl << endl;
}

//--------------------------------------------------------------------

void compute_Test3()
{
    cout << "test three: total solar radiation (kWh Conversion)" << endl;

    //formula= (total / 6.0) / 1000.0
    Vector<singleWeatherStat> data;
    singleWeatherStat s1, s2;
    s1.d = date(1, 1, 2020);
    s1.solarRadiation = 600.0f;
    data.addRecord(s1);
    s2.d = date(11, 1, 2020);
    s2.solarRadiation = 1200.0f;
    data.addRecord(s2);

    compute calculator(data);
    float result = calculator.getTotalSolarRad(1, 2020);

    cout << "expected: 0.3, actual: " << result << endl;
    if (IsSame(result, 0.3f)) cout << "result: pass" << endl << endl;
    else cout << "result: fail" << endl << endl;

}

//--------------------------------------------------------------------

void compute_Test4()
{
    cout << "test four: standard deviation" << endl;

    Vector<singleWeatherStat> data;
    singleWeatherStat s1, s2;
    s1.d = date(1, 1, 2020); s1.temperature = 10.0f;
    s2.d = date(2, 1, 2020); s2.temperature = 20.0f;
    data.addRecord(s1);
    data.addRecord(s2);
    compute calculator(data);
    float result = calculator.getStdevTemp(1, 2020);

cout << "expected: 5.0, actual: " << result << endl;
    if (IsSame(result, 5.0f)) cout << "result: pass" << endl << endl;
    else cout << "result: fail" << endl << endl;

}

//--------------------------------------------------------------------

bool IsSame(float actual, float expected)
{
    if (actual == expected ){
        return true;
    }
    else {
        return false;
    }
}

