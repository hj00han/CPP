#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Container.h"

using namespace std;

namespace sdds {
	void Container::setEmpty() {
		m_content[0] = '\0';
		m_capacity = 0;
		m_volume = 0;
	}

	int Container::capacity() const {
		return m_capacity;
	}

	int Container::volume() const {
		return m_volume;
	}

	Container::Container(const char* content, int capacity, int volume) {
		if (content == nullptr || volume > capacity) {
			m_content[0] = '\0'; //Invalid statte
		}
		else {
			strcpy(m_content, content);
			m_capacity = capacity;
			m_volume = volume;
		}
	}

	int Container::operator +=(int volume) {
		int addedVol;
		if (m_capacity - m_volume >= volume) {//check if there is enough capacity
			m_volume += volume;
			addedVol = volume;
		}
		else {
			addedVol = m_capacity - m_volume;
			m_volume = m_capacity;
		}
		return addedVol;
	}

	int Container::operator -=(int volume) {
		int deductedVol;
		if (m_volume >= volume) {//check if there is enough volume
			m_volume -= volume;
			deductedVol = volume;
		}
		else {
			deductedVol = m_volume;
			m_volume = 0;
		}
		return deductedVol;
	}
	Container::operator bool() const {
		return !(m_content[0] == '\0'); 
	}
	void Container::clear(int capacity, const char* content) {
		if (capacity > 0 && content != nullptr && content[0] != '\0') {
			m_capacity = capacity;
			strcpy(m_content, content);
			m_volume = 0;
		}
	}
	
	ostream& Container::print(ostream& ostr) const {
		if (*this) {
			ostr << m_content <<": (" << m_volume << "cc/" << m_capacity << ")";
		}
		else {
			ostr << "****: (**cc/***)";
		}
		return ostr;
	}

	istream& Container::read(istream& istr) {
		bool invalidInput = true;
		int input;
		int minVal = 1;
		int maxVal = 220000;
		if (*this) {
			cout << "Add to ";
			cout << *this;
			cout << endl << "> ";
			while (invalidInput) {
				istr >> input;
				if (!istr) {
					cout << "Invalid Integer, retry: ";
				}
				else if (input < minVal || input > maxVal) {
					cout << "Value out of range [" << minVal << "<=val<=" << maxVal << "]";
				}
				else {
					invalidInput = false;
				}
			}
			//Add the value when valid input is received
			cout << "Added " << (*this += input) << " CCs" << endl;

		}
		else { //When in invalid state
			cout << "Broken Container, adding aborted! Press <ENTER> to continue...." << endl;
		}
		return istr;
	}

	ostream& operator <<(std::ostream& ostr, Container& container) {
		return container.print(ostr);
	}

	istream& operator >>(std::istream& istr, Container& container) {
		return container.read(istr);
	}

	
}