/***********************************************************************
Name : Hyunjoo Han
Email : hhan39@myseneca.ca
ID : 132749227
Date of completion : 10/12/2023

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
***********************************************************************/

/***********************************************************************
// OOP244 Workshop #5 lab (part 1): tester program
//
// File  Flight.cpp
// Version 1.0
// Author   Asam Gulaid, revised by Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Flight.h"

using namespace std;
namespace sdds {

    void Flight::emptyPlane() {
        m_passengers = 0;
        m_fuel = 0;
        strcpy(m_title, "EmptyPlane");
    }

    // New Flight
    Flight::Flight() {
        emptyPlane();
    }
    Flight::Flight(int passengers, double fuel, const char* title) {
        emptyPlane();
        if (passengers > 0 && passengers <= Boen747Capacity && fuel >= 0 &&
            fuel <= FuelTankCapacity) {
            m_passengers = passengers;
            m_fuel = fuel;
            strcpy(m_title, title);
        }
    }
    std::ostream& Flight::display() const {

        if (*this) {
            cout << " Flight  |  Ready to Depart";
            cout << " ";
            cout.width(10);
            cout << std::string(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        else if (~*this) {
            cout << " Flight  |  Empty Plane    ";
        }
        else {
            cout << " Flight  |  Low Fuel       ";
            cout << " ";
            cout.width(10);
            cout << (const char*)(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        return cout;
    }

    Flight::operator bool() const {
        bool ready = false;
        double minFuel = m_passengers * MINFUEL_PER_PERSON; //calculate minimum fuel 
        if (m_passengers > 0 && m_fuel >= minFuel) {
            ready = true;
        }
        return ready;
    }

    Flight::operator int() const {
        return m_passengers;
    }

    Flight::operator double() const {
        return m_fuel;
    }
    
    Flight::operator const char* () const {
        return m_title;
    }

    bool Flight::operator ~() const {
        bool noPss = false;
        if (m_passengers == 0) {
            noPss = true;
        }
        return noPss;
    }

    Flight& Flight::operator =(Flight& rightOp) {
        if (this == &rightOp) { //Check that the left operand is not the same as the right one.
            return *this;
        }
        else {
            m_passengers = rightOp.m_passengers;
            m_fuel = rightOp.m_fuel;
            strcpy(m_title, rightOp.m_title);
            rightOp.emptyPlane(); //Set the right operand to empty after moving all the variables to the left operand.
            return *this;
        }
    }

    Flight& Flight::operator =(int rightPss) {
        if (rightPss > 0 && rightPss <= Boen747Capacity) {
            m_passengers = rightPss;
        }
        return *this;
    }

    Flight& Flight::operator =(double rightFuel) {
        if (rightFuel > 0 && rightFuel < FuelTankCapacity) {
            m_fuel = rightFuel;
        }
        return *this;
    }

    Flight& Flight::operator +=(double addFuel) {
        if (addFuel > 0) {
            m_fuel += addFuel;
            if (m_fuel > FuelTankCapacity) { //Check if the total fuel exceeds the capacity of the fuel tank
                m_fuel = FuelTankCapacity;
            }
        }
        return *this;
    }

    Flight& Flight::operator +=(int addPss) {
        if (addPss > 0) {
            m_passengers += addPss;
            if (m_passengers > Boen747Capacity) { //Check if the total number of passengers exceeds the capacity of the aircraft
                m_passengers = Boen747Capacity;
            }
        }
        return *this;
    }

    Flight& Flight::operator -=(double reduceFuel) {
        if (reduceFuel > 0) {
            m_fuel -= reduceFuel;
            if (m_fuel < 0) { //Cannot set 'm_fuel' to a negative integer
                m_fuel = 0;
            }
        }
        return *this;
    }

    Flight& Flight::operator -=(int reducePss) {
        if (reducePss > 0) {
            m_passengers -= reducePss;
            if (m_passengers < 0) { //Cannot set 'm_passengers' to a negative integer
                m_passengers = 0;
            }
        }
        return *this;
    }

    Flight& Flight::operator <<(Flight& movePss) {
        if (this == &movePss) {
            return *this;
        }
        if (*this && movePss) {
            int totalPss = this->m_passengers + movePss.m_passengers;

            if (totalPss > Boen747Capacity) { //In case the total number of passengers exceeds the capacity of the aircraft
                this->m_passengers = Boen747Capacity; //Set 'm_passengers' of the left operand to its full capacity
                movePss.m_passengers = totalPss - Boen747Capacity; //Set 'm_passengers' of the right operand to the remaining passengers
            }
            else {
                this->m_passengers += movePss.m_passengers;
                movePss.m_passengers = 0;                
            }            
        }
        return *this;
    }

    Flight& Flight::operator >>(Flight& movePss) {
        if (this == &movePss) {
            return *this;
        }
        if (*this && movePss) {
            int totalPss = this->m_passengers + movePss.m_passengers;

            if (totalPss > Boen747Capacity) { //In case the total number of passengers exceeds the capacity of the aircraft
                movePss = Boen747Capacity; //Set 'm_passengers' of the right operand to its full capacity
                this->m_passengers = totalPss - Boen747Capacity; //Set 'm_passengers' of the left operand to the remaining passenger           
            }
            else {
                movePss.m_passengers += this->m_passengers;
                this->m_passengers = 0;                
            }            
        }
        return *this;
    }

    int Flight::operator +(const Flight& rightOp) {
        if (*this && rightOp) {
            return (int)*this + (int)rightOp; // The operator int returns the value of 'm_passengers'
        }
        return 0;
    }

    int operator +=(int& leftOp, const Flight& rightOp) {
        leftOp += (int)rightOp;
        return leftOp;
    }
}