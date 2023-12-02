#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include "Utils.h"
#include "AidMan.h"
#include "Perishable.h"
#include "iProduct.h"


using namespace std;
namespace sdds {
	unsigned int AidMan::menu() const {
		cout << "Aid Management System" << endl
			<< "Date: ";
		cout << date << endl << "Data file: ";

		//display file name depands on the value;
		if (m_fileName == nullptr) {
			cout << "No file" << endl;
		}
		else {
			cout << m_fileName << endl;
		}

		cout << "---------------------------------"<< endl;
		return m_Menu.run();
	}

	AidMan::AidMan(const char* fileName) {
		//Initialize m_menContent
		m_Menu.content("List Items\tAdd Item\tRemove Item\tUpdate Quantity\tSort\tShip Items\tNew/Open Aid Database");
		m_noOfProduct = 0;
		if (fileName != nullptr) {
			ut.alocpy(m_fileName, fileName);
		}
		else {
			m_fileName = nullptr;
		}
		//upgrade for ms51
		for (int i = 0; i < sdds_max_num_items; i++) {
			m_iproduct[i] = nullptr;
		}
	}

	AidMan::~AidMan() {
		delete[] m_fileName;
		m_fileName = nullptr;
		//upgrade for ms51
		deallocate();
	}

	void AidMan::run() {
		unsigned int code;
		//int noOfList;
		do {
			code = menu();
			if (code != 0 && m_fileName == NULL && code != 7) {
				code = 7;
			}
			switch (code) {
			case 1:
				cout << "\n****List Items****\n";
				//Upgrade from MS51
				listDetails();
				break;
			case 2:
				cout << "\n****Add Item****\n";
				addItem();
				break;
			case 3:
				cout << "\n****Remove Item****\n";
				break;
			case 4:
				cout << "\n****Update Quantity****\n";
				break;
			case 5:
				cout << "\n****Sort****\n";
				break;
			case 6:
				cout<< "\n****Ship Items****\n";
				break;
			case 7:
				cout << "\n****New/Open Aid Database****\n";
				load();
				cout << m_noOfProduct << " records loaded!" << endl;
				break;
			case 0:
				cout << "Exiting Program!";
				save();
				break;
			}
			cout << endl;
		} while (code != 0);
	}

	void AidMan::save() {
		if (m_fileName != nullptr) {
			ofstream createFile(m_fileName);
			for (int i = 0; m_iproduct[i] != 0; i++)
			{
				m_iproduct[i]->save(createFile);
				createFile << "\n";
			}
		}
	}

	void AidMan::deallocate() {
		//delete[] iproduct;
		for (int i = 0; i < sdds_max_num_items; i++)
		{
			delete m_iproduct[i];
		}
		m_noOfProduct = 0;
	}

	void AidMan::load() {
		char firstNum;
		string fileName;
		int createNewFile;
		int i = 0;

		save();
		deallocate();

		cout << "Enter file name: ";
		cin >> fileName;
		ut.alocpy(m_fileName, fileName.c_str());
		ifstream ifstr(m_fileName);

		if (!ifstr) {
			cout << "Failed to open " << m_fileName << " for reading!" << endl <<
				"Would you like to create a new data file?" << endl <<
				"1- Yes!" << endl <<
				"0 - Exit" << endl;
			createNewFile = ut.getint(0, 1, "> ");
			if (createNewFile) {
				ofstream ofstr(m_fileName);
			}	
		}
		else {
			while (ifstr) {
				firstNum = ifstr.peek();
				//Depends on sku, Perishable/Item
				if (firstNum > '0' && firstNum < '4') {
					m_iproduct[i] = new Perishable;
					m_iproduct[i]->load(ifstr);
				}
				else if (firstNum >= '4' && firstNum <= '9') {
					m_iproduct[i] = new Item;
					m_iproduct[i]->load(ifstr);
				}
				else {
					ifstr.setstate(ios::badbit);
				}
				//When load was successful
				if (m_iproduct[i]) {
					m_noOfProduct++;
					i++;
				}
				//when load failed
				else {
					delete m_iproduct[i];
				}
			}
		}
	}
	
	//Custom function for Menu 1
	void AidMan::listDetails() {
		int noOfList = list();
		cout << "Enter row number to display details or <ENTER> to continue:" << endl << "> ";
		cin.clear();
		cin.get();
		if (cin.peek() != '\n')//If input is other than <ENTER>
		{
			//get user input for selection from the list
			int select = ut.getint(1, noOfList);
			m_iproduct[select - 1]->linear(false);
			m_iproduct[select - 1]->display(cout);
			cout << endl;
		}
	}

	int AidMan::list(const char* desc) {
		int i = 0;
		cout << " ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry" << endl
			<< "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
		if (desc == nullptr) {
			for (i = 0; m_iproduct[i] != nullptr; i++)
			{
				cout << "   " << i + 1;
				cout << " | ";
				m_iproduct[i]->linear(true);
				cout << *m_iproduct[i] << endl;
			}
			cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
		}
		else {
			for (i = 0; m_iproduct[i] != nullptr; i++)
			{
				cout << "   " << i + 1;
				cout << " | ";
				if (*m_iproduct[i] == desc)
					cout << *m_iproduct[i] << endl;
				cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
			}
		}
		return i;
	}

	int AidMan::search(int sku) const {
		int index = -1;
		for (int i = 0;  i < m_noOfProduct && index == -1; i++)
		{
			if (*m_iproduct[i] == sku)
				index = i;
		}
		return index;
	}

	//Custom fucntion for Menu 2
	void AidMan::addItem() {
		if (m_noOfProduct >= sdds_max_num_items) {
			cout << "Database full!";
		}
		else {
			int inputSku = 0;
			int schSku = 0;
			displayMenu("Perishable\tNon-Perishable", 2);
			cout << "-----------------" << endl << "0- Exit" << endl;
			int select = ut.getint(1, 2, "> ");
			if (select == 1) {
				m_iproduct[m_noOfProduct] = new Perishable;
				inputSku = m_iproduct[m_noOfProduct]->readSku(cin);
				schSku = search(inputSku);
				//When input sku is available
				if (schSku == -1) {
					m_iproduct[m_noOfProduct]->read(cin);
					if (m_iproduct[m_noOfProduct]) {
						m_noOfProduct++;
					}
					else {
						m_iproduct[m_noOfProduct]->display(cout);
						delete m_iproduct[m_noOfProduct];
						m_iproduct[m_noOfProduct] = nullptr;
					}
				}
				//Not available
				else {
					cout << "Sku: " << inputSku << " is already in the system, try updating quantity instead.\n";
				}
			}
			else if (select == 2) {
				m_iproduct[m_noOfProduct] = new Item;
				inputSku = m_iproduct[m_noOfProduct]->readSku(cin);
				schSku = search(inputSku);
				//When input sku is available
				if (schSku == -1) {
					m_iproduct[m_noOfProduct]->read(cin);
					if (m_iproduct[m_noOfProduct]) {
						m_noOfProduct++;
					}
					else {
						m_iproduct[m_noOfProduct]->display(cout);
						delete m_iproduct[m_noOfProduct];
						m_iproduct[m_noOfProduct] = nullptr;
					}
				}
				//Not available
				else {
					cout << "Sku: " << inputSku << " is already in the system, try updating quantity instead.\n";
				}
			}
			else if (select == 0) {
				cout << "Aborted\n";
			}
		}
	}
}
