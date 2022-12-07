#include "MRVector.h"

template <class T>
MRVector<T>::MRVector() { /// default constructor
    arr = new T[cap];
}
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

template <class T>
T& MRVector<T>:: operator[](int index){ /// Access item by reference
    if(index <sz){
        return *arr[index];
    }
    else{
        cout << "\aIndex out of range" << endl;
        return nullptr;
    }
}

template <class T>
T MRVector<T>::pop_back(){
    if(sz > 0){
        T temp = arr[sz-1];
        sz--;
        delete arr[sz-1];
        return temp;
    }
    else{
        cout << "\aVector is Empty" << endl;
        return 0;
    }
}

template <class T>
bool MRVector<T>::operator==(const MRVector<T> &v2) { /// Return true if ==
    if(v2.sz != sz){
        return false;
    }
    else{
        for(long long i = 0 ; i < sz; i++){
            if(v2[i] != *this[i]){
                return false;
            }
        }
    }
    return true;
}

template <class T>
int MRVector<T>::capacity() { /// Return size of current allocated array
    return cap;
}

template <class T>    /// Relocate to bigger space
void MRVector<T>::resize(int newSz) {
    if(newSz >= sz && newSz != cap){
        T* arr2 = new T[newSz];
        for(int i = 0 ; i < sz ; i++){
            arr2[i] = arr[i];
        }
        delete []arr;
        arr = new T[newSz];
        cap = newSz;
        for(int i = 0 ; i < sz ; i++){
            arr[i] = arr2[i];
        }
    }
    else if(newSz < sz){
        cout << "\a Cannot resize to smaller size, data will be lost ";
    }
}







