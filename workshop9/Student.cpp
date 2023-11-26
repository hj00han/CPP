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
#include "Student.h"

using namespace std;
namespace sdds {
	Student::Student() {
		m_name = nullptr;
		m_age = 0;
	}

	Student::Student(const char* name, int age) {
		if (name != nullptr && name[0] != '\0') {
			m_name = new char[strlen(name) + 1];
			strcpy(m_name, name);
		}
		else {
			m_name = nullptr;
		}
		m_age = age;
	}

	Student::Student(const Student& student) {
		m_name = new char[strlen(student.m_name) + 1];
		strcpy(m_name, student.m_name);
		m_age = student.m_age;
	}

	Student& Student::operator=(const Student& student) {
		if(this != &student) {
			delete[] m_name;
			if (student.m_name != nullptr) {
				m_name = new char[strlen(student.m_name) + 1];
				strcpy(m_name, student.m_name);
			}
			else {
				m_name = nullptr;
			}
			m_age = student.m_age;
		}
		return *this;
	}

	Student::~Student() {
		delete[] m_name;
		m_name = nullptr;
	}

	void Student::display() {
		cout << "Name: " << m_name << endl
			<< "Age: " << m_age << endl;
	}
}