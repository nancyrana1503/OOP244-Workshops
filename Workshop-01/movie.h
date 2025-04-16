/***********************************************************************
// OOP244 Workshop #1 : Lab tester program
//
// File	movie.h
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

#ifndef SENECA_MOVIE_H_
#define SENECA_MOVIE_H_
namespace seneca {

    struct Movie {
        char m_title[128];
        int m_year;
        char m_rating[6];
        int m_duration;
        char m_genres[10][11];
        float m_consumerRating;

    };

    bool loadMovies();
    bool hasGenre(const Movie* mvp, const char genre[]);
    void displayMovie(const Movie* mvp);
    void displayMoviesWithGenre(const char genre[]);

  
}
#endif




