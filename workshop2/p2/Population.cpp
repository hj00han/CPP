#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <iostream>
#include <cstdio>
#include "Population.h"
#include "File.h"

using namespace std;

namespace sdds {

    int noOfMatches = 0, noOfRecs = 0;
    Population* recordPopulation; //Array of struct to store read records
    Population* matchPopulation; //Array of struct to store matching values

    bool startsWith(const char* cstring, const char* subString) {
        return std::strstr(cstring, subString) == cstring;
    }

    void sort() { //sort the record by population
        int i, j;
        Population temp;
        for (i = noOfRecs - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (recordPopulation[j].population > recordPopulation[j + 1].population) {
                    temp = recordPopulation[j];
                    recordPopulation[j] = recordPopulation[j + 1];
                    recordPopulation[j + 1] = temp;
                }
            }
        }
    }

    bool getPostalCode(char* postal_code_prefix) {
        cout << "Population Report" << endl << "-----------------" << endl << "Enter postal code:" << endl << "> ";
        cin >> postal_code_prefix;
        if (!strcmp(postal_code_prefix, "!")) {
            return false;
        }
        else {
            return true;
        }
    }
    bool load(Population& population) {
        bool success = false;
        if (read(population.postalCode) && read(population.population)) {
            success = true;
        }
        return success;
    }

    bool load(const char* filename, const char* partial_postal_code_prefix) {
        int i, j = 0;

        //Open the file, store the records in the struct array
        if (openFile(filename)) {
            noOfRecs = noOfRecords();
            recordPopulation = new Population[noOfRecs];

            for (int i = 0; i < noOfRecs; i++) { 
                load(recordPopulation[i]);
            }
            sort();
        }
        else {
            return false;
        }

        // Check if input is "all" - to print all record, store all record in the struct array 'matchPopulation'
        if (!strcmp("all", partial_postal_code_prefix)) {
            noOfMatches = noOfRecs;
            matchPopulation = new Population[noOfMatches];
            for (i = 0; i < noOfRecs; i++) {
                matchPopulation[i] = recordPopulation[i];
            }
        }
        //Find matching records and store them in the struct array 'matchPopulation'
        else {
            noOfMatches = 0;
            for (i = 0; i < noOfRecs; i++) {
                if (startsWith(recordPopulation[i].postalCode, partial_postal_code_prefix))
                    noOfMatches++;
            }

            matchPopulation = new Population[noOfMatches];
            for (i = 0; i < noOfRecs; i++) {
                if (startsWith(recordPopulation[i].postalCode, partial_postal_code_prefix)) {
                    strcpy(matchPopulation[j].postalCode, recordPopulation[i].postalCode);
                    matchPopulation[j].population = recordPopulation[i].population;
                    j++;
                }
            }
        }
        closeFile();
        return true;
    }

    void display(const Population population) {
        cout << population.postalCode << ":  " << population.population << endl;
    }

    void display() {
        int sumPopulation = 0;

        cout << "Postal Code: population" << endl << "-------------------------" << endl;
        //Printing values of the struct array 'matchPopulation'
        for (int i = 0; i < noOfMatches; i++) { 
            cout << i + 1 << "- ";
            display(matchPopulation[i]);
            sumPopulation += matchPopulation[i].population;
        }
        cout << "-------------------------" << endl << "Population of the listed areas: " << sumPopulation << endl << endl;
    }

    void deallocateMemory() {
        delete[] matchPopulation;
        delete[] recordPopulation;

    }

}
