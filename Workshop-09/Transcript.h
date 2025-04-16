/***********************************************************************
// OOP244 workshop 9, Transcript module
//
// File	Transcript.h
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
#ifndef SENECA_TRANSCRIPT_H
#define SENECA_TRANSCRIPT_H
#include <iostream>
#include "Marks.h"
namespace seneca {
    class Transcript :
        public Marks {


        // character pointer student name
        char* m_studentName;

        // unsigned integer or size_t student number
        unsigned int m_studentNumber;

    private:
        void setStudentName(const char* name);

    public:
        // Constructor
        Transcript(const char* studentName, unsigned int studentNamber);
        Transcript(const Transcript& src);
        Transcript& operator=(const Transcript& src);
        ~Transcript();
        
        std::ostream& display(std::ostream& os = std::cout) const override;
    };


}
#endif // !SENECA_TRANSCRIPT_H