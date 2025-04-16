// Name: Nancy Rana
// Email: nrana18@myseneca.ca
// Student ID: 149951238
// File: Shape.cpp

#include "Shape.h"

namespace seneca {
    std::ostream& operator<<(std::ostream& os, const Shape& shape) {
        shape.draw(os);
        return os;
    }
    std::istream& operator>>(std::istream& is, Shape& shape) {
        shape.getSpecs(is);
        return is;
    }
}