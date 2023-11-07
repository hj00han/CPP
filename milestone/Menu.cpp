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
#include <cstring>
#include "Menu.h"
#include "Utils.h"

using namespace std;
namespace sdds {
	int Menu::countOptions(const char* menContent) const {
		int numOptions = 0;
		if (menContent != nullptr) {
			while (*menContent) {
				if (*menContent == '\t') {
					numOptions++; //Counting tab
				}
				menContent++;
			}
		}
		return numOptions + 1; //Number of option = Number of tab + 1
	}
	Menu::Menu() {
		m_menContent = nullptr;
		m_numOfOption = 0;
		m_valid = false;
	}

	Menu::Menu(const char* menContent) {
		m_numOfOption = countOptions(menContent);
		if (m_numOfOption > 15 || menContent == nullptr) {
			m_valid = false;
		}
		else {
			ut.alocpy(m_menContent, menContent);
			m_valid = true;
		}
	}
	Menu::Menu(const Menu& menu) {
		*this = menu;
	}

	Menu& Menu::operator =(const Menu& menu) {
		if (this != &menu) {
			ut.alocpy(m_menContent, menu.m_menContent);
			m_numOfOption = menu.m_numOfOption;
		}
		return *this;
	}

	Menu::~Menu() {
		delete[] m_menContent;
		m_menContent = nullptr;
	}

	unsigned int Menu::run() const {
		unsigned int input;
		if (m_valid) {
			cout << m_menContent;
			cout << "---------------------------------" << endl << "0- Exit" << endl;
			input = ut.getint(0, m_numOfOption, ">", "Invalid Integer");
		}
		else {
			cout << "Invalid Menu!" << endl;
			input = 0;
		}
		return input;
	}
}