
#include "../../Time.h"
#include <iostream>

using namespace std;

void time_Test1();//default constructor
void time_Test2();//constructor with parameters
void time_Test3();//setters and individual getters

void timeTests()
{
    cout<<"2. tesing TIME class"<<endl;
    time_Test1();
    time_Test2();
    time_Test3();
}

//--------------------------------------------------------------------

void time_Test1()
{
    Time t;
    cout << "test one: default constructor" << endl;
    cout << "expected:0/0" << endl;
    cout << "actual:" << t.getHour() << "/" << t.getMinute() << endl << endl;
}

//--------------------------------------------------------------------

void time_Test2()
{
    Time t(11,16);
    cout << "test two: constructor with parameters" << endl;
    cout << "expected:16:11" << endl;
    cout << "actual:" << t.getHour() << ":" << t.getMinute()<< endl << endl;
}

//--------------------------------------------------------------------

void time_Test3()
{
    Time t;
    t.setMinute(31);
    t.setHour(12);
    cout << "test three: setters" << endl;
    cout << "expected:12:31" << endl;
    if (t.getMinute() == 31 && t.getHour() == 12)
    {
        cout << "result: pass!!" << endl << endl;
    }
    else
    {
        cout << "result: fail!!" << endl << endl;
    }
}


