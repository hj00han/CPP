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
#include "Utils.h"
#include "AidMan.h"

using namespace std;
namespace sdds {
	unsigned int AidMan::menu() const {
		cout << "Aid Management System" << endl
			<< "Date: ";
		cout << date << endl << "Data file: ";

		//display file name depands on the value;
		if (m_fileName == nullptr) {
			cout << "No file" << endl;
		}
		else {
			cout << m_fileName << endl;
		}

		cout << endl;
		return m_Menu.run();
	}

	AidMan::AidMan(const char* fileName) {
		//Initialize m_menContent
		m_Menu.content("List Items\tAdd Item\tRemove Item\tUpdate Quantity\tSort\tShip Items\tNew/Open Aid Database");

		if (fileName != nullptr) {
			ut.alocpy(m_fileName, fileName);
		}
		else {
			m_fileName = nullptr;
		}
	}

	AidMan::~AidMan() {
		delete[] m_fileName;
		m_fileName = nullptr;
	}

	void AidMan::run() {
		unsigned int code;
		do {
			code = menu();
			switch (code) {
			case 1:
				cout << "\n****List Items****\n\n";
				break;
			case 2:
				cout << "\n****Add Item****\n\n";
				break;
			case 3:
				cout << "\n****Remove Item****\n\n";
				break;
			case 4:
				cout << "\n****Update Quantity****\n\n";
				break;
			case 5:
				cout << "\n****Sort****\n\n";
				break;
			case 6:
				cout<< "\n****Ship Items****\n\n";
				break;
			case 7:
				cout << "\n****New/Open Aid Database****\n\n";
				break;
			case 0:
				cout << "Exiting Program!\n";
				break;
			}
		} while (code != 0);		
	}
}