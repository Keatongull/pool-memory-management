#include <iostream>
#include <string>
#include <sstream>
#include "MyObject.h"

std::string toString(int i) {
    std::ostringstream os;
    os << i;
    return os.str();
}

int main() {
    const size_t MAXOBJS = 20;
    MyObject* objs[MAXOBJS];

    for (unsigned int i = 0; i < MAXOBJS; ++i)
        objs[i] = MyObject::create(i, "\"" + toString(i) + "\"");
    std::cout << "Object 5 == " << *objs[5] << std::endl;
    delete objs[5];
    objs[5] = nullptr;
    MyObject::profile();

    std::cout << "Creating another object:\n";
    MyObject* anotherObject = MyObject::create(100, "anotherObject");
    std::cout << "anotherObject == " << *anotherObject << std::endl;

    std::cout << "Creating yet another object:\n";
    MyObject* yetAnotherObject = MyObject::create(120, "yetAnotherObject");
    std::cout << "yetAnotherObject == " << *yetAnotherObject << std::endl;

    delete anotherObject;
    delete yetAnotherObject;
    for (unsigned int i = 0; i < MAXOBJS; ++i)
        delete objs[i];
    MyObject::profile();

    return 0;
}
