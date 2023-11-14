#include <cstring>
#include <iostream>
#include "Line.h"

using namespace std;
namespace sdds {
	Line::Line() :LblShape() {
		m_length = 0;
	}

	Line::Line(const char* str, const int length) :LblShape(str) {
		m_length = length;
	}
	void Line::getSpecs(istream& istr) {
		LblShape::getSpecs(istr);
		istr >> m_length;
		istr.ignore(100, '\n');
	}

	void Line::draw(std::ostream& ostr) const {
		if (m_length > 0 && label() != nullptr) {
			ostr << label() << endl;
			for (int i = 0; i < m_length; i++) {
				ostr << "=";
			}
		}
	}
}