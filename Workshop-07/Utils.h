
#ifndef SENECA_UTILS_H
#define SENECA_UTILS_H
namespace seneca {
    class Utils {
    public:
        char* alocpy(const char* src)const;
        char* alocpy(char*& des, const char* src)const;
        char* strcpy(char* des, const char* src)const;
        char* strcpy(char* des, const char* src, int len)const;
        int strlen(const char* str)const;
        bool isspace(char ch)const;
        bool isspace(const char* cstring)const;
    };
    extern Utils ut;   // makes the ut object available where Utils.h is included
    // to call a Utils function call it as follows
    // ut.strcpy(des, src);
}

#endif // !SENECA_UTILS_H