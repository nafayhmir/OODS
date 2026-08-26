#include <iostream> // Required for input/output operations
using namespace std;

class Complex {
private:
    double real;      // Stores the real part of the complex number
    double imaginary; // Stores the imaginary part of the complex number

public:
    // Default constructor: initializes a complex number to 0 + 0i
   // Complex() : real(0.0), imaginary(0.0) {}

    // Parameterized constructor: initializes a complex number with given real and imaginary parts
    Complex(double r, double i) : real(r), imaginary(i) {}

    void display() const;
    Complex add(Complex) const;
    Complex subtract(Complex) const;
    Complex multiply(Complex) const;
};


    // Method to display the complex number in "a + bi" format
    void Complex::display() const {
        cout << real;
        if (imaginary >= 0) {
            cout << " + " << imaginary << "i"<<endl;
        } else {
            cout << " - " << -imaginary << "i"<<endl;
        }
    }

    // addition of two complex numbers
    Complex Complex::add(Complex other) const {
        double r = real + other.real;
        double i = imaginary + other.imaginary;
        return Complex(r, i);
    }

    // subtraction of two complex numbers
    Complex Complex::subtract(Complex other) const {
        double r = real - other.real;
        double i = imaginary - other.imaginary;
        return Complex(r, i);
     //   return Complex(real - other.real, imaginary - other.imaginary);
    }

    // multiplication of two complex numbers
    Complex Complex::multiply(Complex other) const {
        double r = (real * other.real) - (imaginary * other.imaginary);
        double i = (real * other.imaginary) + (imaginary * other.real);
        return Complex(r, i);
    }


int main() {
    cout << "=== Complex Number Operations ===" << endl;

    // Create complex numbers
    Complex num1(3, 4);   // 3 + 4i
    Complex num2(1, -2);  // 1 - 2i

    // Display numbers
    cout << "Number 1: ";
    num1.display();
    cout << endl;

    cout << "Number 2: ";
    num2.display();
    cout << endl;

    // Perform operations
    Complex sum = num1.add(num2);
    cout << "Addition: ";
    sum.display();
    cout << endl;

    Complex diff = num1.subtract(num2);
    cout << "Subtraction: ";
    diff.display();
    cout << endl;

    Complex product = num1.multiply(num2);
    cout << "Multiplication: ";
    product.display();
    cout << endl;


    return 0;
}


