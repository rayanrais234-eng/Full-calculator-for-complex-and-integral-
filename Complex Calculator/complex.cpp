#include <iostream>
#include <cmath>
#include <stdexcept>
#include "complex.h"

Complex::Complex(double r, double i) : real(r), imag(i) {}
Complex::Complex(const Complex& c) : real(c.real), imag(c.imag) {}

void Complex::setReal(double r) { real = r; }
void Complex::setImag(double i) { imag = i; }
double Complex::getReal() const { return real; }
double Complex::getImag() const { return imag; }
void Complex::display() const {
    std::cout << real << " + " << imag << "i" << std::endl;
}
Complex Complex::fromPolar(double magnitude, double angle) {
    return Complex(magnitude * std::cos(angle), magnitude * std::sin(angle));
}

double Complex::getMagnitude() const {
    return std::sqrt(real * real + imag * imag);
}
Complex Complex::getConjugate() const {
    return Complex(real, -imag);
}
double Complex::getAngle() const {
    return std::atan2(imag, real);
}

Complex Complex::operator+(const Complex& other) const {
    return Complex(real + other.real, imag + other.imag);
}
Complex Complex::operator-(const Complex& other) const {
    return Complex(real - other.real, imag - other.imag);
}
Complex Complex::operator*(const Complex& other) const {
    return Complex(real * other.real - imag * other.imag,
                   real * other.imag + imag * other.real);
}
Complex Complex::operator/(const Complex& other) const {
    double denominator = other.real * other.real + other.imag * other.imag;

    if (denominator == 0) {
        throw std::runtime_error("Division by zero complex number");
    }

    Complex num = (*this) * other.getConjugate();

    return Complex(num.getReal() / denominator,
                   num.getImag() / denominator);
}
Complex Complex::operator^(double n) const {
    double r = getMagnitude();
    double theta = getAngle();

    if (n == 0) return Complex(1.0, 0.0);
    if (n < 0 && getMagnitude() == 0.0) {
        throw std::runtime_error("Zero cannot be raised to a negative power");
    }
    double r_pow = std::pow(r, n);
    double theta_n = theta * n;
    return fromPolar(r_pow, theta_n);
}
Complex Complex::pow(double base) const {
    double ln_base = std::log(base);
    double real_part = real * ln_base;
    double imag_part = imag * ln_base;
    double exp_real = exp(real_part);
    return Complex(exp_real * std::cos(imag_part), exp_real * std::sin(imag_part));
}
void Complex::getPolarForm(Complex& a) const {
    a.setReal(getMagnitude());
    a.setImag(getAngle());
}
void Complex::displayPolarForm() const {
    std::cout << getMagnitude() << "*e^(i * "
              << getAngle() << ")" << std::endl;
}
