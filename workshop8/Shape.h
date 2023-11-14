#ifndef _SHAPE_H_
#define _SHAPE_H_

namespace sdds {
	class Shape {
	public:
		virtual void draw(std::ostream& ostr) const = 0;
		virtual void getSpecs(std::istream& istr) = 0;
		virtual ~Shape() {};
	};
	std::ostream& operator<<(std::ostream & ostr, const Shape& shape);
	std::istream& operator>>(std::istream& istr, Shape& shape);

}
#endif // !_SHAPE_H_
