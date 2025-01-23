//MyObject.h
#include <iosfwd>
#include <cstddef>
#include <iostream>
#include <string>
#include "Pool.h"
#ifndef MyObject_H
#define MyObject_H

class MyObject {
public:
    static void* operator new(size_t size);
    static void operator delete(void* ptr);
    static MyObject* create(int id, const std::string& name);
    static void profile();

    friend std::ostream& operator<<(std::ostream& os, const MyObject& obj);

private:
    MyObject(int id, const std::string& name);
    int id_;
    std::string name_;
    static Pool pool_;
};

#endif
