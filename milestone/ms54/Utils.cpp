#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <cstring>
#include <iomanip>
#include "Utils.h"
using namespace std;
namespace sdds {
    // The ut object of type Utils that is accessible to any file including "Utils.h" to call the Utils
    // methods
    Utils ut;

    void Utils::testMode(bool testmode) {
        m_testMode = testmode;
    }

    void Utils::getSystemDate(int* year, int* mon, int* day) {
        if (m_testMode) {
            if (day) *day = sdds_testDay;
            if (mon) *mon = sdds_testMon;
            if (year) *year = sdds_testYear;
        }
        else {
            time_t t = std::time(NULL);
            tm lt = *localtime(&t);
            if (day) *day = lt.tm_mday;
            if (mon) *mon = lt.tm_mon + 1;
            if (year) *year = lt.tm_year + 1900;
        }
    }

    int Utils::daysOfMon(int month, int year)const {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int mon = (month >= 1 && month <= 12 ? month : 13) - 1;
        return days[mon] + int((mon == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    }

    void Utils::alocpy(char*& destination, const char* source) {
        if (destination != nullptr) {
            delete[] destination;
            destination = nullptr;
        }
        if (source != nullptr && source[0] != '\0')
        {
            destination = new char[strlen(source) + 1];
            strcpy(destination, source);
        }
    }

    int Utils::getint(const char* prompt) {
        bool invalid = true;
        int input;
        if (prompt != nullptr) {
            cout << prompt;
        }
        while (invalid) {
            cin >> input;
            if (cin) { //Check if reading input is successful
                invalid = false;
            }
            else {
                cout << "Invalid Integer, retry: ";
                cin.clear();
                cin.ignore(100, '\n');
            }
        }
        return input;
    }

    int Utils::getint(int min, int max, const char* prompt, const char* errMes) {
        bool invalid = true;
        int input;
        input = getint(prompt);
        while (invalid) {
            if (input<min || input>max) {
                if (errMes == nullptr) {
                    cout << "Value out of range [" << min << "<=val<=" << max << "]: ";
                }
                else {
                    cout << errMes << ", retry: ";
                }
                cin >> input;
            }
            else {
                invalid = false;
            }
        }
        return input;
    }

    double Utils::getDouble(double min, double max, const char* prompt) {
        bool invalid = true;
        double input;
        if (prompt != nullptr) {
            cout << prompt;
        }
        while (invalid) {
            cin >> input;
            if (cin) {
                invalid = false;
            }
            else {
                cout << "Invalid number, retry: ";
                cin.clear();
                cin.ignore(100, '\n');
            }
        }

        invalid = true;
        while (invalid) {
            if (input<min || input>max) {
                cout << "Value out of range [";
                cout << fixed << setprecision(2) << min;
                cout << "<=val<=" << fixed << setprecision(2) << max << "]: ";
                cin >> input;
            }
            else {
                invalid = false;
            }
        }
        return input;
    }
}
