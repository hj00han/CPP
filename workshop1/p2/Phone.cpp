/***********************************************************************
Name : Hyunjoo Han
Email : hhan39@myseneca.ca
ID : 132749227
Date of completion : 9/19/2023

I have done all the coding by myself and only copied the code that 
my professor provided to complete my workshops and assignments.
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio> 
#include "cStrTools.h"
#include "Phone.h"

#define MAX_LENGTH 50
#define MAX_NUMBER 4

using namespace std;

namespace sdds {
    void phoneDir(const char* programTitle, const char* fileName)
    {
        char namePar[MAX_LENGTH + 1], 
            nameParLower[MAX_LENGTH + 1], 
            nameInFile[MAX_LENGTH + 1], 
            nameLower[MAX_LENGTH + 1];        
        char number[MAX_NUMBER + 1], // Even if there 3 variables are number(integer), need to be made string to keep the leading 0.
            areaCode[MAX_NUMBER +1], 
            preFix[MAX_NUMBER+1];
        int keepLooping = 1;
        
        cout << programTitle << " phone direcotry search" << endl
            << "-------------------------------------------------------" << endl;

        FILE* fptr = fopen(fileName, "r");

        if (fptr) { //The file is successfully opened
            do {
                cout << "Enter a partial name to search (no spaces) or enter '!' to exit" << endl << "> ";
                cin >> namePar;
                if (strCmp(namePar, "!") == 0) { // check if user wants to exit(if input is "!")
                    break; // if the user want to exit, go out of the loop.
                }
                else {
                    while (fscanf(fptr, "%[^\t]\t%s\t%s\t%s\n", nameInFile, areaCode, preFix, number) != EOF) {
                        toLowerCaseAndCopy(nameLower, nameInFile); 
                        toLowerCaseAndCopy(nameParLower, namePar);
                        // By using 'toLowerCaseAndCopy' functions for input and names in the file, 
                        // Searching for the name match became case-insensitive
                        if (strStr(nameLower, nameParLower) != nullptr) {
                            //Using 'strStr' because input is a partial name
                            cout << nameInFile << ": (" << areaCode << ") " << preFix << "-" << number << endl;
                        }
                    }
                }
                rewind(fptr); // Go back to the beginnig of the file after finishing looking for the name match
            } while (keepLooping);
            cout << "Thank you for using Star Wars directory." << endl;
        }
        else{ // Opening file failed
            cout << fileName << " file not found!" << endl << "Thank you for using Broken Phone Book directory." <<endl;
        }
        fclose(fptr);
    }

}



