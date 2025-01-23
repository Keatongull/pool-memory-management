//pool.h
#ifndef POOL_H
#define POOL_H

#include <new>
#include <iomanip>
#include <iostream>
#include <cstddef>

class Pool {
public:
    Pool(size_t elemSize, size_t blockSize = 5);
    ~Pool();
    void* allocate();       // Get a pointer inside a pre-allocated block for a new object   
    void deallocate(void* ptr); // Free an object's slot (push the address on the "free list")
    void profile() const;
    void grow();
private:
    union Element {
        char* next;
        char data[1]; // Placeholder for actual data
    };

    char** pool;
    char* freeptr;
    size_t numRows;
    size_t blockSize_;
    size_t elemSize_;
    size_t freeCells;
    size_t liveCells; // Add this line
};

#endif
