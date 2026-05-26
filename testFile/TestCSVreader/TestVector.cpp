
#include "../../Vector.h"
#include <iostream>
#include <string>

using namespace std;

void vector_Test1();
void vector_Test2();
void vector_Test3();
void vector_Test4();
void vector_Test5();

//--------------------------------------------------------------------

void vectorTests()
{
    cout << "3. testing VECTOR template class " << endl << endl;

    vector_Test1();
    vector_Test2();
    vector_Test3();
    vector_Test4();
    vector_Test5();


}

//--------------------------------------------------------------------

void vector_Test1()
{
    cout << "test one: default constructor and initial state" << endl;
    Vector<int> v;

    cout << "initial size: " << v.getSize() << " (expected: 0)" << endl;
    cout << "initial capacity: " << v.getCapacity() << " (expected: 20)" << endl<< endl;
}

//--------------------------------------------------------------------

void vector_Test2()
{
        cout << "test two: template flexibility" << endl;
    Vector<string> vs;
    vs.addRecord("hello");
    vs.addRecord("world");

    cout << "stored: " << vs[0] << " " << vs[1] << endl;
    if(vs.getSize() == 2) {
            cout << "result: pass" << endl << endl;
    }
    else {
            cout << "result: fail" << endl << endl;
}
}

//--------------------------------------------------------------------

void vector_Test3()
{
    cout << "test three: copy constructor" << endl;
    Vector<int> v1;
    v1.addRecord(100);

    //create v2 as a copy of v1 using copy constructor
    Vector<int> v2(v1);

    //change v1 to check if v2 change
    v1[0] = 500;

    cout << "value of v1[0]: " << v1[0] <<endl;
    cout << " value of v2[0]: " << v2[0] << endl;
    if(v2[0] != v1[0]) {
            cout << "result: pass (successful deep copy)" << endl << endl;
    }

    else {
            cout << "result: fail (successful shallow copy)" << endl << endl;
}
}

//--------------------------------------------------------------------

void vector_Test4()
{
    cout << "test four: assignment operator" << endl;
    Vector<int> v1;
    v1.addRecord(10);
    Vector<int> v2;
    v2.addRecord(20);
    v2 = v1;

    cout << "v2 size after assignment operator: " << v2.getSize() << " (expected: 1)" << endl;
    cout << "value of v2[0]: " << v2[0] << " (expected: 10)" << endl<< endl;

}

//--------------------------------------------------------------------

void vector_Test5()
{

cout << "test five: resizing check" << endl;
    Vector<int> v;
    // add 21 elements to trigger the resize (from 20 to 40)
    for(int i = 0; i < 21; i++) {
        v.addRecord(i);
    }

    cout << "size after 21 elements adds: " << v.getSize() << endl;
    cout << "new capacity: " << v.getCapacity() << " (expected: 40)" << endl<< endl;

}

