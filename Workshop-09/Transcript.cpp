/***********************************************************************
// OOP244 workshop 9, Transcript module
//
// File	Transcript.coo
// Version 1.0
// Date 2024-11-18
// started by Fardad
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Nancy Rana    11-30-24
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Transcript.h"
#include "Utils.h"
using namespace std;
namespace seneca {

    Transcript::Transcript(const char* studentName, unsigned int studentNumber)
        : Marks(), m_studentName(nullptr), m_studentNumber(studentNumber) {
        setStudentName(studentName);
    }

    Transcript::Transcript(const Transcript& src) : Marks(src), m_studentName(nullptr), m_studentNumber(src.m_studentNumber) {
        setStudentName(src.m_studentName);
    }

    Transcript& Transcript::operator=(const Transcript& src) {
        if (this != &src) {
            Marks::operator=(src);
            setStudentName(src.m_studentName);
            m_studentNumber = src.m_studentNumber;
        }
        return *this;
    }

    Transcript::~Transcript() {
        delete[] m_studentName;
    }

    void Transcript::setStudentName(const char* name) {
        delete[] m_studentName;
        if (name) {
            m_studentName = new char[std::strlen(name) + 1];
            std::strcpy(m_studentName, name);
        }
        else {
            m_studentName = nullptr;
        }
    }

    std::ostream& Transcript::display(std::ostream& os) const { // Updated to return std::ostream&
        os << (m_studentName ? m_studentName : "No Name") << " (" << m_studentNumber << ")" << std::endl;
        os << std::string(74, '-') << std::endl;
        Marks::display(os);                  // Use base class display
        return os; // Return the output stream
    }

}