#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>  
#include "dma.h"
using namespace std;
namespace seneca {

    //defining reverse function
	void reverse() {
		int num = 0;
		cout << "Enter the number of double values:" << endl;
        cout << "> ";
		cin >>num;

        // Dynamically allocating memory for array of doubles
        double* arr = new double[num];
        
        // Read values into the array
        for (int i = 0; i < num; i++) {
            cout << (i + 1) << "> ";
            cin >> arr[i];
        }

        // Print the array values in reverse order
        for (int i = num - 1; i >= 0; i--) {
            cout << arr[i] << endl;
        }

        // Deallocating the memory
        delete[] arr;
    }

    // 1. getContact: Dynamically allocates a Contact and gets content from the user
    Contact* getContact() {
        Contact* newContact = new Contact;

        cout << "Name: ";
        cin >> newContact->m_name;

        cout << "Last name: ";
        cin >> newContact->m_lastname;

        cout << "Phone number: ";
        cin >> newContact->m_phoneNumber;

        return newContact;
    }

    // 2. display: Receives a constant Contact reference and prints the contents
    void display(const Contact& contact) {
        cout << contact.m_name << " " << contact.m_lastname << ", +" << contact.m_phoneNumber << endl;
    }

    // 3. deallocate: Deallocates the dynamically allocated Contact
    void deallocate(Contact* contact) {
        delete contact;
    }

    // 4. setEmpty: Sets the Contact fields to empty C-strings and the phone number to 0
    void setEmpty(Contact& contact) {
        strcpy(contact.m_name, "");
        strcpy(contact.m_lastname, "");
        contact.m_phoneNumber = 0;
    }
	}




