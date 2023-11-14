#include <iostream>
#include <iomanip>  // For setw
#include "Rectangle.h"
using namespace std;
namespace sdds {
	Rectangle::Rectangle() :LblShape(){
		m_width = 0;
		m_height = 0;
	}

	Rectangle::Rectangle(const char* label, const int width, const int height) :LblShape(label) {
		m_width = width;
		m_height = height;
	}

	void Rectangle::getSpecs(istream& istr) {
		LblShape::getSpecs(istr);
		istr >> m_width;
		istr.ignore(500, ',');
		istr >> m_height;
		istr.ignore(500, '\n');
	}

	void Rectangle::draw(std::ostream& ostr) const {
		if (m_width - 1 > 0 && m_height > 1) {
			//first line
			ostr << "+";
			for (int i = 0; i < m_width - 2; i++) {
				ostr << "-";
			}
			ostr << "+" << endl;

			//second line
			ostr << '|' << setw(m_width - 2) << left << label() << "|" << endl;

			//In next (m_height - 3) lines
			for (int i = 0; i < m_height - 3; i++) {
				ostr << "|";
				for (int i = 0; i < m_width - 2; i++) {
					ostr << " ";
				}
				ostr << "|" << endl;
			}

			//last line
			ostr << "+";
			for (int i = 0; i < m_width - 2; i++) {
				ostr << "-";
			}
			ostr << "+";
		}
	}
}