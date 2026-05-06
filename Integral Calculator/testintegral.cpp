#include<iostream> 
#include<cmath>
#include "integral.h"
constexpr double e = 2.718281828459045;
constexpr double PI = 3.141592653589793;

int pass = 0;
int fail = 0;
double eps = 1e-9; 

int main() {
PowerIntegral p(0, 1, 2, 3);
p.display();
double result1 = p.calculate();
if (std::abs(result1 - 0.5) < eps) {
    std::cout << "PowerIntegral test passed!" << std::endl;
    pass++;
} else {
    std::cout << "PowerIntegral test failed!" << std::endl;
    fail++;
}
ExponentialIntegral e(0, 5, 2, 0);
e.display();
double result2 = e.calculate();
if (std::abs(result2 - 10.0) < eps) {
    std::cout << "ExponentialIntegral test passed!" << std::endl;
    pass++;
} else {
    std::cout << "ExponentialIntegral test failed!" << std::endl;
    fail++;
}
CosineIntegral c(0, 2*PI/3, 2, 3);
c.display();
double result3 = c.calculate();
if (std::abs(result3) < eps) {
    std::cout << "CosineIntegral test passed!" << std::endl;
    pass++;
} else {
    std::cout << "CosineIntegral test failed!" << std::endl;
    fail++;
}
SinusIntegral s(0, 2*PI/3, 2, 3);
s.display();
double result4 = s.calculate();
if (std::abs(result4) < eps) {
    std::cout << "SinusIntegral test passed!" << std::endl;
    pass++;
} else {
    std::cout << "SinusIntegral test failed!" << std::endl;
    fail++;
}
TanIntegral t(0, PI/3, 2, 3);
t.display();
double result5 = t.calculate();
if (std::abs(result5) < eps) {
    std::cout << "TanIntegral test passed!" << std::endl;
    pass++;
} else {
    std::cout << "TanIntegral test failed!" << std::endl;
    fail++;
}

std::cout << "Total tests passed: " << pass << std::endl;
std::cout << "Total tests failed: " << fail << std::endl;

return 0;
}
