/***********************************************************************
// OOP244 Workshop #1 : Lab tester program
//
// File	file.h
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

#ifndef SENECA_FILE_H_
#define SENECA_FILE_H_
namespace seneca {

    bool openFile(const char filename[]);
    void closeFile();
    bool readTitle(char title[]);
    bool readYear(int* year);
    bool readMovieRating(char rating[]);
    bool readDuration(int* duration);
    bool readGenres(char genres[][11]);
    bool readConsumerRating(float* rating);
}
#endif




