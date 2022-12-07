#include "MRVector.h"

template <class T> // each function has its own template
MRVector<T>:: MRVector(T* arr2, int cap){   //// Initialize by n items from array
    this->cap = cap;
    arr = new T[cap];
    for(long long i = 0 ; i < cap ; i++){
        arr[i] = arr2[i];
    }
}

template <class T> // each function has its own template
MRVector<T>:: ~MRVector(){  /// Delete allocated memory
    delete [] arr;
}

template <class T> // each function has its own template
MRVector<T> &MRVector<T>::operator=(const MRVector<T> &&v2) { /// Move assignment operator
    if(this != &v2){
        delete arr;
        arr = new T[v2.cap];
        for(long long i = 0 ; i < v2.cap ; i++){
            arr[i] = v2.arr[i];
        }
    }
    return *this;
}

