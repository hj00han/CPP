/***********************************************************************
Final Project Milestone 51
Name : Hyunjoo Han
Email : hhan39@myseneca.ca
ID : 132749227
Date of completion : 11/29/2023

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef _AIDMAN_H_
#define _AIDMAN_H_

#include "Menu.h"
#include "Date.h"
#include "iProduct.h"

namespace sdds {
	const int sdds_max_num_items = 100;

	class AidMan {
		char* m_fileName{};
		int m_noOfProduct;
		Menu m_Menu;
		Date date;//To print date
		unsigned int menu() const;
		iProduct* m_iproduct[sdds_max_num_items]{};
	public:
		AidMan(const char* fileName = nullptr);
		AidMan(const AidMan& aidMan) = delete;
		AidMan& operator =(const AidMan& aidMan) = delete;
		virtual ~AidMan();
		void run();
		void save();
		void deallocate();
		void load();
		int list(const char* sub_desc = nullptr);

	};
}
#endif