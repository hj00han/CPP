#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Pack.h"

using namespace std;

namespace sdds {
	Pack::Pack(const char* content, int size, int unitSize, int numOfUnit)
		:Container(content, size*unitSize, numOfUnit*size) {
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

	void Pack::clear(int packSize, int unitSize, char* content) {
		if (unitSize > 0) {
			Container::clear(packSize*unitSize, content);
			m_unitSize = unitSize;
		}
	}
	ostream& Pack::print(ostream& ostr) {
		Container::print(ostr);
		if (this) {
			ostr << ", " << noOfUnits() << " in a pack of " << size();
		}
		return ostr;
	}

	istream& Pack::read(istream& istr) {
		bool invalidInput = true;
		int input;
		int minVal = 1;
		int maxVal = size() - noOfUnits();//the number of missing units in the pack
		if (this) {
			if (noOfUnits() < size()) {
				cout << this;
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
						invalidInput = false;
					}
				}
			}
			else {
				cout << "Pack is full!, press <ENTER> to continue...";
			}
		}
		else {
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