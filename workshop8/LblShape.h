#ifndef _LBLSHAPE_H_
#define _LBLSHAPE_H_
#include "Shape.h"
namespace sdds {
	class LblShape :public Shape {
		char* m_label = nullptr;
	protected:
		const char* label() const;
	public:
		LblShape();
		LblShape(const char* label);
		~LblShape();
		LblShape(const LblShape& lblShape) = delete;
		LblShape& operator=(const LblShape& lblShape) = delete;
		void getSpecs(std::istream& istr);
		void safeStrCpy(const char* copy);
	};
}
#endif // !_LBLSHAPE_H_
