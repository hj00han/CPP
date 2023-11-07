#ifndef _MENU_H_
#define _MENU_H_
namespace sdds {
	const int MAX_ITEM = 15;
	class Menu {
		char* m_menContent;
		Menu(char* menContent);
		Menu(const Menu& menu);
		Menu& operator =(const Menu& menu);
		~Menu();
	public:
		unsigned int run() const;
	};
}
#endif