/***********************************************************************
Name : Hyunjoo Han
Email : hhan39@myseneca.ca
ID : 132749227
Date of completion : 11/24/2023

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "iProduct.h"

using namespace std;

namespace sdds {
	ostream& operator<<(ostream& ostr, const iProduct& ipr) {
		return ipr.display(ostr);
	}

	istream& operator>>(istream& istr, iProduct& ipr) {
		return ipr.read(istr);
	}
}
