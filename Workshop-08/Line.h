#ifndef SENECA_LINE_H
#define SENECA_LINE_H

#include "LblShape.h"

namespace seneca {
    class Line : public LblShape {
        int m_length;
    public:
        Line();
        Line(const char* label, int length);
        void getSpecs(std::istream& is) ;
        void draw(std::ostream& os) const ;

    };

}


#endif