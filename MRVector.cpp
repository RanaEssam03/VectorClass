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





