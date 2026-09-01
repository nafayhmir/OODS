#include <iostream>
using namespace std;

class vector
{
    private:
        double x;
        double y;
    public:
        vector()
        {
            x=0;y=0;
        }
        vector(double a,double b)
        {
            x=a;y=b;
        }
        void sety(double a)
        {
            y=a;
        }
        void setx(double a)
        {
            x=a;
        }
        double getx()
        {
            return x;
        }
        double gety()
        {
            return y;
        }
        vector operator+(vector a)//vector addition
        {
            vector b(0,0);
            b.x=x+a.x;
            b.y=y+a.y;
            return b;
        }
        vector operator-(vector a)//vector subtraction
        {
            vector b(0,0);
            b.x=x-a.x;
            b.y=y-a.y;
            return b;
        }
        vector operator*(double s)//Scalar Multiplication
        {
            x=s*x;
            y=s*y;
        }
        vector operator/(double s) //Scalar Division
        {
            x=x/s;
            y=y/s;
        }
        void display()
        {
            cout<<x<<endl<<y;
        }
};
int main()
{
    vector a(2,3);
    vector c(8,8);
    vector d;
    d=a+c;
    vector f;
    f=a-c;
    cout<<"Sum of Two Vectors:"<<endl;
    d.display();
    vector t1,t2;
    cout<<endl<<"Difference between two vectors:"<<endl;
    f.display();
    t1=a*5;
    t2=c/2;
    cout<<endl<<"Scalar Multiplication"<<endl;
    t1.display();
    cout<<endl<<"Scalar Division"<<endl;
    t2.display();
}