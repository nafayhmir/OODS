#include <iostream>
#include "25i6180-A1-class.h"
using namespace std;

int main()
{
    matrix a(1,0,0,0,1,0,0,0,1);
    matrix b(1,2,3,4,5,6,7,8,9);
    matrix c,d,e,f;
    c=a+b;
    d=a-b;
    e=a*b;
    f=a*8;
    bool t1,t2,t3;
    t1=!a;//Is a identity
    t2=a==b;//if same 
    t3=a<b;//if b is larger
    cout<<"Matrix A:"<<endl<<a;

    cout<<"Sum"<<endl<<c;
    cout<<endl<<"Difference"<<endl<<d;
    cout<<endl<<"Multiplication"<<endl<<e;
    cout<<endl<<"Scalar Multiplication by 8"<<endl<<f;
    cout<<"Is A matrix an identity (1=True,0=False): "<<t1<<endl;
    cout<<"Is A and B matrix same (1=True,0=False): "<<t2<<endl;
    cout<<"Is sum of A larger than B (1=True,0=False): "<<t3;
}