#include "complex.h"

int main(){
        Complex a(7, -4), b(3, 2), c;
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
