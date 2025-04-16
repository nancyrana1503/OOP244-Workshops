#ifndef SENECA_PROFESSOR_H
#define SENECA_PROFESSOR_H

#include "Employee.h"
#include "Utils.h"

namespace seneca {
    class Professor : public Employee {
        char* m_subject{};
        int m_numSections{};

        double devPay() const; // Additional pay calculation based on sections

    public:
        // Constructors
        Professor();
        Professor(const char* name, const char* subject, int numSections, size_t employeeNo, double salary);

        // Destructor and cleanup
        ~Professor();
        Professor(const Professor&) = delete;
        Professor& operator=(const Professor&) = delete;

        // Member functions
        std::istream& read(std::istream& istr = std::cin);
        std::ostream& write(std::ostream& ostr = std::cout) const;
        std::ostream& title(std::ostream& ostr = std::cout) const;
    };

    // Overloaded operators
    std::ostream& operator<<(std::ostream& ostr, const Professor& P);
    std::istream& operator>>(std::istream& istr, Professor& P);
}

#endif // SENECA_PROFESSOR_H
