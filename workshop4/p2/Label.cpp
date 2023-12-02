#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <cstring>
#include "Label.h"

using namespace std;

namespace sdds {
	Label::Label() {
		strcpy(m_frame, "+-+|+-+|");
		m_text = nullptr;
	}

	Label::Label(const char* framArg) {
		if (framArg != nullptr) {
			strcpy(m_frame, framArg);
			m_text = nullptr;
		}
		else {
			Label();
		}
	}

	Label::Label(const char* framArg, const char* content) {
		strcpy(m_frame, framArg);
		if (strlen(content) <= MAX_TEXT) {
			m_text = new char[strlen(content) + 1];
			strcpy(m_text, content);
		}
	}

	Label::~Label() {
		delete[] m_text;
		m_text = nullptr;
	}

	istream& Label::readLabel() {
		char content[MAX_TEXT + 1];
		cin.getline(content, MAX_TEXT + 1); //limit the input size of 70 + 1(\0)
		m_text = new char[strlen(content) + 1];
		strcpy(m_text, content);
		m_text[strlen(content)] = '\0';
		return cin;
	}

	std::ostream& Label::printLabel()const {
		if (m_text != nullptr) {
			//Top line of Frame
			cout << m_frame[0];
			for (int i = 0; i < (int)strlen(m_text) + 2; i++)
				cout << m_frame[1];
			cout << m_frame[2] << endl;

			//Second line of Frame
			cout << m_frame[7];
			for (int i = 0; i < (int)strlen(m_text) + 2; i++)
				cout << ' ';
			cout << m_frame[3] << endl;

			//Third line of Frame with one-line text in it
			cout << m_frame[7] << ' ' << m_text << ' ' << m_frame[3] << endl;

			//Fourth line(same as Second)
			cout << m_frame[7];
			for (int i = 0; i < (int)strlen(m_text) + 2; i++)
				cout << ' ';
			cout << m_frame[3] << endl;

			//Fifth line
			cout << m_frame[6];
			for (int i = 0; i < (int)strlen(m_text) + 2; i++)
				cout << m_frame[5];
			cout << m_frame[4];
		}
		return cout;
	}

	Label& Label::text(const char* content) {
		if (strlen(content) <= 70) {
			m_text = new char[strlen(content) + 1];
			strcpy(m_text, content);
		}
		return *this;
	}
}
