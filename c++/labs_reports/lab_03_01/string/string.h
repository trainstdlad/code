#ifndef STRING_H_
#define STRING_H_
#include <iostream>
#include <cstring>

using namespace std;

class String{
private:
        char * data;
        unsigned int length;
public:
        String();
        String(const char *);
        ~String();
        unsigned int Length();
        void Copy(const String &);
        void Copy(const char *);
        String Substr(unsigned int, unsigned int);
        void Remove(unsigned int, unsigned int);
        void Insert(const char *, unsigned int);
        void trim();
        void read();
        void print();
};

#endif /* STRING_H_ */