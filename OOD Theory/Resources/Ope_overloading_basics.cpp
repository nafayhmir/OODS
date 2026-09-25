#include <iostream> // Required for input/output operations
using namespace std;

class Complex {
private:
    double real;      // Stores the real part of the complex number
    double imaginary; // Stores the imaginary part of the complex number

public:
    //Default constructor: initializes a complex number to 0 + 0i
    Complex() : real(0.0), imaginary(0.0) {}

    // Parameterized constructor: initializes a complex number with given real and imaginary parts
    Complex(double r, double i) : real(r), imaginary(i) {}

    //Overloaded addition
    Complex operator+(Complex c)
    {
        Complex s;
        s.real=real+c.real;
        s.imaginary=imaginary+c.imaginary;
        return s;
    };
    //Overloaded Subtraction
    Complex operator-(Complex c)
    {
        Complex d;
        d.real=real-c.real;
        d.imaginary=imaginary-c.imaginary;
        return d;
    }
    // Method to display the complex number in "a + bi" format
    void display() const {
        cout << real;
        if (imaginary >= 0) {
            cout << " + " << imaginary << "i"<<endl;
        } else {
            cout << " - " << -imaginary << "i"<<endl;
        }
    }

    // addition of two complex numbers
    Complex add(Complex other) const {
        double r = real + other.real;
        double i = imaginary + other.imaginary;
        return Complex(r, i);
    }

    // subtraction of two complex numbers
    Complex subtract(Complex other) const {
        double r = real - other.real;
        double i = imaginary - other.imaginary;
        return Complex(r, i);
     //   return Complex(real - other.real, imaginary - other.imaginary);
    }

    // multiplication of two complex numbers
    Complex multiply(Complex other) const {
        double r = (real * other.real) - (imaginary * other.imaginary);
        double i = (real * other.imaginary) + (imaginary * other.real);
        return Complex(r, i);
    }
    
    //Overloading << (Output Operator)
    //ostream is used for << and istream is used for >>
    friend ostream& operator<<(ostream &a,Complex c)  //added friend as it outputs to ostream and not complex
    {
     a<<c.real<<"+"<<c.imaginary<<"i";
     return a;
    } 
    
};
class count{
private:
int c;
public:
void setc(int a)
{
    c=a;
}
int getc()
{
    return c;
}
count()
{
    c=0;
}
count(int a)
{
    c=a;
}
count& operator++() //Pre increment
{
    ++c;
    return *this;//Return current state of calling function
}
count operator++(int)//Post Increment
{
    count temp=*this; //Stores pre increment data in temp
    ++c; //Increments c
    return temp; //returns old state
}
void display()
{
    cout<<c;
}
};


int main()
{
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

    Complex sum2=num1+num2;
    cout<<"Operator Overloading: ";
    sum2.display(); //we can use << as it is now overloaded
    cout<<endl;
    cout<<sum2<<endl;

    cout<<"===============================";
    cout<<"Counter Arithmetic"<<endl;
    count c;
    int x;
    x=c.getc();
    cout<<x<<endl;
    ++c;
    x=c.getc();
    cout<<x<<endl;
    c++;
    x=c.getc();
    cout<<x<<endl;
    return 0;
}
