#ifndef _AIDMAN_H_
#define _AIDMAN_H_

#include "Menu.h"
#include "Date.h"
#include "iProduct.h"

namespace sdds {
	const int sdds_max_num_items = 100;

	class AidMan {
		char* m_fileName{};
		int m_noOfProduct;
		Menu m_Menu;
		Date date;//To print date
		unsigned int menu() const;
		iProduct* m_iproduct[sdds_max_num_items]{};
	public:
		AidMan(const char* fileName = nullptr);
		AidMan(const AidMan& aidMan) = delete;
		AidMan& operator =(const AidMan& aidMan) = delete;
		virtual ~AidMan();
		void run();
		void save();
		void deallocate();
		void load();
		void listDetails();
		int list(const char* sub_desc = nullptr);
		int search(int sku) const;
		void addItem();
		void remove(int index);
		void removeItem();
		void updateQty();
	};
}
#endif
