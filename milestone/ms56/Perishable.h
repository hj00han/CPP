#ifndef _PERISHABLE_H_
#define _PERISHABLE_H_
#include "Item.h"
#include "Date.h"

namespace sdds {
	class Perishable :public Item {
		Date m_expDate;
		char* m_instruction;
	public:
		Perishable();
		Perishable(const Perishable& perishable);
		Perishable& operator=(const Perishable& perishable);
		virtual ~Perishable();
		const Date& expiry()const;
		int readSku(std::istream& istr);
		std::ofstream& save(std::ofstream& ofstr)const;
		std::ifstream& load(std::ifstream& ifstr);
		std::ostream& display(std::ostream& ostr)const;
		std::istream& read(std::istream& istr);
	};
}
#endif // !_PERISHABLE_H_
