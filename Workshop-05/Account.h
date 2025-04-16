
#ifndef SENECA_ACCOUNT_H_
#define SENECA_ACCOUNT_H_

#include <iostream>

namespace seneca {
    class Account {
        int m_number;
        double m_balance;
        void setEmpty(); 

    public:
        // Constructors
        Account();
        Account(int number, double balance);

        std::ostream& display() const;
        operator bool() const;
        operator int() const;
        operator double() const;
        bool operator ~() const;

        Account& operator=(int number);    
        Account& operator=(Account& other);
        Account& operator+=(double amount);
        Account& operator-=(double amount);
        Account& operator<<(Account& other);
        Account& operator>>(Account& other);

        friend double operator+(const Account& left, const Account& right);
        friend double operator+=(double& left, const Account& right);
    };
}

#endif // SENECA_ACCOUNT_H_
