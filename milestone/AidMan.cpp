/***********************************************************************
Final Project Milestone 2
Name : Hyunjoo Han
Email : hhan39@myseneca.ca
ID : 132749227
Date of completion : 11/02/2023

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Utils.h"
#include "AidMan.h"

using namespace std;
namespace sdds {
	unsigned int AidMan::menu() const {
		char* fileName;
		if (m_fileName == nullptr) {
			ut.alocpy(fileName, m_fileName);
		}
		else {
			ut.alocpy(fileName, "No file");
		}

		cout << "Aid Management System Prototype" << endl
			<< "Date: " << endl
			<< "Data file: " << fileName << endl
			<< "---------------------------------" << endl;
		return m_Menu.run();
	}

	AidMan::AidMan(const char* fileName) {
		if (fileName != nullptr) {
			ut.alocpy(m_fileName, fileName);
		}
		else {
			m_fileName = nullptr;
		}
	}

	AidMan::AidMan(const AidMan& aidMan) {
		*this = aidMan;
	}

	AidMan& AidMan::operator =(const AidMan& aidMan) {
		if (this != &aidMan) {
			ut.alocpy(m_fileName, aidMan.m_fileName);
		}
	}

	AidMan::~AidMan() {
		delete[] m_fileName;
	}

	void AidMan::run() {
		while (unsigned int code = menu() != 0) {
			if (code == 1) {
				cout << endl << "***List Items***";
			}
		}
	}
}