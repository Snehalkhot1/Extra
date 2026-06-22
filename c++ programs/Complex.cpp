#include <iostream>
using namespace std;

class Complex {
private:
    int real;
    int imag;

public:

    Complex(int r = 0, int i = 0) {
        real = r;
        imag = i;
    }

    void input() {
        cout << "Enter real part: ";
        cin >> real;
        cout << "Enter imaginary part: ";
        cin >> imag;
    }

    void display() {
        if (imag >= 0)
            cout << real << " + " << imag << "i" << endl;
        else
            cout << real << " - " << -imag << "i" << endl;
    }

    Complex add(Complex c) {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex subtract(Complex c) {
        return Complex(real - c.real, imag - c.imag);
    }
};

int main() {
    Complex c1, c2, sum, diff;

    cout << "Enter first complex number:\n";
    c1.input();

    cout << "Enter second complex number:\n";
    c2.input();

    cout << "\nFirst complex number: ";
    c1.display();

    cout << "Second complex number: ";
    c2.display();

    sum = c1.add(c2);
    diff = c1.subtract(c2);

    cout << "\nAddition: ";
    sum.display();

    cout << "Subtraction: ";
    diff.display();

    return 0;
}