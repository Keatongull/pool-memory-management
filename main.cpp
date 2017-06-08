#ifdef NDEBUG
#undef NDEBUG
#endif

#include <iostream>
#include <string>
#include "MyObject.h"
using namespace std;

int main() {
    MyObject::profile();
    // Create an array of MyObject heap objects
    const int MAXOBJS{10};
    MyObject* objs[MAXOBJS];
    for (int i{0}; i < MAXOBJS; ++i)
        objs[i] = MyObject::create(i, "\"" + to_string(i) + "\"");
    cout << "Object 5 == " << *objs[5] << endl;
    delete objs[5];
    objs[5] = nullptr;
    MyObject::profile();

    cout << "Creating another object:\n";
    MyObject* anotherObject = MyObject::create(100, "anotherObject");
    cout << "anotherObject == " << *anotherObject << endl;

    cout << "Creating yet another object:\n";
    MyObject* yetAnotherObject = MyObject::create(120, "yetAnotherObject");
    cout << "yetAnotherObject == " << *yetAnotherObject << endl;

    // Delete everything
    MyObject::profile();
    delete anotherObject;
    delete yetAnotherObject;
    for (size_t i{0}; i < MAXOBJS; ++i)
        delete objs[i];
    MyObject::profile();
}
//The overall project was good. Learning new things with C++ is great. 
//I was struggling on this one though quite a bit. Working with low level 
//programs is fun and interesting. I learned some new features about C++ 
//including the Placement new and reinterpt cast.
