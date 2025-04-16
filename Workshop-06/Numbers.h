#ifndef NUMBERS_H
#define NUMBERS_H

#include <iostream>

namespace seneca {
    class Numbers {
        double* m_numbers;         // Dynamic array of doubles
        char* m_filename;          // File name associated with the class
        bool m_isOriginal;         // Flag to indicate if the object is original
        size_t m_numCount;         // Number of double values in m_numbers

        void setEmpty();
        size_t numberCount() const;
        bool load();
        void save() const;

    public:
        // Constructors and Destructor
        Numbers(const char* filename);   // One-argument constructor
        Numbers();                       // Default constructor
        ~Numbers();                      // Destructor
        Numbers(const Numbers& other);   // Copy constructor
        Numbers& operator=(const Numbers& other); // Copy assignment operator

        // Member functions
        bool isEmpty() const;
        void setFilename(const char* filename);
        void sort();
        double max() const;
        double min() const;
        double average() const;
        Numbers& operator+=(double value);
        std::ostream& display(std::ostream& ostr) const;

        // Helper friend functions
        friend std::ostream& operator<<(std::ostream& os, const Numbers& N);
        friend std::istream& operator>>(std::istream& istr, Numbers& N);
    };
}
#endif
