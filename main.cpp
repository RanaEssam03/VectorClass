// FCAI – Object-Oriented Programming – 2022 - Assignment 3
// Program Name: MRVector
// Last Modification Date: 8/12/2022
// Author1 and ID and Group: Rana Essam, 20210133, Group B S17 S18
// Author2 and ID and Group: Mohannad Hisham,  20210413   , Group B S17 S18
// Teaching Assistant: Eng. Samar
// Purpose: Vector class

#include "MRVector.h"
#include "MRVector.cpp"


int main() {
    int * arr =new int[5];
    for(int i = 0 ; i < 5 ; i++){
        arr[i] = i+1;
    }
    MRVector<int> v( arr, 5);
   v.insert(v.begin(), 11);
   v.insert(v.end(), 9);
   v.push_back(10);
   cout << v << endl;


}