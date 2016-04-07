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

template <typename T>
Complex<T>::Complex(){
        real = 0;
        imaginary = 0;
}

template <typename T>
Complex<T>::Complex(const T x){
        real = x;
        imaginary = 0;
}

template <typename T>
Complex<T>::Complex(const T x, const T y){
        real = x;
        imaginary = y;
}

template <typename T>
Complex<T> & Complex<T>::operator=(const Complex<T> & r_complex){
        real = r_complex.real;
        imaginary = r_complex.imaginary;
        return *this;
}

template <typename T>
Complex<T> Complex<T>::operator+(const Complex<T> & r_complex){
        T new_real = real + r_complex.real;
        T new_imaginary = imaginary + r_complex.imaginary;
        return Complex(new_real, new_imaginary);
}

template <typename T>
Complex<T> Complex<T>::operator-(const Complex<T> & r_complex){
        T new_real = real - r_complex.real;
        T new_imaginary = imaginary - r_complex.imaginary;
        return Complex(new_real, new_imaginary);
}

template <typename T>
Complex<T> Complex<T>::operator*(const Complex<T> & r_complex){
        T new_real = real * r_complex.real - imaginary * r_complex.imaginary;
        T new_imaginary = imaginary * r_complex.real + real * r_complex.imaginary;
        return Complex(new_real, new_imaginary);
}

template <typename T>
Complex<T> Complex<T>::operator/(const Complex<T> & r_complex){
        T new_real = (real * r_complex.real + imaginary * r_complex.imaginary)/
                (r_complex.real * r_complex.real + r_complex.imaginary * r_complex.imaginary);
        T new_imaginary = (imaginary * r_complex.real - real * r_complex.imaginary)/
                (r_complex.real * r_complex.real + r_complex.imaginary * r_complex.imaginary);
        return Complex(new_real, new_imaginary);
}

template <typename T>
std::ostream & operator<<(std::ostream & output, const Complex<T> & r_complex){
        output << r_complex.real;
        if(r_complex.imaginary < 0)
                output << r_complex.imaginary << "i";
        else
                output << "+" << r_complex.imaginary << "i";
        return output;
}

int main(){
        Complex<int> a(7, -4), b(3, 2), c;
        std::cout << "a = " << a << std::endl;
        std::cout << "b = " << b << std::endl;
        c = a;
        std::cout << "c = " << c << std::endl;
        c = 3;
        std::cout << "c = " << c << std::endl;
        std::cout << "a + b = " << a + b << std::endl;
        std::cout << "a - b = " << a - b << std::endl;
        std::cout << "a * b = " << a * b << std::endl;
        std::cout << "a / b = " << a / b << std::endl;
        return 0;
}
