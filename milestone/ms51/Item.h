/***********************************************************************
Final Project Milestone 51
Name : Hyunjoo Han
Email : hhan39@myseneca.ca
ID : 132749227
Date of completion : 11/29/2023

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef _ITEM_H_
#define _ITEM_H_
#include "iProduct.h"
#include "Status.h"

namespace sdds {
	class Item :public iProduct {
		double m_price;
		int m_qty;
		int m_qtyNeeded;
		char* m_desc = nullptr;
		bool m_isLinear;
	protected:
		Status state;
		int m_sku{};
		bool linear() const;
	public:
		Item();
		Item(const Item& item);
		Item& operator=(const Item& item);
		virtual ~Item();
		int qtyNeeded()const;
		int qty()const;
		operator double()const;
		operator bool()const;
		int operator-=(int qty);
		int operator+=(int qty);
		void linear(bool isLinear);
		bool operator==(int sku)const;
		bool operator==(const char* desc)const;
		std::ofstream& save(std::ofstream& ofstr)const;
		std::ifstream& load(std::ifstream& ifstr);
		std::ostream& display(std::ostream& ostr)const;
		int readSku(std::istream& istr);
		std::istream& read(std::istream& istr);
		void clear();
	};
}

#endif