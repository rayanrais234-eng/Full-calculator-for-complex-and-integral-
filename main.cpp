#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <cmath>
#include "Complex Calculator/complex.h"
#include "Integral Calculator/integral.h"

using namespace std;

int main() {
    int choice;
    do {
    cout << "Welcome to the Calculator!" << endl;
    cout << "Please select an option:" << endl;
    cout << "1. Complex Number Operations" << endl;
    cout << "2. Integral Calculations" << endl;
    cout << "3. Exit" << endl;
    cin >> choice;

    switch (choice) {
        case 1: {
            Complex c1;
            Complex c2;
            cout << "Please enter a complex number in the form (a + ib): ";
            string complexInput;
            cin.ignore();
            getline(cin, complexInput);
            {
                istringstream iss(complexInput);
                double real, imag;
                char sign, i;
                if (iss >> real >> sign >> imag >> i && (sign == '+' || sign == '-') && i == 'i') {
                    if (sign == '-') imag = -imag;
                     c1 = Complex(real, imag);
                    cout << "You entered: " << endl;
                    c1.display();
                } else {
                    cout << "Invalid complex number format." << endl;
                }
            }
            cout << "Please enter a second complex number in the form (a + ib): ";
            string complexInput2;
            getline(cin, complexInput2);
            {
                istringstream iss(complexInput2);
                double real, imag;
                char sign, i;
                if (iss >> real >> sign >> imag >> i && (sign == '+' || sign == '-') && i == 'i') {
                    if (sign == '-') imag = -imag;
                    c2 = Complex(real, imag);
                    cout << "You entered: " << endl;
                    c2.display();
                } else {
                    cout << "Invalid complex number format." << endl;
                }
            }
            cout << "Please choose an operation:" << endl;
            cout << "1. Addition" << endl;
            cout << "2. Subtraction" << endl;
            cout << "3. Multiplication" << endl;
            cout << "4. Division" << endl;
            cout << "5. Power" << endl;
            cout << "6. Exponential" << endl;
            int operation;
            cin >> operation;
            switch (operation) {
                case 1: {
                    Complex c3 = c1 + c2;
                    cout << "Result: " << endl;
                    c3.display();
                    break;
                }
                case 2: {
                    Complex c4 = c1 - c2;
                    cout << "Result: " << endl;
                    c4.display();
                    break;
                }
                case 3: {
                    Complex c5 = c1 * c2;
                    cout << "Result: " << endl;
                    c5.display();
                    break;
                }
                case 4: {
                    Complex c6 = c1 / c2;
                    cout << "Result: " << endl;
                    c6.display();
                    break;
                }
                case 5: {
                    cout << "choose a power: ";
                    int power;
                    cin >> power;
                    Complex c7 = c1 ^ power;
                    Complex c8 = c2 ^ power;
                    cout << "Result: " << endl;
                    c7.display();
                    cout << ", " << endl;
                    c8.display();
                    break;
                }
                case 6: {
                    cout << "choose a base: ";
                    double base;
                    cin >> base;
                    Complex c9 = c1.pow(base);
                    Complex c10 = c2.pow(base);
                    cout << "Result: " << endl;
                    c9.display();
                    cout << ", " << endl;
                    c10.display();
                    break;
                }
                default:
                    cout << "Invalid operation. Please try again." << endl;
                    break;
            }
            break;
        } case 2: {
            cout << "Please choose the type of definite integral:" << endl;
            cout << "1. Power integral" << endl;
            cout << "2. Exponential integral" << endl;
            cout << "3. Cosine integral" << endl;
            cout << "4. Sine integral" << endl;
            cout << "5. Tangent integral" << endl;
            int integralType;
            cin >> integralType;
            switch (integralType) {
                case 1: {
                    cout << "Please enter a function for power integral in the form int(a,b)kx^n:" << endl;
                    string PowerInput;
                    cin.ignore();
                    getline(cin, PowerInput);
                size_t Int = PowerInput.find("int(");
                size_t Comma = PowerInput.find(",");
                size_t CloseInt = PowerInput.find(")");
                size_t X = PowerInput.find("x^");
                if (Int != string::npos && Comma != string::npos && CloseInt != string::npos && X != string::npos) {
                    double a = stod(PowerInput.substr(Int + 4, Comma - Int - 4));
                    double b = stod(PowerInput.substr(Comma + 1, CloseInt - Comma - 1));
                    double k = stod(PowerInput.substr(CloseInt + 1, X - CloseInt - 1));
                    double n = stod(PowerInput.substr(X + 2));
                    PowerIntegral p(a, b, k, n);
                    cout << "You entered: integral" << endl;
                    p.display();
                    cout << "Result: " << p.calculate() << endl;
                } else {
                    cout << "Invalid power integral format." << endl;
                }
                break;
            } case 2: {
                cout << "Please enter a function for exponential integral in the form int(a,b)k1e^k2x:" << endl;
                string ExponentialInput;
                cin.ignore();
                getline(cin, ExponentialInput);
                size_t Int = ExponentialInput.find("int(");
                size_t Comma = ExponentialInput.find(",");
                size_t CloseInt = ExponentialInput.find(")");
                size_t E = ExponentialInput.find("e^");
                size_t X = ExponentialInput.find("x");
                if (Int != string::npos && Comma != string::npos && CloseInt != string::npos && E != string::npos && X != string::npos) {
                    double a = stod(ExponentialInput.substr(Int + 4, Comma - Int - 4));
                    double b = stod(ExponentialInput.substr(Comma + 1, CloseInt - Comma - 1));
                    double k1 = stod(ExponentialInput.substr(CloseInt + 1, E - CloseInt - 1));
                    double k2 = stod(ExponentialInput.substr(E + 2, X - E - 2));
                    ExponentialIntegral e(a, b, k1, k2);
                    cout << "You entered: integral" << endl;
                    e.display();
                    cout << "Result: " << e.calculate() << endl;
                } else {
                    cout << "Invalid exponential integral format." << endl;
                }
                break;
            } case 3: {
                cout << "Please enter a function for cosine integral in the form int(a,b)k1cos(k2x):" << endl;
                string CosineInput;
                cin.ignore();
                getline(cin, CosineInput);
                size_t Int = CosineInput.find("int(");
                size_t Comma = CosineInput.find(",");
                size_t CloseInt = CosineInput.find(")");
                size_t Cos = CosineInput.find("cos(");
                size_t X = CosineInput.find("x");
                if (Cos != string::npos && X != string::npos && Comma != string::npos && Int != string::npos && CloseInt != string::npos) {
                        double a = stod(CosineInput.substr(Int + 4, Comma - Int - 4));
                        double b = stod(CosineInput.substr(Comma + 1, CloseInt - Comma - 1));
                        double k1 = stod(CosineInput.substr(CloseInt + 1,Cos - (CloseInt + 1)));
                        double k2 = stod(CosineInput.substr(Cos + 4,X - (Cos + 4)));
                        CosineIntegral c(a, b, k1, k2);
                        cout << "You entered: integral" << endl;
                        c.display();
                        cout << "Result: " << c.calculate() << endl;
                    } else {
                        cout << "Invalid cosine integral format." << endl;
                    }
                break;
            } case 4: {
                cout << "Please enter a function for sine integral in the form int(a,b)k1sin(k2x):" << endl;
                string SineInput;
                cin.ignore();
                getline(cin, SineInput);
                size_t Int = SineInput.find("int(");
                size_t Comma = SineInput.find(",");
                size_t CloseInt = SineInput.find(")");
                size_t Sin = SineInput.find("sin(");
                size_t X = SineInput.find("x");
                if (Int != string::npos && Comma != string::npos && CloseInt != string::npos && Sin != string::npos && X != string::npos) {
                    double a = stod(SineInput.substr(Int + 4, Comma - Int - 4));
                    double b = stod(SineInput.substr(Comma + 1, CloseInt - Comma - 1));
                    double k1 = stod(SineInput.substr(CloseInt + 1, Sin - CloseInt - 1));
                    double k2 = stod(SineInput.substr(Sin + 4, X - Sin - 4));
                    SinusIntegral s(a, b, k1, k2);
                    cout << "You entered: integral" << endl;
                    s.display();
                    cout << "Result: " << s.calculate() << endl;
                } else {
                    cout << "Invalid sine integral format." << endl;
                }
                break;
            } case 5: {
                cout << "Please enter a function for tangent integral in the form int(a,b)k1tan(k2x):" << endl;
                string TangentInput;
                cin.ignore();
                getline(cin, TangentInput);
                size_t Int = TangentInput.find("int(");
                size_t Comma = TangentInput.find(",");
                size_t CloseInt = TangentInput.find(")");
                size_t Tan = TangentInput.find("tan(");
                size_t X = TangentInput.find("x");
                if (Int != string::npos && Comma != string::npos && CloseInt != string::npos && Tan != string::npos && X != string::npos) {
                    double a = stod(TangentInput.substr(Int + 4, Comma - Int - 4));
                    double b = stod(TangentInput.substr(Comma + 1, CloseInt - Comma - 1));
                    double k1 = stod(TangentInput.substr(CloseInt + 1, Tan - CloseInt - 1));
                    double k2 = stod(TangentInput.substr(Tan + 4, X - Tan - 4));
                    TanIntegral t(a, b, k1, k2);
                    cout << "You entered: integral" << endl;
                    t.display();
                    cout << "Result: " << t.calculate() << endl;
                } else {
                    cout << "Invalid tangent integral format." << endl;
                }
                break;
            } default: {
                    cout << "Invalid integral type. Please try again." << endl;
                }
                break;
            }
        } case 3: {
            cout << "Exiting the Calculator. Goodbye!" << endl;
            break;
         }}
        } while (choice != 3);
    return 0;
    }
