/***********************************************************************
Name : Hyunjoo Han
Email : hhan39@myseneca.ca
ID : 132749227
Date of completion : 10/09/2023

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
***********************************************************************/

#ifndef SDDS_LabelMaker_H 
#define SDDS_LabelMaker_H
#include "Label.h"

namespace sdds {
	class LabelMaker {
		Label* labels;
		int m_noOfLabels;
	public:
		LabelMaker(int noOfLabels);
		~LabelMaker();
		void readLabels();
		void printLabels();		
	};
}
#endif