#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Container.h"

using namespace std;

namespace sdds {
	Container::Container(const char* content, int capacity, int volume) {
		if (content == nullptr || volume > capacity) {
			m_content[0] = '\0';
		}
		else {
			strcpy(m_content, content);
			m_capacity = capacity;
			m_volume = volume;
		}
	}

	int Container::operator +=(int volume) {
		int addedVol;
		if (m_capacity - m_volume >= volume) {//check if there is enough capacity
			m_volume += volume;
			addedVol = volume;
		}
		else {
			m_volume = m_capacity;
			addedVol = m_capacity - m_volume;
		}
		return addedVol;
	}

	int Container::operator -=(int volume) {
		int deductedVol;
		if (m_volume >= volume) {//check if there is enough volume
			m_volume -= volume;
			deductedVol = volume;
		}
		else {
			m_volume = 0;
			deductedVol = m_volume;
		}
		return deductedVol;
	}
	Container::operator bool() const {
		return m_content[0] != '\0';
	}
	void Container::clear(int capacity, const char* content) {
		if (capacity > 0 && content != nullptr && content[0] != '\0') {
			m_capacity = capacity;
			strcpy(m_content, content);
		}
	}
	std::ostream& Container::print(std::ostream& ostr) {
		if (this) {
			ostr << m_content <<": (" << m_volume << "cc / " << m_capacity << ")";
		}
		else {
			ostr << "****: (**cc/***)";
		}
		return ostr;
	}

	void Container::setEmpty() {
		m_content[0] = '\0';
		m_capacity = 0;
		m_volume = 0;
	}

	int Container::capacity() const{
		return m_capacity;
	}

	int Container::volume() const {
		return m_volume;
	}
}