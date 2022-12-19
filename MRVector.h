/**
 * @file MRVector.h
 * @author Rana (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef VECTORCLASS_MRVECTOR_H
#define VECTORCLASS_MRVECTOR_H

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

template <class T>

class MRVector{
private:
    T *arr;
    long long sz = 0;
    long long cap = 10;
public:
    typedef T* iterator;
    // default constructor
    MRVector();
    // Constructors and Big 4
    MRVector(int cap);			// Initialize by specific capacity
    // No content is added, size = 0
    // Assign a default size value
    MRVector (T* , int  n );		// Initialize by n items from array
    MRVector (const MRVector& v2);	// Initialize with a copy
    ~MRVector()		;		// Delete allocated memory
    MRVector &operator=(const MRVector& v2) ;  // Copy assignment
    MRVector &operator=(const MRVector&& v2); // Move assignment

    // Access operations
    T& operator[](int index); // Access item by reference

    // Modifying operations
    int push_back(T item); // Add item to end of vec & return # of items
    // Increase capacity of needed

    T pop_back();     // Remove and return last element in vec
    void erase(iterator);        // Remove item at iterator
    void erase( iterator first, iterator last);

    // Throw exception if invalid iter
    void clear();     // Delete all vector content

    // Iterators 		// Supports *, + and ++ operations at least
    // Can use: typedef T* iterator
    // Or u can use std::iterator so you can
    void insert(iterator itr, T elmnt);
    // apply STL algorithms on XYVector
    iterator begin();	// Return an iterator (T*)
    iterator end();	    // Return an iterator (T*)

    // Comparison operations
    bool operator==(const MRVector<T>& v2); // Return true if ==
    bool operator< (const MRVector<T>& v2); // Compares item by item

    // Capacity operations
    int size();     // Return current size of vec
    int capacity() ; // Return size of current allocated array
    void resize(int newSz) ;        // Relocate to bigger space
    bool empty();        // Return true if size is 0

    // Friends
    template<class T2>friend ostream& operator << (ostream& out, const MRVector<T2>  &v);
    void fillWithZeroes();

};


#endif //VECTORCLASS_MRVECTOR_H
