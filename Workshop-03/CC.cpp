#include <iostream>
#include "cstr.h"
#include "CC.h"
using namespace std;
namespace seneca {
    void CC::prnNumber(unsigned long long no) const {
        cout << no / 1000000000000ull << " ";
        no %= 1000000000000ull;
        cout.fill('0');
        cout.width(4);
        cout.setf(ios::right);
        cout << no / 100000000ull << " ";
        no %= 100000000ull;
        cout.width(4);
        cout << no / 10000ull << " ";
        no %= 10000ull;
        cout.width(4);
        cout << no;
        cout.unsetf(ios::right);
        cout.fill(' ');
    }
    void CC::display(const char* name, unsigned long long number, short expYear, short expMon, short cvv) const {
        char lname[31]{};
        strcpy(lname, name, 30);
        cout << "| ";
        cout.width(30);
        cout.fill(' ');
        cout.setf(ios::left);
        cout << lname << " | ";
        prnNumber(number);
        cout << " | " << cvv << " | ";
        cout.unsetf(ios::left);
        cout.setf(ios::right);
        cout.width(2);
        cout << expMon << "/" << expYear << " |" << endl;
        cout.unsetf(ios::right);
    }

    bool CC::validate(const char* name, unsigned long long cardNo, short cvv, short expMon, short expYear) const {
        return name != nullptr && strlen(name) > 2 &&
            cardNo >= 4000000000000000ull && cardNo <= 4099999999999999ull &&
            cvv >= 100 && cvv <= 999 &&
            expMon >= 1 && expMon <= 12 &&
            expYear >= 24 && expYear <= 32;
    }

    void CC::set() {
        cardholderName = nullptr;
        cardNo = 0;
        cvv = 0;
        expMonth = 0;
        expYear = 0;


    }

    void CC::cleanUp() {
        freeMem(cardholderName);
        set();
    }

    bool CC::isEmpty() const {
        return cardholderName == nullptr;
    }

    void CC::set(const char* cc_name, unsigned long long cc_no, short cvv, short expMon, short expYear) {
       cleanUp();

        if (validate(cc_name, cc_no, cvv, expMon, expYear)) {
        alocpy(cardholderName,cc_name);

            cardNo = cc_no;
            this->cvv = cvv;        
            this->expMonth = expMon;
            this->expYear = expYear;
        }
    }

    void CC::display() const {
        if (isEmpty()) {
            cout << "Invalid Credit Card Record" << endl;
        }
        else {
            display(cardholderName, cardNo, expYear, expMonth, cvv);
        }
    }
    
}