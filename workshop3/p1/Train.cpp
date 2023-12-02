#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include"Train.h"

using namespace std;

namespace sdds {
	void Train::initialize() {
		trainName = nullptr;
		noOfPassenger = -1;
		departureTime = -1;
	}
	
	bool Train::validTime(int value)const {
		bool valid = false;
		if (value > MIN_TIME && value < MAX_TIME && (value % 100) <= 59) {
			valid = true;
		}
		return valid;
	}
	
	bool Train::validNoOfPassengers(int value)const {
		bool valid = false;
		if (value > 0 && value < MAX_NO_OF_PASSENGER) {
			valid = true;
		}			
		return valid;
	}
	
	void Train::set(const char* name) {
		delete[] trainName;
		trainName = nullptr;
		if (name != nullptr && strlen(name) > 0) {
			trainName = new char[strlen(name) + 1];
			strcpy(this->trainName, name);
		}
	}
	
	void Train::set(int noOfPassengers, int departure) {
		if (validNoOfPassengers(noOfPassengers) && validTime(departure)) {
			this->noOfPassenger = noOfPassengers;
			this->departureTime = departure;
		}
		else {
			this->noOfPassenger = -1;
			this->departureTime = -1;
		}
	}
	
	void Train::set(const char* name, int noOfPassengers, int departure) {
		
		delete[] trainName;
		trainName = nullptr;
		//check all the argumnets are valid. Initialize them only when all of 3 argumnets are valid
		if (name != nullptr && strlen(name) > 0 && validNoOfPassengers(noOfPassengers) && validTime(departure)) {
			trainName = new char[strlen(name) + 1];
			strcpy(this->trainName, name);
			this->noOfPassenger = noOfPassengers;
			this->departureTime = departure;
		}
		//if any of argumnets is not valid, initialize it with default values.
		else {
			initialize();
		}
	}
	
	void Train::finalize() {
		delete[] trainName;
		trainName = nullptr;
	}
	
	bool Train::isInvalid()const {
		bool invalid = true;
		if (validTime(departureTime) && validNoOfPassengers(noOfPassenger) && trainName != nullptr) {
			invalid = false;
		}
		return invalid;
	}
	
	int Train::noOfPassengers() const {
		return noOfPassenger;
	}
	
	const char* Train::getName() const {
		return trainName;
	}

	int Train::getDepartureTime() const {
		return departureTime;
	}
	
	void Train::display() const {
		if (!isInvalid()) {
			cout << "NAME OF THE TRAIN:    " << trainName << endl
				<< "NUMBER OF PASSENGERS: " << noOfPassenger << endl
				<< "DEPARTURE TIME:       " << departureTime << endl;
		}
		else {
			cout << "Train in an invalid State!"<<endl;
		}
	}
}
