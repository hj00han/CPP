/***********************************************************************
Name : Hyunjoo Han
Email : hhan39@myseneca.ca
ID : 132749227
Date of completion : 11/09/2023

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef _CONTAINER_H_
#define _CONTAINER_H_

namespace sdds {
	class Container {
		char m_content[50] = {};
		int m_capacity;
		int m_volume;
	protected:
		void setEmpty();
		int capacity() const;
		int volume() const;
	public:
		Container(const char* content, int capacity, int volumne = 0);
		int operator +=(int volume);
		int operator -=(int volume);
		operator bool() const;
		void clear(int capacity, const char* content);
		std::ostream& print(std::ostream& ostr) const;
		std::istream& read(std::istream& istr);
		friend std::ostream& operator <<(std::ostream& ostr, Container& container);
		friend std::istream& operator >>(std::istream& istr, Container& container);
	};
}
#endif