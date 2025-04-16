/*
////////////////////////////////////////////////////////////////////////
Workshop 7	: Part 1
Full Name	: Kyasol Rai
Student ID# : 133805234
Email		: krai15@myseneca.ca
Date		: 2024-11-11
Section		: ZBB

Authenticity Declaration :
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////
*/

#include "Professor.h"
#include "Utils.h"
#include <iomanip>
#include <iostream>

using namespace std;
namespace seneca {

	// Default constructor for Professor, initializes member variables
	Professor::Professor() : Employee(), m_subject(nullptr), m_numSections(0) {}

	// Parameterized constructor for Professor
	// Initializes the base Employee class and sets the subject name and number of sections
	Professor::Professor(const char* name, const char* subject, int numSections, size_t employeeNo, double salary)
		: Employee(name, employeeNo, salary), m_numSections(numSections) {
		m_subject = ut.alocpy(subject);
	}

	// Destructor to release allocated memory for m_subjectName
	Professor::~Professor() {
		delete[] m_subject;
	}

	// Calculates and returns the development pay based on the number of sections
	double Professor::devPay() const {
		return salary() * 0.01 * m_numSections;
	}

	// Reads Professor data from input stream
	std::istream& Professor::read(std::istream& istr) {
		char subject[1024];     // Temporary storage for subject name
		Employee::read(istr);
		istr.ignore();
		istr >> std::ws;        // Skip leading whitespace

		istr.getline(subject, 1024, ',');
		if (istr) {
			m_subject = ut.alocpy(m_subject, subject);
		}
		istr >> m_numSections;
		return istr;
	}

	// Writes Professor data to output stream
	std::ostream& Professor::write(std::ostream& ostr) const {
		char subjectStr[21]{};  // Temporary storage for truncated subject name
		if (m_subject) {
			ut.strcpy(subjectStr, m_subject, 20);
		}
		Employee::write(ostr);

		// Format and display Professor-specific data
		ostr << " ";
		ostr.width(20);
		ostr.setf(ios::left);
		ostr << subjectStr << " | "; // Display subject name
		ostr.unsetf(ios::left);

		ostr.width(5);
		ostr.setf(ios::right);
		ostr << m_numSections << " | "; // Display number of sections
		ostr.fill(' ');

		ostr.setf(ios::fixed);
		ostr.width(8);
		ostr.precision(2);
		ostr << devPay() << " |"; // Display development pay
		ostr.unsetf(ios::right);

		return ostr;
	}

	// Adds a title row to the output stream for Professor data display
	std::ostream& Professor::title(std::ostream& ostr) const {
		Employee::title(ostr);
		ostr << " Teaching Subject     | Sec # | $Dev Pay |";
		return ostr;
	}

	// Overloads the insertion operator to display Professor data
	ostream& operator<<(ostream& ostr, const Professor& P) {
		return P.write(ostr);
	}

	// Overloads the extraction operator to read Professor data
	std::istream& operator>>(std::istream& istr, Professor& P) {
		return P.read(istr);
	}
}