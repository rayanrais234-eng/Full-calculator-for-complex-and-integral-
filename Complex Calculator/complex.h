#ifndef COMPLEX_H
#define COMPLEX_H

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0.0, double i = 0.0);
    static Complex fromPolar(double magnitude = 1.0, double angle = 0.0);
    Complex(const Complex& c);

    void setReal(double r);
    void setImag(double i);
    double getReal() const;
    double getImag() const;
    void display() const;

    double getMagnitude() const;
    Complex getConjugate() const;
    double getAngle() const;

    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex operator/(const Complex& other) const;
    Complex operator^(double n) const;
    Complex pow(double base) const;

    void getPolarForm(Complex& a) const;
    void displayPolarForm() const;
};

#endif