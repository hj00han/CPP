/***********************************************************************
Name : Hyunjoo Han
Email : hhan39@myseneca.ca
ID : 132749227
Date of completion : 11/24/2023

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef _STATUS_H_
#define _STATUS_H_
namespace sdds {
	class Status {
		char* m_statDesc{};
		int m_statCode{};
	public:
		Status(const char* statDesc = nullptr);
		Status(const Status& status);
		Status& operator =(const Status& status);
		~Status();
		Status& operator =(const char* statDesc);
		Status& operator =(int statCode);
		operator int() const;
		operator const char* () const;
		operator bool() const;
		Status& clear();
		friend std::ostream& operator <<(std::ostream& ostr, const Status& status);
	};
}
#endif