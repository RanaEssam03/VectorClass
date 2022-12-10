#include "MRVector.h"

template <class T>
MRVector<T>::MRVector() { /// default constructor
    arr = new T[cap];
}
template<class T>
MRVector<T>::MRVector(int cap) {
    this->cap = cap;
    arr = new T[cap];
    fillWithZeroes();
}
template <class T> // each function has its own template
MRVector<T>:: MRVector(T* arr2, int n){   //// Initialize by n items from array
    if( n > cap ){
        cap*=2;
    }
    arr = new T[cap];
    sz = n;
    for(long long i = 0 ; i < n ; i++){
        arr[i] = arr2[i];
    }
    fillWithZeroes();

}

template <class T> // each function has its own template
MRVector<T>:: ~MRVector(){  /// Delete allocated memory
    delete [] arr;
}

template<class T>
MRVector<T>::MRVector(const MRVector &v2) { /// Initialize with a copy
    delete[] arr;
    this->cap = v2.cap;
    this->sz = v2.sz;
    arr = new T[cap];
    for(long long i = 0 ; i < cap ; i++){
        arr[i] = v2.arr[i];
    }
    cout << "Copy constructor called" << endl;
}

template<class T>
MRVector<T> &MRVector<T>::operator=(const MRVector &v2) {
    if(this != &v2) {
        delete[] arr;
        this->cap = v2.cap;
        this->sz = v2.sz;
        arr = new T[cap];
        for (long long i = 0; i < cap; i++) {
            arr[i] = v2.arr[i];
        }
    }
    cout << "Copy assignment called" << endl;
    return *this;

}

template <class T> // each function has its own template
MRVector<T> &MRVector<T>::operator=(const MRVector<T> &&v2) { /// Move assignment operator
    if(this != &v2){
        delete[] arr;
        arr = new T[v2.cap];
        for(long long i = 0 ; i < v2.cap ; i++){
            arr[i] = v2.arr[i];
        }
    }
    return *this;
}

template <class T>
T& MRVector<T>:: operator[](int index){ /// Access item by reference
    if(index < cap){
        if(arr[index] == 0)
            sz++;
        return arr[index];
    }
    else{
        cout << "\aIndex out of range" << endl;
        exit(-1);
    }

}

template<class T>
int MRVector<T>::push_back(T item) {   // Error
    if(sz < cap){
        arr[sz++] = item;
    }
    else{
        T* temp = new T[cap*2];
        cap *= 2;
        for(long long i = 0 ; i < cap ; i++){
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
        temp = nullptr;
        arr[sz++] = item;
    }
    return 0;
}

template <class T>
T MRVector<T>::pop_back(){
    if(sz > 0){
        T* p = new int[cap];
        copy(arr, arr+sz-1, p);
        T temp = arr[sz-1];
        delete [] arr;
       arr= p;
        sz--;
        return temp;
    }
    else{
        cout << "\aVector is Empty" << endl;
        return 0;
    }
}

template<class T>
void MRVector<T>::erase(iterator it) {

    if(it < begin() || it > end()){
        cout << "\aInvalid iterator" << endl;
        exit(-1);
    }
    else{
        for(iterator i = it ; i < end() ; i++){
            *i = *(i+1);
        }
        sz--;
    }
}

template<class T>
void MRVector<T>::erase(iterator first, iterator last) {
    if(first < begin() || first > end() || last < begin() || last > end()){
        cout << "\aInvalid iterator" << endl;
        exit(-1);
    }
    else{
        T* temp = new T[cap];
        iterator itr2 = temp;
        sz -= last-first;
        for(iterator itr = begin() ; itr < first ; itr++){
            *itr2 = *itr;
            itr2++;
        }
        if(last < begin())
            last++;
        for(iterator itr = last ; itr <= end() ; itr++){
            *itr2 = *itr;
        }
        delete []arr;
        arr = temp;

        }
}

template<class T>
void MRVector<T>::clear() {
    delete [] arr;
    arr = new T[cap];
    sz = 0;

}

template <class T>
void MRVector<T>::insert(iterator itr, T elmnt) {
    if( itr > end() || itr < begin()){
        exit(-1);
    }
    else{
        if(cap == sz){
            T* arr2 = new T[cap*2];
            iterator temp = arr2;
            int j = 0;
            sz ++;
            for(iterator i = begin() ; i < itr ;i++){
               *temp = *i;
               temp++;
            }
           *temp = elmnt;
            temp++;
            for(iterator i = itr +1 ; i < end()+1 ; i++){
                *temp = *(i-1);
                temp++;
            }
            delete [] arr;
            arr = arr2;

        }
        else
        {
            sz++;
            for(iterator i = end()+1 ; i > itr ; i--){
                *i = *(i-1);
            }
           *itr = elmnt;
        }

    }
}

template<class T>
T* MRVector<T>::begin() {
    return arr;
}

template <class T>
T* MRVector<T>::end() {
    return arr + sz;
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

template<class T>
bool MRVector<T>::operator<(const MRVector <T> &v2) {
    if(sz < v2.sz){
        return true;
    }
    else if(sz > v2.sz){
        return false;
    }
    else{
        for(long long i=0;i <sz;i++){
            if(arr[i] < v2.arr[i]){
                return true;
            }
            else{
                return false;
            }
        }
    }

}

template<class T>
int MRVector<T>::size() {
    return sz;
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

template<class T>
bool MRVector<T>::empty() {
    if(sz == 0){
        return true;
    }
    else{
        return false;
    }
}


template<class T> ostream & operator<<(ostream &out,  const MRVector<T> &v){
    for(int i = 0 ; i < v.sz ; i++){
        out << v.arr[i] << " ";
    }
    return out;
}

 template <class T>
 void MRVector<T>::fillWithZeroes() {
    for(int i = sz ; i < cap; i++){
        arr[i] = 0;
    }
}



