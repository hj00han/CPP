/***********************************************************************
Final Project Milestone 2
Name : Hyunjoo Han
Email : hhan39@myseneca.ca
ID : 132749227
Date of completion : 11/02/2023

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef _AIDMAN_H_
#define _AIDMAN_H_

#include "Menu.h"

namespace sdds {
	class AidMan {
		char* m_fileName;
		Menu m_Menu;
		unsigned int menu() const;
	public:
		AidMan(const char* fileName);
		AidMan(const AidMan& aidMan);
		AidMan& operator =(const AidMan& aidMan);
		~AidMan();
		void run();
	};
}
#endif