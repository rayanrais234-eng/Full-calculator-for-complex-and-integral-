#ifndef INTEGRAL_H
#define INTEGRAL_H

class Integral {
protected:
    double a;
    double b;

public:
    Integral() : a(0), b(0) {}
    Integral(double a, double b);
    Integral(const Integral& other);
    virtual ~Integral() = default;
    virtual double calculate() const = 0;
    virtual void display() const = 0;

    void setA(double a);
    void setB(double b);

    double getA() const;
    double getB() const;
};

class PowerIntegral final : public Integral {
private:
    double k;
    double n;
public:
    PowerIntegral(double a, double b, double k, double n);
    double calculate() const override;
    void display() const override;
};

class ExponentialIntegral final : public Integral {
private:
    double k1;
    double k2;
public:
    ExponentialIntegral(double a, double b, double k1, double k2);
    double calculate() const override;
    void display() const override;
};

class CosineIntegral final : public Integral {
private:
    double k1;
    double k2;
public:
    CosineIntegral(double a, double b, double k1, double k2);
    double calculate() const override;
    void display() const override;
};

class SinusIntegral final : public Integral {
private:
    double k1;
    double k2;
public:
    SinusIntegral(double a, double b, double k1, double k2);
    double calculate() const override;
    void display() const override;
};
class TanIntegral final : public Integral {
private: 
    double k1;
    double k2;
public:
    TanIntegral(double a, double b, double k1, double k2);
    double calculate() const override;
    void display() const override;
};

#endif
