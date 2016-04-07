#include "complex.h"
Complex::Complex(){
        real = 0;
        imaginary = 0;
}

Complex::Complex(const int x){
        real = x;
        imaginary = 0;
}

Complex::Complex(const int x, const int y){
        real = x;
        imaginary = y;
}

Complex & Complex::operator=(const Complex & r_complex){
        real = r_complex.real;
        imaginary = r_complex.imaginary;
        return *this;
}

Complex Complex::operator+(const Complex & r_complex){
        int new_real = real + r_complex.real;
        int new_imaginary = imaginary + r_complex.imaginary;
        return Complex(new_real, new_imaginary);
}

Complex Complex::operator-(const Complex & r_complex){
        int new_real = real - r_complex.real;
        int new_imaginary = imaginary - r_complex.imaginary;
        return Complex(new_real, new_imaginary);
}

Complex Complex::operator*(const Complex & r_complex){
        int new_real = real * r_complex.real - imaginary * r_complex.imaginary;
        int new_imaginary = imaginary * r_complex.real + real * r_complex.imaginary;
        return Complex(new_real, new_imaginary);
}

Complex Complex::operator/(const Complex & r_complex){
        int new_real = (real * r_complex.real + imaginary * r_complex.imaginary)/
                (r_complex.real * r_complex.real + r_complex.imaginary * r_complex.imaginary);
        int new_imaginary = (imaginary * r_complex.real - real * r_complex.imaginary)/
                (r_complex.real * r_complex.real + r_complex.imaginary * r_complex.imaginary);
        return Complex(new_real, new_imaginary);
}

std::ostream & operator<<(std::ostream & output, const Complex & r_complex){
        output << r_complex.real;
        if(r_complex.imaginary < 0)
                output << r_complex.imaginary << "i";
        else
                output << "+" << r_complex.imaginary << "i";
        return output;
}
