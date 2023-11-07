/***********************************************************************
Name : Hyunjoo Han
Email : hhan39@myseneca.ca
ID : 132749227
Date of completion : 11/02/2023

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "HealthCard.h"

using namespace std;
namespace sdds {
	bool HealthCard::validID(const char* name, long long number, const char vCode[], const char sNumber[]) const {
		bool valid = (name != nullptr && name[0] != '\0' && number > 999999999 && number < 9999999999
			&& strlen(vCode) == 2 && strlen(sNumber) == 9);
		return valid;
	}

	void HealthCard::setEmpty() {
		delete[] m_name;
		m_name = nullptr;
	}

	void HealthCard::allocateAndCopy(const char* name) {
		delete[] m_name;
		m_name = new char[strlen(name) + 1];
		strcpy(m_name, name);
	}

	void HealthCard::extractChar(istream& istr, char ch) const {
		char next;
		next = istr.peek();
		//See if the next character in the buffer is same as 'ch' argument
		if (next == ch) {
			istr.ignore();
		}
		else {
			//Ignore remaining charactoers up to 1000 characters or 'ch'
			istr.ignore(10000, ch);
			//Set the istream into a fail state
			istr.setstate(ios::failbit);
		}
	}

	ostream& HealthCard::printIDInfo(ostream& ostr)const {
		return ostr << m_number << "-" << m_vCode << ", " << m_sNumber;
	}
	
	void HealthCard::set(const char* name, long long number, const char vCode[], const char sNumber[]) {
		//Calling member function to validate argumnets
		bool valid = validID(name, number, vCode, sNumber);
		if (valid) {
			allocateAndCopy(name);
			m_number = number;
			strcpy(m_vCode, vCode);
			strcpy(m_sNumber, sNumber);
		}
		else {
			setEmpty();
		}
	}

	//Constructor
	HealthCard::HealthCard(const char* name, long long number, const char vCode[], const char sNumber[]) {
		set(name, number, vCode, sNumber);
	}

	//Copy constructor 
	HealthCard::HealthCard(const HealthCard& hc) {
		m_name = nullptr;
		*this = hc; 
		//Use copy assignmnet operator overload
	}

	//Copy Assignment operator overload
	HealthCard& HealthCard::operator=(const HealthCard& hc) {
		if (this != &hc) {
			//Use set function to assign the values
			set(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber);
		}
		return *this;
	}

	//Destructor
	HealthCard::~HealthCard() {
		delete[] m_name;
		m_name = nullptr;
	}

	//Conversion operator
	HealthCard::operator bool() const {
		return m_name != nullptr;
	}

	ostream& HealthCard::print(ostream& ostr, bool toFile)const{
		if (*this) {
			if (toFile) {
				ostr << m_name << ",";
				//print health card ID information by Calling member funtion
				printIDInfo(ostr);
				ostr << endl;
			}
			else {
				ostr.width(50);
				ostr.setf(ios::left);
				ostr.fill('.');
				ostr << m_name;
				printIDInfo(ostr);
			}
		}
		return ostr;
	}

	istream& HealthCard::read(istream& istr) {
		//Temp local variables to get input
		char name[MaxNameLength + 1];
		long long number;
		char vCode[3];
		char sNumber[10];
		
		istr.get(name, MaxNameLength, ',');
		extractChar(istr, ',');
		istr >> number;
		extractChar(istr, '-');
		istr.get(vCode, 3, ',');
		extractChar(istr, ',');
		istr.get(sNumber, 10, '\n');
		if (istr) {
			//Assign the inputs
			set(name, number, vCode, sNumber);
		}
		istr.clear();
		istr.ignore(1000, '\n');
		return istr;
	}

	ostream& operator<<(ostream& ostr, const HealthCard& hc) {
		if (hc) {
			hc.print(ostr, false);
		}
		else {
			ostr << "Invalid Health Card Record";
		}
		return ostr;
	}

	istream& operator>>(istream& istr, HealthCard& hc) {
		return hc.read(istr);
	}
}

 