
#include "Account.h"

using namespace std;

namespace seneca {

    void Account::setEmpty() {
        m_number = -1;
        m_balance = 0.0;
    }

    Account::Account() {
        m_number = 0;
        m_balance = 0.0;
    }

    Account::Account(int number, double balance) {
        setEmpty();
        if (number >= 10000 && number <= 99999 && balance >= 0) {
            m_number = number;
            m_balance = balance;
        }
    }

    std::ostream& Account::display() const {
        if (*this) {
            cout << " ";
            cout << m_number << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << m_balance;
            cout.unsetf(ios::right);
            cout << " ";
        }
        else if (~*this) {
            cout << "  NEW  |         0.00 ";
        }
        else {
            cout << "  BAD  |    ACCOUNT   ";
        }
        return cout;
    }

    Account::operator bool() const {
        return m_number >= 10000 && m_number <= 99999 && m_balance >= 0;
    }

    Account::operator int() const {
        return m_number;
    }

    Account::operator double() const {
        return m_balance;
    }

    bool Account::operator~() const {
        return m_number == 0;
    }

    Account& Account::operator=(int number) {
        if (~*this && number >= 10000 && number <= 99999) {
            m_number = number;
        }
        else if (~*this) {
            setEmpty();
        }
        return *this;
    }

    Account& Account::operator=(Account& other) {
        if (~*this && other) {
            m_number = other.m_number;
            m_balance = other.m_balance;
            other.m_number = 0;
            other.m_balance = 0.0;
        }
        return *this;
    }

    Account& Account::operator+=(double amount) {
        if (*this && amount > 0) {
            m_balance += amount;
        }
        return *this;
    }

    Account& Account::operator-=(double amount) {
        if (*this && amount > 0 && m_balance >= amount) {
            m_balance -= amount;
        }
        return *this;
    }

    Account& Account::operator<<(Account& other) {
        if (*this && other && this != &other) {
            m_balance += other.m_balance;
            other.m_balance = 0.0;
        }
        return *this;
    }

    Account& Account::operator>>(Account& other) {
        if (*this && other && this != &other) {
            other.m_balance += m_balance;
            m_balance = 0.0;
        }
        return *this;
    }

    double operator+(const Account& left, const Account& right) {
        if (left && right) {
            return left.m_balance + right.m_balance;
        }
        return 0.0;
    }

    double operator+=(double& left, const Account& right) {
        if (right) {
            left += right.m_balance;
        }
        return left;
    }

}
