/***********************************************************************
Final Project Milestone 51
Name : Hyunjoo Han
Email : hhan39@myseneca.ca
ID : 132749227
Date of completion : 11/29/2023

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Menu.h"
#include "Utils.h"

using namespace std;
namespace sdds {
	Menu::Menu(const char* menContent) {
		m_numOfOption = countOptions(menContent);
		if (m_numOfOption > 15 || menContent == nullptr) {
			m_menContent = nullptr;
		}
		else {
			ut.alocpy(m_menContent, menContent);
		}
	}

	Menu::~Menu() {
		delete[] m_menContent;
		m_menContent = nullptr;
	}

	unsigned int Menu::run() const {
		unsigned int input;
		if (*this) {
			displayMenu(m_menContent, m_numOfOption);
			cout << "---------------------------------" << endl << "0- Exit" << endl;
			input = ut.getint(0, m_numOfOption, "> "); //get Valid input by using a function from Utils module
		}
		else {
			cout << "Invalid Menu!" << endl;
			input = 0;
		}
		return input;
	}

	Menu::operator bool() const {
		//return true if the class is in valid state
		return m_menContent != nullptr;
	}

	void Menu::content(const char* menContent) {
		if (menContent != nullptr) {
			ut.alocpy(m_menContent, menContent);
		}
		//Updating m_numOfOption
		m_numOfOption = countOptions(menContent);
	}

	int countOptions(const char* menContent) {
		int numOptions = 0;
		if (menContent != nullptr) {
			while (*menContent) {
				if (*menContent == '\t') {
					numOptions++; //Counting tab
				}
				menContent++;
			}
			numOptions++;//Number of option = Number of tab + 1
		}
		return numOptions;
	}

	void displayMenu(const char* menContent, int numOfOption) {
		for (int i = 0; i < numOfOption; i++) {
			cout << i + 1 << "- ";
			while (*menContent != '\t' && *menContent != '\0') {
				cout << *menContent;
				menContent++;
			}
			cout << endl;
			menContent++;
		}
	}
}