#include <iostream>
#include <string>
#include <sstream>
#include "MyObject.h"
using namespace std;

template<typename T>
string toString(const T& t)
{
    ostringstream os;
    os << t;
    return os.str();
}

int main()
{
    const size_t MAXOBJS = 20;
    MyObject* objs[MAXOBJS];

    for (unsigned int i = 0; i < MAXOBJS; ++i)
        objs[i] = MyObject::create(i, "\"" + toString(i) + "\"");
    cout << "Object 5 == " << *objs[5] << endl;
    delete objs[5];
    objs[5] = 0;
    MyObject::profile();

    cout << "Creating another object:\n";
    MyObject* anotherObject = MyObject::create(100, "anotherObject");
   cout << "anotherObject == " << *anotherObject << endl;

    cout << "Creating yet another object:\n";
    MyObject* yetAnotherObject = MyObject::create(120, "yetAnotherObject");
   cout << "yetAnotherObject == " << *yetAnotherObject << endl;

    delete anotherObject;
    delete yetAnotherObject;
    for (unsigned int i = 0; i < MAXOBJS; ++i)
        delete objs[i];
    MyObject::profile();
}

