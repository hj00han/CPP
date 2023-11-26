/***********************************************************************
Name : Hyunjoo Han
Email : hhan39@myseneca.ca
ID : 132749227
Date of completion : 11/22/2023

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Graduate.h"

using namespace std;
namespace sdds {
	Graduate::Graduate():Student() {
		m_supervisor = nullptr;
		m_thesisTitle = nullptr;
	}

	Graduate::Graduate(const char* name, int age, const char* thesisTitle,const char* supervisor) : Student(name, age) {
		//copy thesisTitle
		if (thesisTitle != nullptr && thesisTitle[0] != '\0') {
			m_thesisTitle = new char[strlen(thesisTitle) + 1];
			strcpy(m_thesisTitle, thesisTitle);
		}
		else {
			m_thesisTitle = nullptr;
		}
		//copy supervisor
		if (supervisor != nullptr && supervisor[0] != '\0') {
			m_supervisor = new char[strlen(supervisor) + 1];
			strcpy(m_supervisor, supervisor);
		}
		else {
			m_supervisor = nullptr;
		}
	}

	Graduate::Graduate(const Graduate& graduate) : Student(graduate) {
		m_supervisor = new char[strlen(graduate.m_supervisor) + 1];
		strcpy(m_supervisor, graduate.m_supervisor);
		m_thesisTitle = new char[strlen(graduate.m_thesisTitle) + 1];
		strcpy(m_thesisTitle, graduate.m_thesisTitle);
	}

	Graduate& Graduate::operator=(const Graduate& graduate){
		if (this != &graduate) {
			delete[] m_supervisor;
			delete[] m_thesisTitle;
			Student::operator=(graduate);
			if (graduate.m_supervisor != nullptr) {
				m_supervisor = new char[strlen(graduate.m_supervisor) + 1];
				strcpy(m_supervisor, graduate.m_supervisor);
			}
			else {
				m_supervisor = nullptr;
			}
			if (graduate.m_thesisTitle != nullptr) {
				
				m_thesisTitle = new char[strlen(graduate.m_thesisTitle) + 1];
				strcpy(m_thesisTitle, graduate.m_thesisTitle);
			}
			else {
				m_thesisTitle = nullptr;
			}
		}
		return *this;
	}

	Graduate::~Graduate() {
		delete[] m_supervisor;
		m_supervisor = nullptr;
		delete[] m_thesisTitle;
		m_thesisTitle = nullptr;
	}

	void Graduate::display() {
		Student::display();
		cout << "Thesis Title: " << m_thesisTitle << endl
			<< "Supervisor: " << m_supervisor << endl
			<< "---------------------------------------------" << endl;
	}
}