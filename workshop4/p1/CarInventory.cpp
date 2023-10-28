/***********************************************************************
Name : Hyunjoo Han
Email : hhan39@myseneca.ca
ID : 132749227
Date of completion : 10/06/2023

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include <iomanip> //to use 'setw' 
#include"CarInventory.h"

using namespace std;

namespace sdds {
    CarInventory::CarInventory() //constructor
    {
        resetInfo();
    }

    CarInventory::CarInventory(const char* type, const char* brand, const char* model, int year, int code, double price) //constructor
    {
        resetInfo();
        if (type != nullptr && brand != nullptr && model != nullptr
            && year >= 1990 && code >= 100 && code <= 999 && price > 0) {
            setInfo(type, brand, model, year, code, price);
        }
    }

    CarInventory::~CarInventory() //destructor
    {
        delete[] m_type;
        delete[] m_brand;
        delete[] m_model;

    }

    void CarInventory::resetInfo()
    {
        m_type = nullptr;
        m_brand = nullptr;
        m_model = nullptr;
        m_year = 0;
        m_code = 0;
        m_price = 0;
    }

    CarInventory& CarInventory::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price)
    {
        delete[] m_type;
        m_type = new char[strlen(type) + 1];
        strcpy(m_type, type);

        delete[] m_brand;
        m_brand = new char[strlen(brand) + 1];
        strcpy(m_brand, brand);

        delete[] m_model;
        m_model = new char[strlen(model) + 1];
        strcpy(m_model, model);

        m_year = year;
        m_code = code;
        m_price = price;

        return *this;
    }

    void CarInventory::printInfo() const
    {
        //use setw - set width funcion 
        cout << left << "| " << setw(10) << m_type
            << " | " << setw(16) << m_brand
            << " | " << setw(16) << m_model
            << " | " << m_year << right
            << " | " << setw(4) << m_code 
            << " | " << setw(9) << fixed << setprecision(2) << double(m_price)
            //display only 2 floating point of m_price
            << " |" << "\n";
    }

    bool CarInventory::isValid() const
    {
        bool valid = false;
        if (m_type != nullptr && m_brand != nullptr && m_model != nullptr
            && m_year >= 1990 && m_code >= 100 && m_code <= 999 && m_price > 0) {
            valid = true;
        }
        return valid;
    }

    bool CarInventory::isSimilarTo(const CarInventory& car) const
    {
        bool similar = false;
        if (!strcmp(m_type, car.m_type) && !strcmp(m_model, car.m_model) && !strcmp(m_brand, car.m_brand) && m_year == car.m_year) {
            similar = true;
        }
        return similar;

    }

    int find_similar(CarInventory car[], const int num_cars) {
        int index;
        for (int i = 0; i < num_cars; i++) {
            for (int j = i + 1; j < num_cars; j++) {
                if ((car[i].isValid() && car[j].isValid()) && car[i].isSimilarTo(car[j])) {
                    index = i;
                }
            }
        }
        return index;
    }
}