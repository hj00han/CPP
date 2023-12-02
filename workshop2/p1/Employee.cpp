#include <iostream>
#include "Employee.h"
#include "File.h"

using namespace std;

namespace sdds {

    int noOfEmployees;
    Employee* employees;


    void sort() {
        int i, j;
        Employee temp;
        for (i = noOfEmployees - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (employees[j].m_empNo > employees[j + 1].m_empNo) {
                    temp = employees[j];
                    employees[j] = employees[j + 1];
                    employees[j + 1] = temp;
                }
            }
        }
    }

    // TODO: Finish the implementation of the 1 arg load function which
    // reads one employee record from the file and loads it into the employee reference
    // argument
    bool load(Employee &employees) {
        bool ok = false;
        // return the combined success result of the three read functions. These read 
        // functions should set the properties of the reference argument of the load function
        if (read(employees.m_empNo) && read(employees.m_salary) && read(employees.m_name)); {
            ok = true;
        }
        return ok;
    }
    // TODO: Finish the implementation of the 0 arg load function 
    bool load() {
        bool ok = true;

        if (openFile(DATAFILE)) {
            noOfEmployees = noOfRecords();
            employees = new Employee[noOfEmployees];
            
            for (int i = 0; i < noOfEmployees; i++) {
                if (!load(employees[i])) { //Check if load function succeeded
                    ok = false;
                    cout << "Error: incorrect number of records read; the data is possibly corrupted." << endl;
                    break; //When load function fails for any of members of struct, get out of the loop.
                }
            }            
        }
        else {
            cout << "Could not open data file : " << DATAFILE << endl;
            ok = false;
        }
        closeFile();
        return ok;
    }

    // TODO: Implementation for the display functions go here
    void display(const Employee employees) {
        cout << employees.m_empNo << ": " << employees.m_name << ", $" << employees.m_salary << endl;
    }

    void display() {
        cout << "Employee Salary report, sorted by employee number" << endl
            << "no- Empno, Name, Salary" << endl
            << "------------------------------------------------" << endl;
        sort();
        for (int i = 0; i < noOfEmployees + 1; i++) {
            cout << i+1 << "- ";
            display(employees[i]);
        }
    }

    // TODO: Implementation for the deallocateMemory function goes here
    void deallocateMemory() {
        for (int i = 0; i < noOfEmployees; i++)
        {
            delete employees[i].m_name;
        }//deallocate every member of name array with for loop
        delete employees;
    }
}
