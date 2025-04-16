#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "input.h"

using namespace std;
namespace seneca {

    int getInt() {
        int num = 0;
        bool done = false;
        do {
            // extract an integer from the console and put it in num
            cin >> num;
            // if this action fails (the integer is unreadable)
            if (cin.fail()) {
                cout << "Bad integer entry, please try again:\n> ";
                // clear the failure status to activate cin again
                cin.clear();
            }
            else {
                done = true;
            }
            // flush the keyboard buffer up to 1000 characters or '\n', whichever comes first
            cin.ignore(1000, '\n');
        } while (!done);
        return num;
    }
    int getInt(int min, int max) {
        int num = 0;
        bool valid = false;
        do {
            num = getInt();  // Call the no-argument getInt to get the input from the user
            if (num >= min && num <= max) {
                valid = true;
            }
            else {
                cout << "Invalid value, ["<<min << "<ENTRY<" << max<<"]" << "\n> ";
            }
        } while (!valid);
        return num;
    }
    
     bool getInt(int& valueRef, int min, int max) {
            int value = getInt(); 
            if (value >= min && value <= max) {
                valueRef = value;
                return true;  // entry valid
            }
            else {
                return false;  // entry ivalid
            }
        }
    }



