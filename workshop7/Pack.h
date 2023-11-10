/***********************************************************************
Name : Hyunjoo Han
Email : hunjoo.han25@gmail.com
***********************************************************************/
#ifndef _PACK_H_
#define _PACK_H_
#include "Container.h"

namespace sdds {
	class Pack : public Container {
		int m_unitSize;//size of a unit
	public:
		Pack(const char* content, int capacity, int unitSize = 330, int volume = 0);
		int operator +=(int numOfUnits);
		int operator -=(int numOfUnits);
		int unit() const;
		int noOfUnits() const;
		int size() const;
		void clear(int size, int unitSize, const char* content);
		std::ostream& print(std::ostream& ostr) const;
		std::istream& read(std::istream& istr);
		friend std::ostream& operator <<(std::ostream& ostr, Pack& pack);
		friend std::istream& operator >>(std::istream& istr, Pack& pack);
	};
}
#endif