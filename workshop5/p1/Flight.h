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
// File  Flight.h
// Version 1.0
// Author   Asam Gulaid, revised by Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/

#ifndef SDDS_FLIGHT_H
#define SDDS_FLIGHT_H
#include <iostream>
#define MINFUEL_PER_PERSON 600;
namespace sdds {

    const int Boen747Capacity = 388;
    const int FuelTankCapacity = 238840;

    class Flight {

        int m_passengers = 0;
        double m_fuel = 0;
        char m_title[16];
        void emptyPlane();

    public:
        Flight();
        Flight(int passengers, double fuel, const char* title);
        std::ostream& display()const;
        operator bool() const;
        operator int() const;
        operator double() const;
        operator const char* () const;
        bool operator ~() const;
        Flight& operator =(Flight& rightOp);
        Flight& operator =(int rightPss);
        Flight& operator =(double rightFuel);
        Flight& operator +=(double addFuel);
        Flight& operator +=(int addPss);
        Flight& operator -=(double reduceFuel);
        Flight& operator -=(int reducePss);
        Flight& operator <<(Flight& movePss);
        Flight& operator >>(Flight& movePss);
        int operator +(const Flight& rightOp);
    };
    int operator +=(int& leftOp, const Flight& rightOp);

}
#endif // SDDS_FLIGHT_H