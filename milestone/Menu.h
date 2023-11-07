/***********************************************************************
Final Project Milestone 2
Name : Hyunjoo Han
Email : hhan39@myseneca.ca
ID : 132749227
Date of completion : 11/02/2023

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef _MENU_H_
#define _MENU_H_
namespace sdds {
	const int MAX_ITEM = 15;
	class Menu {
		char* m_menContent;
		int m_numOfOption;
		bool m_valid;
	public:
		int countOptions(const char* menContent) const; //Functions to count number of options
		Menu();
		Menu(const char* menContent);
		Menu(const Menu& menu);
		Menu& operator =(const Menu& menu);
		~Menu();
		unsigned int run() const;
	};
}
#endif