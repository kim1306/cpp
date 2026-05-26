

#include "../../date.h"
#include <iostream>

using namespace std;

void date_Test1();
void date_Test2();
void date_Test3();

void dateTests()
{
    cout<<"1. tesing DATE class"<<endl;
    date_Test1();
    date_Test2();
    date_Test3();
}

//--------------------------------------------------------------------

void date_Test1()//test a defaultconstructor
{
    date d;
    cout << "test one: default constructor" << endl;
    cout << "expected:0/0/0" << endl;
    cout << "actual:" << d.getDay() << "/" << d.getMonth() << "/" << d.getYear() << endl << endl;
}

//--------------------------------------------------------------------

void date_Test2()//test constructor with paramters
{
    date d(15, 5, 2026);
    cout << "test two: constructor with parameters" << endl;
    cout << "expected:15/5/2026" << endl;
    cout << "actual:" << d.getDay() << "/" << d.getMonth() << "/" << d.getYear() << endl << endl;
}

//--------------------------------------------------------------------

void date_Test3()//test setters and getters
{
    date d;
    d.setDay(31);
    d.setMonth(12);
    d.setYear(2022);

    cout << "test three: setters" << endl;
    cout << "expected:31/12/2022" << endl;
    if (d.getDay() == 31 && d.getMonth() == 12 && d.getYear() == 2022)
    {
        cout << "result: pass!!" << endl << endl;
    }
    else
    {
        cout << "result: fail!!" << endl << endl;
    }
}

