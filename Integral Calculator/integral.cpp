#include <iostream>
#include <cmath>
#include <stdexcept>
#include "integral.h"
constexpr double eps = 1e-9;
Integral::Integral(double a, double b) : a(a), b(b) {}
Integral::Integral(const Integral& other) : a(other.a), b(other.b) {}

void Integral::setA(double a) {this->a = a;}
void Integral::setB(double b) {this->b = b;}

double Integral::getA() const {return a;}
double Integral::getB() const {return b;}

PowerIntegral::PowerIntegral(double a, double b, double k, double n) : Integral(a, b), k(k), n(n) {}
double PowerIntegral::calculate() const {
    if (std::abs(n + 1.0) < eps) {
        if (a * b <= 0.0) {
            throw std::invalid_argument("Invalid limits");
        }
        return k * std::log(std::abs(b / a));
    }
    return (k / (n + 1)) * (std::pow(b, n + 1) - std::pow(a, n + 1));
}
void PowerIntegral::display() const {
    std::cout<<"int(" << a << "," << b << ")" << k << "x^" << n << "dx" << std::endl;
}

ExponentialIntegral::ExponentialIntegral(double a, double b, double k1, double k2) : Integral(a, b), k1(k1), k2(k2) {}
double ExponentialIntegral::calculate() const {
    if (std::abs(k2) < eps) {
        return k1 * (b - a);
    }
    return (k1 / k2) * (std::exp(k2 * b) - std::exp(k2 * a));
}
void ExponentialIntegral::display() const {
    std::cout<<"int(" << a << "," << b << ")" << k1 << "e^" << k2 << "x dx" << std::endl;
}

CosineIntegral::CosineIntegral(double a, double b, double k1, double k2) : Integral(a, b), k1(k1), k2(k2) {}
double CosineIntegral::calculate() const {
    if (std::abs(k2) < eps) {
        return k1 * (b - a);
    }
    return (k1 / k2) * (std::sin(k2 * b) - std::sin(k2 * a));
}
void CosineIntegral::display() const {
    std::cout<<"int(" << a << "," << b << ")" << k1 << "cos(" << k2 << "x) dx" << std::endl;
}

SinusIntegral::SinusIntegral(double a, double b, double k1, double k2) : Integral(a, b), k1(k1), k2(k2) {}
double SinusIntegral::calculate() const {
    if (std::abs(k2) < eps) {
        return 0.0;
    }
    return (k1 / k2) * (std::cos(k2 * a) - std::cos(k2 * b));
}
void SinusIntegral::display() const {
    std::cout<<"int(" << a << "," << b << ")" << k1 << "sin(" << k2 << "x) dx" << std::endl;
}

TanIntegral::TanIntegral(double a, double b, double k1, double k2) : Integral(a, b), k1(k1), k2(k2) {}
double TanIntegral::calculate() const {
    if (std::abs(k2) < eps) {
        return 0.0;
    }
    return -(k1/k2) * (std::log(std::abs(std::cos(k2 * b)))-std::log(std::abs(std::cos(k2 * a))));
}
void TanIntegral::display() const {
    std::cout<<"int(" << a << "," << b << ")" << k1 << "tan(" << k2 << "x) dx" << std::endl;
}

