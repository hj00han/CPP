/***********************************************************************
Name : Hyunjoo Han
Email : hhan39@myseneca.ca
ID : 132749227
Date of completion : 11/24/2023

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
***********************************************************************/
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
