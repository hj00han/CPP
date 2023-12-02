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

    void closeFile() {
        if (fptr) fclose(fptr);
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

    bool read(char postalCode[]) {
        bool success = false;
        char readPostalCode[POSTALCODE_LENGTH + 1];

        if (fscanf(fptr, "%[^,]", readPostalCode) == 1) {
            strcpy(postalCode, readPostalCode);
            success = true;
        }
        return success;
    }

    bool read(int& population) {
        bool success = false;
        int readPopulation = 0;
        if (fscanf(fptr, ",%d\n", &readPopulation) == 1) {
            population = readPopulation;
            success = true;
        }
        return success;
    }
}
