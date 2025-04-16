#ifndef SENECA_LABELEDSHAPE_H
#define SENECA_LABELEDSHAPE_H

#include <cstring>
#include "Shape.h"

namespace seneca {

    class LblShape : public Shape{
        // Dynamically allocated label for the shape
            char* m_label{ nullptr };

        protected:
            // Returns the label string for derived classes to access
            const char* label() const;

        public:
            // Default constructor
            LblShape();

            // Constructor with label initialization
            LblShape(const char* label);
            virtual ~LblShape();

            // Copy constructor and assignment operator are deleted to prevent copying
            LblShape(const LblShape& lblShape) = delete;

            // Reads label specifications from input stream
            LblShape& operator=(const LblShape& lblShape) = delete;

            // Destructor to release dynamically allocated memory
            void getSpecs(std::istream& is);
        };
}

#endif // !SENECA_LABELEDSHAPE_H