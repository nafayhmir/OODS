//Assignment #1
//25i-6180,Muhammad Nafayh Akhlaq
//All mentioned functions are working in header file

#include <iostream>
#include "25i6180-A1-class.h"
using namespace std;

int main()
{
    matrix a(1,0,0,0,1,0,0,0,1); //Matrix Declaration
    matrix b(1,2,3,4,5,6,7,8,9); //Matrix Declaration
    matrix c,d,e,f; 
    c=a+b; //Summing A and B
    d=a-b; //Subtracting A and B
    e=a*b; //Multiplying A and B
    f=a*8; //Scalar Multiplication
    bool t1,t2,t3;
    t1=!a;//Is Matrix an Identity Matrix
    t2=a==b;// Are both matrices same
    t3=a<b;// Is left matrix larger than right matrix
    cout<<"Matrix A:"<<endl<<a; //Using << to display Matrix A

    cout<<"Sum"<<endl<<c;
    cout<<endl<<"Difference"<<endl<<d;
    cout<<endl<<"Multiplication"<<endl<<e;
    cout<<endl<<"Scalar Multiplication by 8"<<endl<<f;
    cout<<"Is A matrix an identity (1=True,0=False): "<<t1<<endl;
    cout<<"Is A and B matrix same (1=True,0=False): "<<t2<<endl;
    cout<<"Is sum of A larger than B (1=True,0=False): "<<t3;
}

