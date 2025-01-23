//MyObject.cpp
#include "Pool.h"
#include "MyObject.h"
using namespace std;

Pool MyObject::pool_(sizeof(MyObject), 10);

void* MyObject::operator new(size_t size) {
    return pool_.allocate();
}

void MyObject::operator delete(void* ptr) {
    pool_.deallocate(ptr);
}

MyObject* MyObject::create(int id, const std::string& name) {
    return new MyObject(id, name);
}

void MyObject::profile() {
    pool_.profile();
}

MyObject::MyObject(int id, const std::string& name) : id_(id), name_(name) {}

ostream& operator<<(ostream& os, const MyObject& obj) {
    os << "MyObject{id: " << obj.id_ << ", name: " << obj.name_ << "}";
    return os;
}
