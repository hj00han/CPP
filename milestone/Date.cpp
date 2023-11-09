/***********************************************************************
Final Project Milestone 2
Name : Hyunjoo Han
Email : hhan39@myseneca.ca
ID : 132749227
Date of completion : 11/09/2023

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Date.h"
#include "Utils.h"

using namespace std;
namespace sdds {
	bool Date::validate() {
		bool valid = false;
		int currYear;
		State.clear();
		ut.getSystemDate(&currYear); //Get Current year by using function of Utils module
		if (Year<currYear || Year>MAX_YEAR) {
			//Set State member variables by using assignment operator overload
			State = "Invalid year in date";
			State = 1;
		}
		else if (Month < 1 || Month>12) {
			State = "Invalid month in date";
			State = 2;
		}
		else if (Day<1 || Day > ut.daysOfMon(Month, Year)) {
			State = "Invalid day in date";
			State = 3;
		}
		else {
			valid = true;
		}
		return valid;
	}

	int Date::uniqueDateValue() const {
		return Year * 372 + Month * 31 + Day;
	}

	Date::Date() {
		//No arguemnt = Current date
		//Using a function from Utils module
		ut.getSystemDate(&Year, &Month, &Day);
		Formatted = true;
	}

	Date::Date(int year, int month, int day) {
		Year = year;
		Month = month;
		Day = day;
		Formatted = true;
		validated = validate();
	}

	bool Date::operator ==(const Date& date) const {
		return this->uniqueDateValue() == date.uniqueDateValue();
	}

	bool Date::operator !=(const Date& date) const {
		return this->uniqueDateValue() != date.uniqueDateValue();
	}

	bool Date::operator <(const Date& date) const {
		return this->uniqueDateValue() < date.uniqueDateValue();
	}

	bool Date::operator >(const Date& date) const {
		return this->uniqueDateValue() > date.uniqueDateValue();
	}

	bool Date::operator <=(const Date& date) const {
		return this->uniqueDateValue() <= date.uniqueDateValue();
	}

	bool Date::operator >=(const Date& date) const {
		return this->uniqueDateValue() >= date.uniqueDateValue();
	}

	Date::operator bool() const {
		return State;
	}

	const Status& Date::state() const {
		return State;
	}

	Date& Date::formatted(const bool format) {
		Formatted = format;
		return *this;
	}

	std::ostream& Date::write(std::ostream& ostr) const {
		if (Formatted)
		{
			ostr << Year;
			ostr << '/';
			ostr.fill('0');
			ostr.width(2);
			ostr << Month;
			ostr << '/';
			ostr.width(2);
			ostr.fill('0');
			ostr << Day;
		}
		else
		{
			ostr << Year % 100;
			ostr.fill('0');
			ostr.width(2);
			ostr << Month;
			ostr.width(2);
			ostr.fill('0');
			ostr << Day;
		}
		return ostr;
	}

	std::istream& Date::read(std::istream& istr) {
		int inputDate;
		istr >> inputDate;

		if (istr) {
			int day = inputDate % 100;
			int month = inputDate / 100 % 100;
			int year = inputDate / 10000 + 2000;
			if (inputDate < 10000) {
				ut.getSystemDate(&year);
				*this = Date(year, month, day);//Using Constructor with argument to assign the values and also validate them
			}
			else if (inputDate > 99999 && inputDate < 1000000) {
				*this = Date(year, month, day);
			}
		}
		else {
			State = "Invalid date value";
			validated = false;
		}

		if (!validated) { //Check if reading input was unsucessful or vaidition was failed
			istr.setstate(ios::badbit);
		}

		return istr;
	}

	std::ostream& operator<<(std::ostream& ostr, const Date& date) {
		return date.write(ostr);
	}

	std::istream& operator>>(std::istream& istr, Date& date) {
		return date.read(istr);
	}
}