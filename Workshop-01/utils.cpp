/***********************************************************************
// OOP244 Workshop #1 : Lab tester program
//
// File	utils.cpp
// Version 1.0
// Date 2024-08-20
// Author Fardad
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Nancy Rana
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "utils.h"

using namespace std;
namespace seneca {
	// flushes the keyboard
	void flushkeys() {
		while (cin.get() != '\n');
	}

	// returns true if user enter y or Y
	bool yes() {
		char ch = cin.get();
		flushkeys();
		return ch == 'y' || ch == 'Y';
	}


	// copies src Cstring to des and converts all characters to lowercase
	// at the same time.
	void toLowerCase(char* des, const char* src) {
		int i = 0;
		while (src[i]) {
			des[i] = src[i];
			if (des[i] >= 'A' && des[i] <= 'Z') {
				des[i] += ('a' - 'A');
			}
			i++;
		}
		des[i] = 0;
	}

}