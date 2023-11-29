/***********************************************************************
Name : Hyunjoo Han
Email : hhan39@myseneca.ca
ID : 132749227
Date of completion : 11/24/2023

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include "Item.h"
#include "Utils.h"

using namespace std;

namespace sdds {
	bool Item::linear() const {
		return m_isLinear;
	}

	Item::Item()  {
		m_price = 0;
		m_qty = 0;
		m_qtyNeeded = 0;
		m_desc = nullptr;
		m_isLinear = false;
		m_sku = 0;
		state = "false";
	}

	Item::Item(const Item& item) {
		//*this = item;
		if (this != &item) {
			m_price = item.m_price;
			m_qty = item.m_qty;
			m_qtyNeeded = item.m_qtyNeeded;
			if (item.m_desc != nullptr) {
				m_desc = new char[strlen(item.m_desc) + 1];
				strcpy(m_desc, item.m_desc);
			}
			else {
				m_desc = nullptr;
			}
			m_isLinear = item.m_isLinear;
			state = item.state;
			m_sku = item.m_sku;
		}
	}

	Item& Item::operator=(const Item& item) {
		if (this != &item) {
			m_price = item.m_price;
			m_qty = item.m_qty;
			m_qtyNeeded = item.m_qtyNeeded;
			m_isLinear = item.m_isLinear;
			state = item.state;
			m_sku = item.m_sku;
			if (item.m_desc != nullptr) {
				ut.alocpy(m_desc, item.m_desc);
			}
			else {
				m_desc = nullptr;
			}
		}
		return *this;
	}

	Item::~Item() {
		delete[] m_desc;
		m_desc = nullptr;
	}

	int Item::qtyNeeded()const {
		return m_qtyNeeded;
	}

	int Item::qty()const {
		return m_qty;
	}

	Item::operator double()const {
		return m_price;
	}

	Item::operator bool()const {
		return state;
	}

	int Item::operator-=(int qty) {
		return m_qty -= qty;
	}

	int Item::operator+=(int qty) {
		return m_qty += qty;
	}

	void Item::linear(bool isLinear) {
		m_isLinear = isLinear;
	}

	void Item::clear() {
		m_price = 0;
		m_qty = 0;
		m_qtyNeeded = 0;
		m_isLinear = false;
		state = false;
		m_sku = 0;
		delete[] m_desc;
		m_desc = nullptr;
	}

	bool Item::operator==(int sku)const {
		return m_sku == sku;
	}

	bool Item::operator==(const char* desc)const {
		return strstr(m_desc, desc);
	}

	ofstream& Item::save(ofstream& ofstr)const {
		if (state) {
			ofstr << m_sku << '\t'
				<< m_desc << '\t'
				<< m_qty << '\t'
				<< m_qtyNeeded << '\t';
			ofstr << fixed << setprecision(2) << m_price;
		}
		return ofstr;
	}

	ifstream& Item::load(ifstream& ifstr) {
		ifstr >> m_sku;
		ifstr.ignore();

		string temp; //to get unkown length of charactor
		getline(ifstr, temp, '\t');
		ut.alocpy(m_desc, temp.c_str());//convert string to cstring and alocpy
		
		ifstr >> m_qty;
		ifstr.ignore();
		ifstr >> m_qtyNeeded;
		ifstr.ignore();
		ifstr >> m_price;
		ifstr.ignore(100,'\t');
		
		if (!ifstr) {
			state = "Input file stream read failed!";
		}
		else {
			if (!state) {
				state.clear();
			}
		}
		return ifstr;

	}

	ostream& Item::display(::ostream& ostr)const {
		if (state) {
			if (m_isLinear) {
				ostr<<setw(5);
				ostr << m_sku << " | ";
				char desc[36]{};
				if (m_desc) {
					strncpy(desc, m_desc,35);
					desc[35] = '\0';
				}//????????????
				ostr<< left << setfill(' ') << setw(35) << desc << " | "
					<< right << setfill(' ') << setw(4) << m_qty << " | "
					<< right << setfill(' ') << setw(4) << m_qtyNeeded << " | "
					<< right << setfill(' ') << setw(7) << m_price << " |";
			}
			else {
				double neededFund = (qtyNeeded() - qty()) * (double)*this;
				ostr << "AMA Item:" << endl
					<< m_sku << ": " << m_desc << endl
					<< "Quantity Needed: " << m_qtyNeeded << endl
					<< "Quantity Available: " << m_qty << endl
					<< "Unit Price: $" << fixed << setprecision(2) << m_price << endl
					<< "Needed Purchase Fund: $" << neededFund << endl;
			}
		}
		else {
			ostr << state;
		}
		return ostr;
	}

	int Item::readSku(std::istream& istr) {
		m_sku = ut.getint(40000, 99999, "SKU: ");
		return m_sku;
	}

	istream& Item::read(istream& istr) {
		delete[] m_desc;
		m_desc = nullptr;
		state.clear();
		string temp; //to get unkown length of charactor 
		cout << "AMA Item:" << endl
			<< "SKU: " << m_sku << endl
			<< "Description: ";
		istr.ignore();
		getline(istr, temp, '\n');
		ut.alocpy(m_desc, temp.c_str());//convert string to cstring and alocpy
		m_qtyNeeded = ut.getint(1, 9999, "Quantity Needed: ");
		m_qty = ut.getint(0, m_qtyNeeded, "Quantity On Hand: ");
		m_price = ut.getDouble(0, 9999, "Unit Price: $");
		if (!istr) {
			state = "Console entry failed!";
		}
		else {
			if (state != nullptr) {
				state.clear();
			}
		}
		return istr;
	}
}