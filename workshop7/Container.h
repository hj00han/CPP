#ifndef _CONTAINER_H_
#define _CONTAINER_H_

namespace sdds {
	class Container {
		char m_content[50] = {};
		int m_capacity;
		int m_volume;
		//bool m_valid;
	public:
		Container(const char* content, int capacity, int volumne = 0);
		int operator +=(int volume);
		int operator -=(int volume);
		operator bool() const;
		void clear(int capacity, const char* content);
		std::ostream& print(std::ostream& ostr);
	protected:
		void setEmpty();
		int capacity() const;
		int volume() const;
	};
}
#endif