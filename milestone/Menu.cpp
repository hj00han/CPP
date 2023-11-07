#include "Menu.h"

using namespace std;
namespace sdds {
	Menu::Menu(char* menContent) {

	}

	Menu::~Menu() {
		delete[] m_menContent;
		m_menContent = nullptr;
	}
}