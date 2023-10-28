/***********************************************************************
Name : Hyunjoo Han
Email : hhan39@myseneca.ca
ID : 132749227
Date of completion : 9/26/2023

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
***********************************************************************/

/***********************************************************************
// OOP244 Workshop #2 DIY (part 2):
//
// File  Population.h
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//   To completed by students
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
***********************************************************************/#ifndef SDDS_POPULATION_H_

#define SDDS_POPULATION_H_

namespace sdds {

	struct Population {
		char postalCode[3];
		int population;
	};

	bool startsWith(const char* cString, const char* subString);
	void sort();
	bool getPostalCode(char* postal_code_prefix);
	bool load(Population& population);
	bool load(const char* filename, const char* partial_postal_code_prefix);
	void display(const Population population);
	void display();
	void deallocateMemory();



}
#endif // SDDS_POPULATION_H_