/***********************************************************************
Name : Hyunjoo Han
Email : hhan39@myseneca.ca
ID : 132749227
Date of completion : 11/09/2023

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Pack.h"

using namespace std;

namespace sdds {
	//*******capacity of container(m_capacity) : size * unitsize*******
	//*******volume of container(m_volume) : number of unit * unitsize*******

	Pack::Pack(const char* content, int size, int unitSize, int numOfUnit)
		//Container(content, capacity, volumne)
		:Container(content, size*unitSize, numOfUnit*unitSize) {
		if (unitSize > 0) {
			m_unitSize = unitSize;
		}
		else {
			setEmpty();
		}
	}

	int Pack::operator +=(int numOfUnits) {
		return Container::operator+=(m_unitSize * numOfUnits) / m_unitSize;
	}

	int Pack::operator -=(int numOfUnits) {
		return Container::operator-=(m_unitSize * numOfUnits) / m_unitSize;
	}

	int Pack::unit() const {
		return m_unitSize;
	}

	int Pack::noOfUnits() const {
		return volume() / m_unitSize;
	}

	int Pack::size() const {
		return capacity() / m_unitSize;
	}

	void Pack::clear(int packSize, int unitSize, const char* content) {
		if (unitSize > 0) {
			Container::clear(packSize*unitSize, content);
			m_unitSize = unitSize;
		}
	}
	ostream& Pack::print(ostream& ostr) const {
		Container::print(ostr);
		if (*this) {
			ostr << ", " << noOfUnits() << " in a pack of " << size();
		}
		return ostr;
	}

	istream& Pack::read(istream& istr) {
		int input;
		int minVal = 1;
		int maxVal = size() - noOfUnits();//the number of missing units in the pack
		bool invalidInput = true;
		if (*this) { //conversion to bool
			if (noOfUnits() < size()) {
				cout << "Add to ";
				cout << *this;
				cout << endl << "> ";
				while (invalidInput) {
					istr >> input;
					if (!istr) {
						cout << "Invalid Integer, retry: ";
					}
					else if (input<minVal || input>maxVal) {
						cout << "Value out of range [" << minVal << "<=val<=" << maxVal << "]: ";
					}
					else {
						//Add the value when valid input is received
						cout << "Added " << (*this += input) << endl;
						invalidInput = false;
					}
				}
			}
			else {
				cout << "Pack is full!, press <ENTER> to continue..." << endl;
			}
		}
		else { //When in invalid state
			cout << "Broken Container, adding aborted! Press <ENTER> to continue....";
		}
		return istr;
	}

	ostream& operator <<(ostream& ostr, Pack& pack) {
		return pack.print(ostr);
	}

	istream& operator >>(istream& istr, Pack& pack) {
		return pack.read(istr);
	}
}