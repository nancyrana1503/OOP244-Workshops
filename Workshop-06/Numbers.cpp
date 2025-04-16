#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <fstream>
#include <iomanip>
#include "Numbers.h"

using namespace std;

namespace seneca {

    // Private Member Functions
    void Numbers::setEmpty() {
        m_numbers = nullptr;
        m_filename = nullptr;
        m_numCount = 0;
    }

    // Constructors and Destructor
    Numbers::Numbers() {
        setEmpty();
        m_isOriginal = false;
    }

    Numbers::Numbers(const char* filename) {
        setEmpty();
        m_isOriginal = true;
        setFilename(filename);
        m_numCount = numberCount();
        if (m_numCount == 0 || !load()) {
            delete[] m_numbers;
            delete[] m_filename;
            setEmpty();
            m_isOriginal = false;
        }
        else {
            sort();
        }
    }

    Numbers::Numbers(const Numbers& other)
        : m_numbers(nullptr), m_filename(nullptr), m_isOriginal(false), m_numCount(other.m_numCount) {
        if (!other.isEmpty()) {
            m_numbers = new double[m_numCount];
            for (size_t i = 0; i < m_numCount; i++) {
                m_numbers[i] = other.m_numbers[i];
            }
        }
    }

    Numbers& Numbers::operator=(const Numbers& other) {
        if (this != &other) {
            delete[] m_numbers;
            m_numCount = other.m_numCount;
            m_numbers = new double[m_numCount];
            for (size_t i = 0; i < m_numCount; i++) {
                m_numbers[i] = other.m_numbers[i];
            }
        }
        return *this;
    }

    Numbers::~Numbers() {
        if (m_isOriginal && !isEmpty()) save();
        delete[] m_numbers;
        delete[] m_filename;
    }

    bool Numbers::isEmpty() const {
        return m_numbers == nullptr;
    }

    void Numbers::setFilename(const char* filename) {
        delete[] m_filename;
        m_filename = new char[strlen(filename) + 1];
        strcpy(m_filename, filename);
    }

    size_t Numbers::numberCount() const {
        ifstream file(m_filename);
        int count = 0;
        double value;
        while (file >> value) count++;
        return count;
    }

    bool Numbers::load() {
        if (m_numCount > 0) {
            m_numbers = new double[m_numCount];
            ifstream file(m_filename);
            size_t i = 0;
            while (file && i < m_numCount) {
                file >> m_numbers[i++];
            }
            if (i != m_numCount) {
                delete[] m_numbers;
                setEmpty();
                return false;
            }
            return true;
        }
        return false;
    }

    void Numbers::save() const {
        if (m_isOriginal && !isEmpty()) {
            ofstream file(m_filename);
            for (size_t i = 0; i < m_numCount; i++) {
                file << m_numbers[i] << endl;
            }
        }
    }

    void Numbers::sort() {
        for (size_t i = m_numCount - 1; i > 0; i--) {
            for (size_t j = 0; j < i; j++) {
                if (m_numbers[j] > m_numbers[j + 1]) {
                    double temp = m_numbers[j];
                    m_numbers[j] = m_numbers[j + 1];
                    m_numbers[j + 1] = temp;
                }
            }
        }
    }

    double Numbers::average() const {
        double aver = 0.0;
        if (!isEmpty()) {
            for (size_t i = 0; i < m_numCount; i++) {
                aver += m_numbers[i];
            }
            aver /= m_numCount;
        }
        return aver;
    }

    double Numbers::min() const {
        double minVal = m_numbers[0];
        for (size_t i = 1; i < m_numCount; i++) {
            if (minVal > m_numbers[i]) minVal = m_numbers[i];
        }
        return minVal;
    }

    double Numbers::max() const {
        double maxVal = m_numbers[0];
        for (size_t i = 1; i < m_numCount; i++) {
            if (maxVal < m_numbers[i]) maxVal = m_numbers[i];
        }
        return maxVal;
    }

    Numbers& Numbers::operator+=(double value) {
        double* temp = new double[m_numCount + 1];
        for (size_t i = 0; i < m_numCount; i++) {
            temp[i] = m_numbers[i];
        }
        temp[m_numCount] = value;
        delete[] m_numbers;
        m_numbers = temp;
        m_numCount++;
        sort();
        return *this;
    }

    std::ostream& Numbers::display(std::ostream& ostr) const {
        if (isEmpty()) {
            ostr << "Empty list";
        }
        else {
            ostr << "=========================" << endl;
            if (m_isOriginal) 
            { ostr << m_filename << endl; 
            }
            else {
                ostr << "*** COPY ***" << endl;
            }
            ostr << std::fixed << std::setprecision(2);
            for (size_t i = 0; i < m_numCount; i++) {
                ostr << m_numbers[i]; // Display each number
                if (i < m_numCount - 1) ostr << ", ";
            }
            ostr << endl << "-------------------------" << endl;
            ostr << "Total of " << m_numCount << " number(s)" << endl;
            ostr << "Largest number:  " << max() << endl;
            ostr << "Smallest number: " << min() << endl;
            ostr << "Average:         " << average() << endl;
            ostr << "=========================";

            
        }
        return ostr;
    }

    // Overloaded Operators
    std::ostream& operator<<(std::ostream& os, const Numbers& N) {
        return N.display(os);
    }

    std::istream& operator>>(std::istream& istr, Numbers& N) {
        double value;
        if (istr >> value) {
            N += value;
        }
        return istr;
    }
} // namespace seneca
