/***********************************************************************
Name : Hyunjoo Han
Email : hhan39@myseneca.ca
ID : 132749227
Date of completion : 11/22/2023

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef _STUDENT_H_
#define _STUDENT_H_

namespace sdds {
	class Student {
		char* m_name;
		int m_age;
	public:
		Student();
		Student(const char* name, int age);
		Student(const Student& student);
		Student& operator=(const Student& student);
		//Virtual destructor ensures that the destructor of the most derived class is called first, 
		//followed by the destructors of each base class in the inheritance hierarchy. 
		//This ensures that all resources are properly released in the correct order.
		virtual ~Student();
		void display();
	};
}
#endif // !_STUDENT_H_
