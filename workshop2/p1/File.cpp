/***********************************************************************
Name : Hyunjoo Han
Email : hhan39@myseneca.ca
ID : 132749227
Date of completion : 9/19/2023

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
***********************************************************************/

/***********************************************************************
// OOP244 Workshop #2 lab (part 1)
//
// File  File.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//    To be completed by students
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include "File.h"

namespace sdds {
    FILE* fptr;
    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }
    int noOfRecords() {
        int noOfRecs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1) {
            noOfRecs += (ch == '\n');
        }
        rewind(fptr);
        return noOfRecs;
    }
    void closeFile() {
        if (fptr) fclose(fptr);
    }
    /// TODO: read functions go here
    bool read(char*& name) {
        bool success = false;
        char readName[127];

        if (fscanf(fptr, "%127[^\n]\n", readName) == 1) {
            name = new char[strlen(readName) + 1];
            strcpy(name, readName);
            success = true;
        }
        return success;
    }

    bool read(int &empNo) {
        bool success = false;
        int readNo;
        if (fscanf(fptr, "%d,", &readNo) == 1) {
            empNo = readNo;
            success = true;
        }
        return success;
    }

    bool read(double &salary) {
        bool success = false;
        double readSal;
        if (fscanf(fptr, "%lf,", &readSal) == 1) {
            salary = readSal;
            success = true;
        }
        return success;
    }

}