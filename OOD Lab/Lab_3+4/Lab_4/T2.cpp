#include <iostream>
using namespace std;

class Matrix
{
private:
    int arr[2][2];

public:
    Matrix()
    {
        int a = 0;
        arr[0][0] = a;
        arr[0][1] = a;
        arr[1][0] = a;
        arr[1][1] = a;
    }
    Matrix(int a, int b, int c, int d)
    {
        arr[0][0] = a;
        arr[0][1] = b;
        arr[1][0] = c;
        arr[1][1] = d;
    }
    friend Matrix operator+(Matrix a, Matrix b);   // Matrix Addition
    friend Matrix operator-(Matrix a, Matrix b);   // Matrix Subtraction
    friend Matrix operator-=(Matrix &a, Matrix b); // Matrix Subtraction
    friend bool operator==(Matrix a, Matrix b);
    friend ostream &operator<<(ostream &out, Matrix &m);
    friend istream &operator>>(istream &in, Matrix &m);
};
Matrix operator+(Matrix a, Matrix b) // Matrix Addition
{
    Matrix c;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            c.arr[i][j] = a.arr[i][j] + b.arr[i][j];
        }
    }
    return c;
}

Matrix operator-(Matrix a, Matrix b) // Matrix Subtraction
{
    Matrix c;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            c.arr[i][j] = a.arr[i][j] - b.arr[i][j];
        }
    }
    return c;
}
Matrix operator-=(Matrix &a, Matrix b)
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            a.arr[i][j] -= b.arr[i][j];
        }
    }
    return a;
}
istream &operator>>(istream &in, Matrix &m)
{

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            in >> m.arr[i][j];
        }
    }
    return in;
}
ostream &operator<<(ostream &out, Matrix &m)
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            out << m.arr[i][j] << "\t";
        }
    }
    return out;
}
bool operator==(Matrix a, Matrix b)
{
    bool k = 1;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (a.arr[i][j] != b.arr[i][j])
            {
                k = 0;
            }
        }
    }
    return k;
}
int main()
{
    Matrix m1(1, 2, 3, 4);
    Matrix m2(5, 6, 7, 8);
    cout << "Matrix 1:" << endl
         << m1 << endl;
    cout << "Matrix 2:" << endl
         << m2 << endl;

    cout << "--- Testing Input Operator (>>) ---" << endl;
    Matrix m3;
    cout << "Enter 4 space-separated integers for Matrix 3: ";
    cin >> m3;
    cout << "You entered Matrix 3:" << endl
         << m3 << endl;

    cout << "--- Testing Addition Operator (+) ---" << endl;
    Matrix sum = m1 + m2;
    cout << "m1 + m2 = " << endl
         << sum << endl;

    cout << "--- Testing Subtraction Operator (-) ---" << endl;
    Matrix diff = m2 - m1;
    cout << "m2 - m1 = " << endl
         << diff << endl;

    cout << "--- Testing Compound Subtraction (-=) ---" << endl;
    cout << "Original m2:" << endl
         << m2 << endl;
    m2 -= m1; // Modifies m2 in-place
    cout << "m2 after (m2 -= m1):" << endl
         << m2 << endl;

    cout << "--- Testing Equality Operator (==) ---" << endl;
    Matrix m4(1, 2, 3, 4);

    if (m1 == m4)
    {
        cout << "m1 and m4 are EQUAL." << endl;
    }
    else
    {
        cout << "m1 and m4 are NOT equal." << endl;
    }

    if (m1 == m3)
    {
        cout << "m1 and m3 are EQUAL." << endl;
    }
    else
    {
        cout << "m1 and m3 are NOT equal." << endl;
    }

    return 0;
}