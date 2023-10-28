/***********************************************************************
Name : Hyunjoo Han
Email : hhan39@myseneca.ca
ID : 132749227
Date of completion : 9/14/2023
***********************************************************************/

/***********************************************************************
// OOP244 Workshop #1 lab: tester program
//
// File  WordStat_prof.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
***********************************************************************/

#include <iostream>
#include "Word.h"

using namespace sdds;
using namespace std;

int main() {
   char filename[256];
   programTitle();
   cout << "Enter filename: ";
   cin >> filename;
   wordStats(filename);
   return 0;
}