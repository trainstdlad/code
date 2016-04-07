#ifndef COMPLEX_H_
#define COMPLEX_H_
#include <iostream>
class Complex{
private:
        int real, imaginary;
public:
        Complex();
        Complex(const int);
        Complex(const int, const int);
        Complex & operator=(const Complex &);
        Complex operator+(const Complex &);
        Complex operator-(const Complex &);
        Complex operator*(const Complex &);
        Complex operator/(const Complex &);
        friend std::ostream & operator<<(std::ostream &, const Complex &);
};
#endif /* COMPLEX_H_ */
