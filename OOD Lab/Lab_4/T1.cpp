#include <iostream>
using namespace std;

class Vector2D
{
private:
	int x;
	int y;
public:
	Vector2D()
	{
		x = 0;
		y = 0;
	}
	Vector2D(int a, int b)
	{
		x = a;
		y = b;
	}
	int getX() const { return x; }
	int getY() const { return y; }

	// Friend operator declarations
	friend Vector2D operator+(Vector2D obj, Vector2D b);
	friend Vector2D operator-(Vector2D obj, Vector2D b);
	friend Vector2D operator*(int scalar, Vector2D b);
	friend int operator*(Vector2D obj, Vector2D b); // Added Dot Product
	friend Vector2D& operator+=(Vector2D& obj, const Vector2D& obj2);
	friend bool operator==(Vector2D obj, Vector2D obj2);
	friend istream& operator>>(istream& a, Vector2D& obj);
	friend ostream& operator<<(ostream& b, const Vector2D& obj);
};

Vector2D operator+(Vector2D obj, Vector2D b)
{
	return Vector2D(obj.x + b.x, obj.y + b.y);
}

// Fixed subtraction order: Left - Right
Vector2D operator-(Vector2D obj, Vector2D b)
{
	return Vector2D(obj.x - b.x, obj.y - b.y);
}

// Scalar Multiplication (int * Vector2D)
Vector2D operator*(int scalar, Vector2D b)
{
	return Vector2D(b.x * scalar, b.y * scalar);
}

// Vector Dot Product (Vector2D * Vector2D)
int operator*(Vector2D obj, Vector2D b)
{
	return (obj.x * b.x) + (obj.y * b.y);
}

// Fixed Pass-by-reference and return statement
Vector2D& operator+=(Vector2D& obj, const Vector2D& obj2)
{
	obj.x += obj2.x;
	obj.y += obj2.y;
	return obj;
}

bool operator==(Vector2D obj, Vector2D obj2)
{
	return (obj.x == obj2.x) && (obj.y == obj2.y);
}

istream& operator>>(istream& a, Vector2D& obj)
{
	a >> obj.x >> obj.y;
	return a;
}

ostream& operator<<(ostream& b, const Vector2D& obj)
{
	b << "(" << obj.x << ", " << obj.y << ")";
	return b;
}

int main()
{
	Vector2D A(6, 2), B(4, 3), C(0, 0);

	C += B;
	bool k = (A == B);

	cout << "+= Operator: " << C << endl;
	cout << "+ Operator: " << A + B << endl;
	cout << "- Operator: " << A - B << endl;
	cout << "* Operator (Scalar): " << 2 * A << endl;
	cout << "* Operator (Dot Product): " << A * B << endl;
	cout << "== Operator: " << (k ? "true" : "false") << endl;

	cout << "Enter X and Y for Vector D: ";
	Vector2D D;
	cin >> D;
	cout << "Vector D: " << D << endl;

	return 0;
}