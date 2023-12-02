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
