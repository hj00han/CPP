/***********************************************************************
Final Project Milestone 2
Name : Hyunjoo Han
Email : hhan39@myseneca.ca
ID : 132749227
Date of completion : 11/09/2023

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Status.h"
#include "Utils.h"

using namespace std;

namespace sdds {
	//Constructor
	Status::Status(const char* statDesc) {
		if (statDesc == nullptr) {
			m_statDesc = nullptr;
		}
		else {
			ut.alocpy(m_statDesc, statDesc); //using Utils module function for deep copy
		}
		m_statCode = 0;
	}

	//Rule of three
	//Copy Constructor
	Status::Status(const Status& status) {
		//m_statDesc = nullptr;
		*this = status;
	}

	//Copy Assignment Operator
	Status& Status::operator =(const Status& status) {
		if (this != &status) {
			ut.alocpy(m_statDesc, status.m_statDesc);
			m_statCode = status.m_statCode;
		}
		return *this;
	}

	//Destructor
	Status::~Status() {
		delete[] m_statDesc;
		m_statDesc = nullptr;
	}

	Status& Status::operator =(const char* statDesc) {
		if (statDesc != nullptr) {
			ut.alocpy(m_statDesc, statDesc);
		}
		return *this;
	}

	Status& Status::operator =(int statCode) {
		m_statCode = statCode;
		return *this;;
	}

	Status::operator int() const {
		return m_statCode;
	}

	Status::operator const char* () const {
		return m_statDesc;
	}

	Status::operator bool() const {
		return m_statDesc == nullptr;
	}

	Status& Status::clear() {
		delete[] m_statDesc;
		m_statDesc = nullptr;
		m_statCode = 0;
		return *this;
	}

	std::ostream& operator <<(std::ostream& ostr, const Status& status) {
		if (!status) {
			if (status.m_statCode != 0) {
				ostr << "ERR#" << status.m_statCode << ": ";
			}
			ostr << status.m_statDesc;
		}
		return ostr;
	}
}
