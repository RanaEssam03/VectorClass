/**
 * @file MRVector.cpp
 * @author 1 Rana Essam, 20210133, Group B S17 S18
 * @author 2 Mohannad Hisham,  20210413   , Group B S17 S18
 * @version 0.1
 * @date 2022-12-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "MRVector.h"

template <class T>
/**
 * @brief Construct a new MRVector<T>::MRVector object
 * 
 */
MRVector<T>::MRVector() { /// default constructor
    arr = new T[cap];
    fillWithZeroes();
}

/**
 * @brief Construct a new MRVector<T>::MRVector object
 * 
 * @tparam T refers to the data type of the vector 
 * @param cap trefers to the initial capacity of the vector 
 */
template<class T>
MRVector<T>::MRVector(int cap) {
    this->cap = cap;
    arr = new T[cap];
    fillWithZeroes();
}

/**
 * @brief Construct a new MRVector<T> by initialize its elements from a array with fixed size
 * 
 * @tparam T datatype
 * @param arr2 the array which the vector will copy all its elements
 * @param n the size of the array
 */
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
/**
 * @brief Destruct the object and delete all the dynamic memory allocation 
 * 
 * @tparam T datatype
 */
template <class T> // each function has its own template
MRVector<T>:: ~MRVector(){  /// Delete allocated memory
    delete [] arr;
}

/**
 * @brief Construct a new MRVector<T>::MRVector object from another vector using deep copy
 * 
 * @tparam T datatype
 * @param v2 the second MRVector with the current vector will copy its elements from it
 */
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

/**
 * @brief overload the copy assignment operator to avoid shallow copy and use deep copy instead
 * 
 * @tparam T datatype
 * @param v2 the second MRVector which the current vector will copy its elements from it
 */
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

/**
 * @brief move assignment operator to move only the elements from a vector to another and this move not include the ownership  
 * and to avoid memory leak
 * @tparam T refers to the datatype of the vector
 * @param v2 the second vector which the current vector will take its values
 * @return MRVector<T>& 
 */
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


/**
 * @brief overload the operator [] to work with MRVector and access elements by index
 * 
 * @tparam T  refers to the datatype
 * @param index refers to the index of the required element of the vector
 * @return T& 
 */
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

/**
 * @brief this function to appened elements to MEVector even if its size is not suitable 
 * 
 * @tparam T refers to the datatype
 * @param item refers to the value which will be appended to the vector
 * @return int 
 */
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

/**
 * @brief this function delete the last element of MRVector  
 * 
 * @tparam T refers to the datatype of the vector
 * @return T 
 */
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

/**
 * @brief this function to erase an element with specific iterator 
 * 
 * @tparam T refers to the datatype of the vector
 * @param it refers to the iterator which its element will be erased
 */
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

/**
 * @brief this function to erase a range of elements with specific iterators as  start and end 
 * 
 * @tparam T refers to the datatype of the vector
 * @param first refers to the first iterator which the erasing will start from it
 * @param last refers to the last iterator which the erasing will end at it
 */
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
            itr2++;
        }
        delete []arr;
        arr = temp;

        }
}

/**
 * @brief this function to clear all the vector elements
 * @tparam T refers to the datatype of the vector
 */
template<class T>
void MRVector<T>::clear() {
    delete [] arr;
    arr = new T[cap];
    sz = 0;

}

/**
 * @brief this function to insert an element in specific iterator position
 * @tparam T refers to the datatype of the vector
 * @param itr the iterator which the new element will be inserted at its position
 * @param elmnt the element which will be inserted in the vector
 */
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

/**
 * @brief this function to a pointer to the begin of the MRVector
 * 
 * @tparam T datatype 
 * @return T* a pointer to the beginning 
 */

template<class T>
T* MRVector<T>::begin() {
    return arr;
}

/**
 * @brief this function to a pointer to the end of the MRVector
 * 
 * @tparam T datatype 
 * @return T* a pointer to the end
 */
template <class T>
T* MRVector<T>::end() {
    return arr + sz;
}

/***
 * @brief this function to check if the two vectors are equal or not
 * @tparam T refers to the datatype of the vector
 * @param v2 the second vector which will be checked with the current vector
 * @return
 */
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
/**
 * @brief this function checks if two vectors are equal or not
 * @tparam T refers to the datatype of the vector
 * @param v2 the second vector which will be checked with the current one
 * @return
 */
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

/**
 * @brief this function returns the actual size of the vector
 * @tparam T refers to the datatype of the vector
 * @return
 */
template<class T>
int MRVector<T>::size() {
    return sz;
}

/**
 * @brief this function Return size of current allocated array
 * @tparam T refers to the datatype of the vector
 * @return
 */
template <class T>
int MRVector<T>::capacity() { /// Return size of current allocated array
    return cap;
}

/**
 * @brief this function Relocate to bigger space
 * @tparam T refers to the datatype of the vector
 * @param newSz the new capacity which the vector will resized to
 */
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
/**
 * @brief this function checks if the vector is empty or not
 * @tparam T refers to the datatype of the vector
 * @return
 */
template<class T>
bool MRVector<T>::empty() {
    if(sz == 0){
        return true;
    }
    else{
        return false;
    }
}

/**
 * @brief this function is overloading function to operator << to be suitable with MRVector class
 * @tparam T refers to the datatype of the vector
 * @param out
 * @param v
 * @return
 */
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


