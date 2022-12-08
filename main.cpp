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
    MRVector<int> v(3);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    cout << v;

}