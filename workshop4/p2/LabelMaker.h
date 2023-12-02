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
