#ifndef COMPLEX_H_
#define COMPLEX_H_
#include <iostream>
template <typename T>
class Complex{
private:
        T real, imaginary;
public:
        Complex();
        Complex(const T);
        Complex(const T, const T);
        Complex<T> & operator=(const Complex<T> &);
        Complex<T> operator+(const Complex<T> &);
        Complex<T> operator-(const Complex<T> &);
        Complex<T> operator*(const Complex<T> &);
        Complex<T> operator/(const Complex<T> &);
        template <typename C>
        friend std::ostream & operator<<(std::ostream &, const Complex<C> &);
};

#include "complex.tpp"
#endif /* COMPLEX_H_ */
