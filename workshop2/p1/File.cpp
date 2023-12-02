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
