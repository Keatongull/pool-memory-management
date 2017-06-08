//MyObject.h
#include <iosfwd>
#include <cstddef>
#include "Pool.h"
#ifndef MyObject_H
#define MyObject_H

class MyObject{
    
private:   
    static Pool pool;
    MyObject(int i, const std::string& nm): name(nm) {  // Note initializer list      
        id = i;  
    }  
    
    static void* operator new (size_t siz);
    
public:  
    int id;   
    std::string name;
    static void operator delete(void*);
    static MyObject* create(int id, const std::string& name) { // Factory method      
    return new MyObject(id, name);
   }
    static void profile();
    friend std::ostream& operator<<(std::ostream& os, const MyObject& obj);
    
};

#endif

//The overall project was good. Learning new things with C++ is great. 
//I was struggling on this one though quite a bit. Working with low level 
//programs is fun and interesting. I learned some new features about C++ 
//including the Placement new and reinterpt cast.
