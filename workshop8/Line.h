#ifndef _LINE_H_
#define _LINE_H_
#include "LblShape.h"

namespace sdds {
	class Line :public LblShape {
		int m_length;
	public:
		Line();
		Line(const char* str, const int length);
		void getSpecs(std::istream& istr);
		void draw(std::ostream& ostr) const;
	};
}
#endif // !_LINE_H_
