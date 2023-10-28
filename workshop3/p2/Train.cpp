/***********************************************************************
Name : Hyunjoo Han
Email : hhan39@myseneca.ca
ID : 132749227
Date of completion : 10/02/2023

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
***********************************************************************/
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
		if (value >= MIN_TIME && value <= MAX_TIME && (value % 100) <= 59) {
			valid = true;
		}
		return valid;
	}

	bool Train::validNoOfPassengers(int value)const {
		bool valid = false;
		if (value > 0 && value <= MAX_NO_OF_PASSENGER) {
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
		//edited to calling these functions
        //with my previous logic, it would initialize all of 3 datas empty when one is not valid.
        //Initially(for part1), I called two set functions as well but it caused memory leak.
        //However it doesn't for part 2.
        set(name);
		set(noOfPassengers, departure);
        
        //previous logig below
        
		//delete[] trainName;
		//trainName = nullptr;
		////check all the argumnets are valid. Initialize them only when all of 3 argumnets are valid
		//if (name != nullptr && strlen(name) > 0 && validNoOfPassengers(noOfPassengers) && validTime(departure)) {
		//	trainName = new char[strlen(name) + 1];
		//	strcpy(this->trainName, name);
		//	this->noOfPassenger = noOfPassengers;
		//	this->departureTime = departure;
		//}
		////if any of argumnets is not valid, initialize it with default values.
		//else {
		//	initialize();
		//}
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
			cout << "Train in an invalid State!" << endl;
		}
	}

	bool Train::load(int& unboarded) {
		int boarding = 0;
		bool allboarded = true;
		int capacity = MAX_NO_OF_PASSENGER - noOfPassenger;
		cout << "Enter number of passengers boarding:" << endl << "> ";
		cin >> boarding;

		if (boarding > capacity) {
			unboarded = boarding - capacity;
			noOfPassenger = MAX_NO_OF_PASSENGER;
			allboarded = false;
		}
		else if (boarding <= capacity) {
			unboarded = 0;
			noOfPassenger += boarding;
		}

		return allboarded;
	}

	bool Train::updateDepartureTime() {
		bool success = false;
		int newDeparture;
		cout << "Enter new departure time:" << endl << "> ";
		cin >> newDeparture;
		if (validTime(newDeparture)) {
			departureTime = newDeparture;
			success = true;
		}
		else {
			departureTime = -1;
		}
		return success;
	}

	bool Train::transfer(const Train& transferFrom) {
		bool success = false;
		
		if (!this->isInvalid() && !transferFrom.isInvalid()) {
			char* newName = nullptr;
			newName = new char[strlen(this->trainName) + strlen(transferFrom.trainName) + 3];
            //Allocate new dynamic memory to store new combined name. For the array size, addition to length or two names, +3 for ",", " ", \0

			strcpy(newName, this->trainName);//first copy train name of 'to'.
			strcat(newName, ", ");// add ", "
			strcat(newName, transferFrom.trainName);//add train name of 'from'
			delete[] this->trainName;//Empty the string
			this->trainName = newName;//redefine the name.

			this->noOfPassenger += transferFrom.noOfPassenger;
			if (this->noOfPassenger > MAX_NO_OF_PASSENGER) {
				int unboarded = this->noOfPassenger - MAX_NO_OF_PASSENGER;
				this->noOfPassenger = MAX_NO_OF_PASSENGER;
				cout << "Train is full; " << unboarded << " passengers of " << transferFrom.getName() << " could not be boarded!" << endl;
			}
			success = true;
		}
		return success;
	}

}
