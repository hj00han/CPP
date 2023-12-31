#ifndef _DATE_H_
#define _DATE_H_

#include "Status.h"

namespace sdds {
	const int MAX_YEAR = 2030;

	class Date {
		int Year;
		int Month;
		int Day;
		bool Formatted;
		bool validated; //Additional member variable to indicate if date variables are valid
		Status State;
		bool validate();
		int uniqueDateValue() const;
	public:
		Date();
		Date(int year, int month, int day);
		int dateNoFormat()const;//custom function
		bool operator ==(const Date& date) const;
		bool operator !=(const Date& date) const;
		bool operator <(const Date& date) const;
		bool operator >(const Date& date) const;
		bool operator <=(const Date& date) const;
		bool operator >=(const Date& date) const;
		operator bool() const;
		const Status& state() const;
		Date& formatted(const bool format);
		std::ostream& write(std::ostream& ostr) const;
		std::istream& read(std::istream& istr);
	};
	std::ostream& operator<<(std::ostream& ostr, const Date& date);
	std::istream& operator>>(std::istream& istr, Date& date);
}
#endif
