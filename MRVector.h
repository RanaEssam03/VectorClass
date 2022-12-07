#ifndef VECTORCLASS_MRVECTOR_H
#define VECTORCLASS_MRVECTOR_H

#include <iostream>
#include <vector>

using namespace std;

template <class T>

class MRVector{
private:
    T *arr;
    long long sz = 0;
    long long cap = 10;
public:
    // Constructors and Big 4
    MRVector(int cap);			// Initialize by specific capacity
    // No content is added, size = 0
    // Assign a default size value
    MRVector (T*, int  n );		// Initialize by n items from array
    MRVector (const MRVector&);	// Initialize with a copy
    ~MRVector()		;		// Delete allocated memory
    MRVector &operator=(const MRVector& v2) ;  // Copy assignment
    MRVector &operator=(const MRVector&& v2); // Move assignment

    // Access operations
    T& operator[](int index); // Access item by reference
    T pop_back();     // Remove and return last element in vec

};

#endif //VECTORCLASS_MRVECTOR_H
