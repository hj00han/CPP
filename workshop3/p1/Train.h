#ifndef SDDS_Train_H 
#define SDDS_Train_H

#define MIN_TIME 700
#define MAX_TIME 2300
#define MAX_NO_OF_PASSENGER 1000

namespace sdds {

	class Train {
		char* trainName;
		int noOfPassenger;
		int departureTime;
		
	public:
		void initialize();
		bool validTime(int value)const;
		bool validNoOfPassengers(int value)const;
		void set(const char* name);
		void set(int noOfPassengers, int departure);
		void set(const char* name, int noOfPassengers, int departure);
		void finalize();
		bool isInvalid()const;
		int noOfPassengers() const;
		const char* getName() const;
		int getDepartureTime() const;
		void display() const;

	};
}
#endif
