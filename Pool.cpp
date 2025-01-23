//Pool.cpp
#include "Pool.h"
#include <cstring>
#include <cstddef>
#include <cassert>
#include <iostream>
using namespace std;

void Pool::grow(){
    cout<<"Expanding Pool...."<<endl;
    char** tempPool= new char*[numRows + 1];
    memcpy(tempPool, pool, (numRows * sizeof(char*)));
    delete[] pool;
    pool= tempPool;
    pool[numRows] = new char [blockSize_ * elemSize_];
    Element* P = reinterpret_cast<Element*>(pool[numRows]);
    
    for(size_t i{0}; i<blockSize_-1; i++){
        P[i].next = reinterpret_cast<char*>(&P[i+1]);
    }
    
    P[blockSize_-1].next = nullptr;
    freeptr = reinterpret_cast<char*>(P);
    numRows++;
    freeCells+= blockSize_;
}

Pool::Pool(size_t elemSize, size_t blockSize){
    assert(sizeof(elemSize)>=sizeof(char*));
    cout<<"Initializing a pool with element size "<< elemSize <<" and block size "<< blockSize<<endl<<endl;
    numRows = 0;
    blockSize_ = blockSize;
    elemSize_ = elemSize;
    freeptr=nullptr;
    pool = nullptr;
    freeCells = 0;
    liveCells = 0; // Initialize liveCells
}

Pool::~Pool(){
    for(size_t i{0}; i<numRows; i++){
        delete[] pool[i];
    }
    delete[] pool;
}

void* Pool::allocate(){
    if (freeptr== nullptr)
        grow();
    assert(freeptr!=nullptr);
    cout<<"Cell Allocated at "<< reinterpret_cast<void*>(freeptr) <<endl;
    void* temp = freeptr;
    freeptr = *reinterpret_cast<char**>(freeptr);
    freeCells--;
    liveCells++;
    return temp;
}

void Pool::deallocate(void* ptr){
    assert(ptr!=nullptr);
    cout<<"Cell deallocated at "<< ptr <<endl;
    new (ptr) char*(freeptr);
    freeptr = reinterpret_cast<char*>(ptr);
    freeCells++;
    liveCells--;
}

void Pool::profile() const{
    cout<<"Live cells: "<< liveCells<<" ,Free Cells: "<<freeCells <<endl;
    cout<<"Free list: \n"<<std::endl;
    void* freeptr_temp = freeptr;
    while(freeptr_temp!=nullptr){
        cout<<freeptr_temp<<endl;
        freeptr_temp= *reinterpret_cast<char**>(freeptr_temp);
    }
}
