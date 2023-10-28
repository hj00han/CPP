/***********************************************************************
Name : Hyunjoo Han
Email : hhan39@myseneca.ca
ID : 132749227
Date of completion : 10/16/2023

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
***********************************************************************/

/***********************************************************************
// OOP244 Workshop #5 DIY (part 2): tester program
//
// File  Portfolio.cpp
// Version 1.0
// Author   Asam Gulaid, revised by Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Portfolio.h"

using namespace std;
namespace sdds {


    Portfolio::Portfolio() {
        emptyPortfolio();
    }

    void Portfolio::emptyPortfolio()
    {
        m_value = 0;
        m_stock[0] = 0;
        m_type = 'E';
    }

    Portfolio::Portfolio(double value, const char* stock, char type) {
        emptyPortfolio();
        if (value >= 0 && (type == 'V' || type == 'G' || type == 'I')) {
            m_value = value;
            m_type = type;
            strcpy(m_stock, stock);
        }
    }

    void Portfolio::dispPortfolio() const {
        cout << " ";
        cout.width(10);
        cout << (const char*)(*this);
        cout << " | ";
        cout << "Value: ";
        cout.width(10);
        cout << double(*this);
        cout << " | ";
        cout << " Type: ";
        cout << char(*this);
    }
    std::ostream& Portfolio::display() const {

        if (~*this) {
            cout << " Portfolio  |  Bad-NG |";
            dispPortfolio();
        }
        else if (*this) {
            cout << " Portfolio  |  Active |";
            dispPortfolio();

        }
        else {
            cout << " Portfolio  |  EMPTY  |";
            dispPortfolio();
        }
        return cout;
    }

    Portfolio::operator double() const {
        return m_value;
    }

    Portfolio::operator const char* () const {
        return m_stock;
    }

    Portfolio::operator char() const {
        return m_type;
    }

    Portfolio::operator bool() const {
        return (m_type == 'G' || m_type == 'V' || m_type == 'I');
    }

    Portfolio& Portfolio::operator +=(double value) {
        if (*this && value > 0) {
            this->m_value += value;
        }
        return *this;        
    }

    Portfolio& Portfolio::operator -=(double value) {
        if (*this && value > 0) {
            this->m_value -= value;
        }
        return *this;
    }

    bool Portfolio::operator ~() const {
        return (m_value < 0);
    }

    Portfolio& Portfolio::operator <<(Portfolio& rightOp) {
        if (this == &rightOp) {
            return *this;
        }
        this->m_value += rightOp.m_value;
        rightOp.emptyPortfolio();
        return *this;
    }

    Portfolio& Portfolio::operator >>(Portfolio& rightOp) {
        if (this == &rightOp) {
            return *this;
        }
        rightOp.m_value += this->m_value;
        this->emptyPortfolio();
        return *this;
    }

    double operator +(const Portfolio& leftOp, const Portfolio& rightOp) {
        double result = 0;
        if (&leftOp && &rightOp) {
            result = double(leftOp) + double(rightOp);
        }
        return result;
    }

    double operator +=(double& value, const Portfolio& rightOp) {
        return value += double(rightOp);
    }
}