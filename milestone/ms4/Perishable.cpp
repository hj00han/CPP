/***********************************************************************
Name : Hyunjoo Han
Email : hhan39@myseneca.ca
ID : 132749227
Date of completion : 11/24/2023

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include <fstream>
#include "Perishable.h"
#include "Utils.h"


using namespace std;
namespace sdds {
	
	Perishable::Perishable() : Item() {
		m_instruction = nullptr;
		//m_expDate = Date();
		m_expDate.formatted(true);
	}

	Perishable::Perishable(const Perishable& perishable):Item(perishable) {
		if (this != &perishable) {
			if(perishable.m_instruction!=nullptr){
				m_instruction = new char[strlen(perishable.m_instruction) + 1];
				strcpy(m_instruction, perishable.m_instruction);
			}
			else {
				m_instruction = nullptr;
			}
			m_expDate = perishable.m_expDate;
		}
	}

	Perishable& Perishable::operator=(const Perishable& perishable) {
		if (this != &perishable) {
			Item::operator=(perishable);
			m_expDate = perishable.m_expDate;
			delete[] m_instruction;
			if (perishable.m_instruction != nullptr) {
				m_instruction = new char[strlen(perishable.m_instruction) + 1];
				strcpy(m_instruction, perishable.m_instruction);
				//ut.alocpy(m_instruction, perishable.m_instruction);
			}
			else {
				m_instruction = nullptr;
			}
		}
		return *this;
	}

	Perishable::~Perishable() {
		delete[] m_instruction;
		m_instruction = nullptr;
	}

	const Date& Perishable::expiry()const {
		return m_expDate;
	}

	int Perishable::readSku(std::istream& istr) {
		m_sku = ut.getint(10000, 39999, "SKU: ");
		return m_sku;
	}

	ofstream& Perishable::save(ofstream& ofstr)const {
		if (state) {
			Item::save(ofstr);
			ofstr << '\t';
			if (m_instruction != nullptr) {
				ofstr << m_instruction;
			}
			ofstr << '\t';
			Date tempD;
			tempD = m_expDate;
			tempD.formatted(false);
			ofstr << tempD;
				//save it as unformatted form
				//<< m_expDate.dateNoFormat();

		}
		return ofstr;
	}

	ifstream& Perishable::load(ifstream& ifstr) {
		Item::load(ifstr);

		string temp;
		getline(ifstr, temp, '\t');
		ut.alocpy(m_instruction, temp.c_str());

		ifstr >> m_expDate;
		ifstr.ignore();

		if(ifstr.fail()){
			state = "Input file stream read (perishable) failed!";
		}
		else {
			if(!state)
			state.clear();
		}

		return ifstr;
	}

	ostream& Perishable::display(::ostream& ostr)const {
		if (state) {
			if (linear()) {
				Item::display(ostr);
				if (m_instruction != nullptr && m_instruction[0] != '\0') {
					ostr << "*";
				}
				else {
					ostr << " ";
				}
				ostr << m_expDate;
			}
			else {
				ostr << "Perishable ";
				Item::display(ostr);
				ostr << "Expiry date: " << m_expDate << endl;
				if (m_instruction != nullptr && m_instruction[0] != '\0') {
					ostr << "Handling Instructions: " << m_instruction << endl;
				}
			}
		}
		else {
			ostr << state;
		}
		
		return ostr;
	}

	istream& Perishable::read(istream& istr) {
		char temp[1000];
		Item::read(istr);
		delete[] m_instruction;
		m_instruction = nullptr;
		cout << "Expiry date (YYMMDD): ";
		istr >> m_expDate;
		istr.ignore(10000, '\n');
		cout << "Handling Instructions, ENTER to skip: ";
		char first;
		first = istr.peek();
		if (first != '\n') {
			istr.getline(temp, 1000, '\n');
			ut.alocpy(m_instruction, temp);
		}
		else {
			m_instruction = nullptr;
		}

		state.clear();
		if (istr.fail()) {
			istr.ignore(10000, '\n');
			cout << "Perishable console date entry failed!";
		}
		return istr;
	}
}