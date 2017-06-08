//MyObject.cpp
#include "Pool.h"
#include "MyObject.h"
using namespace std;

Pool MyObject::pool(sizeof(MyObject));

void* MyObject::operator new (size_t siz){
    return pool.allocate();
}
void MyObject::operator delete(void* ptr){
    pool.deallocate(ptr); 
}
void MyObject::profile(){
    pool.profile();
}
ostream& operator<<(ostream& os, const MyObject& obj){
os << "{" << obj.id << ", " << obj.name << "}";
return os;
}