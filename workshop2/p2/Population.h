#ifndef SDDS_POPULATION_H_
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
