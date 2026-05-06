#include <iostream>
#include "complex.h"
#define e 2.718281828459045

int pass = 0;
int fail = 0;
double eps = 1e-9;

int main() {
    Complex a(3.0, 4.0);
    a.display();
    a.displayPolarForm();
    if (a.getReal() == 3.0 && a.getImag() == 4.0) {
        std::cout << "Constructor works correctly." << std::endl;
        pass++;
    } else {
        std::cout << "Constructor has an issue." << std::endl;
        fail++;
    }

    Complex b(1.0, 2.0);
    Complex c1 = a + b;
    c1.display();
    c1.displayPolarForm();
    if (c1.getReal() == 4.0 && c1.getImag() == 6.0) {
        std::cout << "Addition operator works correctly." << std::endl;
        pass++;
    } else {
        std::cout << "Addition operator has an issue." << std::endl;
        fail++;
    }

    Complex c2 = a - b;
    c2.display();
    c2.displayPolarForm();
    if (c2.getReal() == 2.0 && c2.getImag() == 2.0) {
        std::cout << "Subtraction operator works correctly." << std::endl;
        pass++;
    } else {
        std::cout << "Subtraction operator has an issue." << std::endl;
        fail++;
    }

    Complex c3 = a * b;
    c3.display();
    c3.displayPolarForm();
    if (c3.getReal() == -5.0 && c3.getImag() == 10.0) {
        std::cout << "Multiplication operator works correctly." << std::endl;
        pass++;
    } else {
        std::cout << "Multiplication operator has an issue." << std::endl;
        fail++;
    }

    Complex c4 = a / b;
    c4.display();
    c4.displayPolarForm();
    if (std::abs(c4.getReal() - 2.2) < eps && std::abs(c4.getImag() + 0.4) < eps) {
        std::cout << "Division operator works correctly." << std::endl;
        pass++;
    } else {
        std::cout << "Division operator has an issue." << std::endl;
        fail++;
    }

    Complex c5 = Complex::fromPolar(2.0, M_PI/2);
    c5.display();
    if (std::abs(c5.getReal()) < eps && std::abs(c5.getImag() - 2) < eps) {
        std::cout << "fromPolar function works correctly." << std::endl;
        pass++;
    } else {
        std::cout << "fromPolar function has an issue." << std::endl;
        fail++;
    }

    Complex c6 = b ^ 3;
    c6.display();
    if (std::abs(c6.getReal() + 11) < eps && std::abs(c6.getImag() + 2) < eps) {
        std::cout << "Power operator works correctly." << std::endl;
        pass++;
    } else {
        std::cout << "Power operator has an issue." << std::endl;
        fail++;
    }
    Complex c7(0, M_PI );
    Complex result = c7.pow(e);
    result.display();
    if (std::abs(result.getReal() - (-1)) < eps && std::abs(result.getImag()) < eps) {
        std::cout << "Exponential function works correctly." << std::endl;
        pass++;
    } else {
        std::cout << "Exponential function has an issue." << std::endl;
        fail++;
    }

    std::cout << "Total tests passed: " << pass << std::endl;
    std::cout << "Total tests failed: " << fail << std::endl;

    return 0;
}