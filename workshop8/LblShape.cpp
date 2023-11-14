#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "LblShape.h"
using namespace std;
namespace sdds {
	const char* LblShape::label() const {
		return m_label;
	}

	LblShape::LblShape() {
		if (m_label != nullptr) {
			m_label = nullptr;
		}
	}

	LblShape::LblShape(const char* label) {
		if (label != nullptr) {
			this->safeStrCpy(label);
		}
	}

	LblShape::~LblShape() {
		delete[] m_label;
		m_label = nullptr;
	}

	void LblShape::getSpecs(istream& istr) {
		char label[500];
		istr.get(label, 100, ',');
		istr.ignore();
		this->safeStrCpy(label);
	}

	void LblShape::safeStrCpy(const char* src) {
		if (m_label != nullptr) {
			delete[] m_label;
			m_label = nullptr;
		}
		m_label = new char[strlen(src) + 1];
		strcpy(m_label, src);
	}
}