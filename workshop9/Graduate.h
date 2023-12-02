#ifndef _GRADUATE_H_
#define _GRADUATE_H_
#include "Student.h"

namespace sdds {
	class Graduate :public Student {
		char* m_supervisor;
		char* m_thesisTitle;
	public:
		Graduate();
		Graduate(const char* name, int age, const char* thesisTitle, const char* supervisor);
		Graduate(const Graduate& graduate);
		Graduate& operator=(const Graduate& graduate);
		//Virtual destructor ensures that the destructor of the most derived class is called first, 
		//followed by the destructors of each base class in the inheritance hierarchy. 
		//This ensures that all resources are properly released in the correct order.
		virtual ~Graduate();
		void display();
	};
}
#endif // !_GRADUATE_H_
