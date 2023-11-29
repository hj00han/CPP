/***********************************************************************
Name : Hyunjoo Han
Email : hhan39@myseneca.ca
ID : 132749227
Date of completion : 11/18/2023

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef _MENU_H_
#define _MENU_H_

namespace sdds {
	const int MAX_ITEM = 15;
	class Menu {
		char* m_menContent{};
		int m_numOfOption;
	public:
		Menu(const char* menContent = nullptr);
		Menu(const Menu&) = delete;
		Menu& operator =(const Menu&) = delete;
		~Menu();
		unsigned int run() const;
		//type conversion operator
		operator bool() const;
		//Initialize m_menContent
		void content(const char* menContent);
	};
	//helper function; counting the tab and returns number of options
	int countOptions(const char* menContent);
	//helper function; format the menu and display
	void displayMenu(const char* menContent, int numOfOptions);
}
#endif