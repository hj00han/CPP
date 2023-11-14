#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_
#include "LblShape.h"

namespace sdds {
	class Rectangle :public LblShape {
		int m_width;
		int m_height;
	public:
		Rectangle();
		Rectangle(const char* label, const int width, const int height);
		void getSpecs(std::istream& istr);
		void draw(std::ostream& ostr) const;
	};
}
#endif // !_RECTANGLE_H_
