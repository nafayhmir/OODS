#include <iostream>
using namespace std;
class Acc
{
private:
    double amount;

public:
    Acc()
    {
        amount = 0;
    }
    Acc(double a)
    {if (a > 0)
        {
            amount = a;
        }
        else
        {
            cout << "Negative value isn't possible";
        }
    }
    Acc operator+(double a) // Deposit
    {
        amount += a;
    }
    Acc operator-(double a) // Withdraw
    {
        amount -= a;
        return amount;
    }
    Acc &operator+=(Acc a)
    {
        double n;
        cout << "Transfer Amount:";
        cin >> n;
        amount += n;
        a.amount -= n;
        return a;
    }
    friend bool operator>(Acc a, Acc b) // Account Balance Comparison
    {
        bool k = 1;
        if (a.amount > b.amount)
        {
            k = 1;
        }
        else
        {
            k = 0;
        }
    }
    friend bool operator!(Acc a) // Checking Empty
    {
        bool k = 0;
        if (a.amount == 0)
        {
            k = 1;
        }
    }
    friend ostream &operator<<(ostream &out, Acc &a)
    {
        out << a.amount;
    }
};

int main()
{
    Acc a(1000);
    Acc b;
    b = b + 10.05; // Deposit
    b = b - 5.11;  // Withdraw
    a += b;
    bool g;
    g = a > b; // Which is bigger
    bool k;
    k = !b;
    cout << a << endl << b;
}