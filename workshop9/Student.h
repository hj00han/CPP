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
