/***********************************************************************
Name : Hyunjoo Han
Email : hhan39@myseneca.ca
ID : 132749227
Date of completion : 11/18/2023

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef _IPRODUCT_H_
#define _IPRODUCT_H_

namespace sdds {
	class iProduct {
	public:
		virtual ~iProduct() {};
		// to read the Stock-Keeping Unit from the console before
		// main data entry
		virtual int readSku(std::istream& istr) = 0;
		// to reduce the quantity on hand
		virtual int operator-=(int qty) = 0;
		// to increase the quantity on hand
		virtual int operator+=(int qty) = 0;
		// returns the price of the produce
		virtual operator double()const = 0;
		// returns if the iProduct is in a good state
		virtual operator bool()const = 0;
		// returns the number of products needed
		virtual int qtyNeeded()const = 0;
		// returns the quantity on hand
		virtual int qty()const = 0;
		// determines if the iProduct is displayed in a linear format or 
		// descriptive format
		virtual void linear(bool isLinear) = 0;
		// saves the iProduct into a file
		virtual std::ofstream& save(std::ofstream& ofstr)const = 0;
		// loads an iProduct from a file
		virtual std::ifstream& load(std::ifstream& ifstr) = 0;
		// displays the iProduct on the screen
		virtual std::ostream& display(std::ostream& ostr)const = 0;
		// reads the iProduct from the console
		virtual std::istream& read(std::istream& istr) = 0;
		// return true if the SKU is a match to the iProduct's SKU
		virtual bool operator==(int sku)const = 0;
		// returns true if the description is found in the iPorduct's description
		virtual bool operator==(const char* description)const = 0;
	};
	std::ostream& operator<<(std::ostream& ostr, const iProduct& ipr);
	std::istream& operator>>(std::istream& istr, iProduct& ipr);

}
#endif // !_IPRODUCT_H_
