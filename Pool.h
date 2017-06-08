//pool.h
#ifndef POOL_H
#define POOL_H

#include <new>
#include <iomanip>
#include <iostream>

class Pool{
  
  private:
    size_t freeCells{};
    size_t liveCells{};
    char* freeptr;
    char** pool;
    size_t blockSize_;
    size_t elemSize_;
    size_t numRows;
    size_t rowSize;

    void grow();
  public:
    Pool(size_t elemSize, size_t blockSize = 5);
    ~Pool();   
    void* allocate();       // Get a pointer inside a pre-allocated block for a new object   
    void deallocate(void* ptr); // Free an object's slot (push the address on the "free list")
    void profile() const;
};

#endif
