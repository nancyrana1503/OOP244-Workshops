#define _CRT_SECURE_NO_WARNINGS
#include "LblShape.h"
#include "Utils.h"
using namespace std;
namespace seneca {

    // This function returns the label associated with the LblShape object.
    const char* LblShape::label() const {
        return m_label;
    }

    // Default constructor: Initializes m_label to nullptr to indicate no label has been set yet.
    LblShape::LblShape() {
        m_label = nullptr;
    }

    // Parameterized constructor: Accepts a const char pointer as a label. 
    LblShape::LblShape(const char* label) {
        if (label != nullptr && label[0] != '\0') {
            m_label = new char[strlen(label) + 1];
            strcpy(m_label, label);
        }
    }

    // Destructor: Releases memory allocated for m_label to avoid memory leaks.
    LblShape::~LblShape() {
        if (m_label != nullptr) {
            delete[] m_label;
            m_label = nullptr;
        }
    }

    // getSpecs function: Reads a label from an input stream until a comma (or up to 256 characters).
    void LblShape::getSpecs(istream& is) {
        char label[256] = { '\0', };
        is.getline(label, 256, ',');
        if (m_label != nullptr) {
            delete[] m_label;
            m_label = nullptr;
        }
        m_label = new char[strlen(label) + 1];
        strcpy(m_label, label);
    }

}