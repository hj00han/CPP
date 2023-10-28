/***********************************************************************
Name : Hyunjoo Han
Email : hhan39@myseneca.ca
ID : 132749227
Date of completion : 10/09/2023

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "LabelMaker.h"

using namespace std;

namespace sdds {
	LabelMaker::LabelMaker(int noOfLabels) {
		m_noOfLabels = noOfLabels; //assigning value to the member variable
		labels = new Label[m_noOfLabels]; //allocate dynamic memory with size of the argument
	}

	LabelMaker::~LabelMaker() {
		delete[] labels;
		labels = nullptr;
	}
	void LabelMaker::readLabels() {
		cout << "Enter " << m_noOfLabels << " labels:" << endl;
		for (int i = 0; i < m_noOfLabels; i++) { //Repeating reading the label depends on number of lines 
			cout << "Enter label number " << i + 1 << endl << "> ";
			labels[i].readLabel(); //read Labels by calling function from 'Label' module.
		}		
	}

	void LabelMaker::printLabels() {
		for (int i = 0; i < m_noOfLabels; i++) {
			labels[i].printLabel(); //print Lables by calling function from 'Label' module.
			cout << endl;
		}
	}
}