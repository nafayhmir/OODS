//Lab 1, 25i-6180
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class book{
    private:
    string title;
    string author;
    double price;

    public:
    book() //Default Constructor
    {
        title=" ";
        author=" ";
        price=0;
    }
    book(string a,string b, double c) //Parameterized Constructor
    {
        title=a;
        author=b;
        price=c;
    }
    void sett(string a) //Set and Get Functions
    {
        title=a;
    }
    void seta(string b)
    {
        author=b;
    }
    void setp(double c)
    {
        price=c;
    }
    string gett()
    {
        return title;
    } 
    string geta()
    {
        return author;
    } 
    double getp()
    {
        return price;
    } 
   
};
    
int main()
{
book a("Car","Ali",55);
cout<<"Author: "<<a.geta()<<endl<<"Title: "<<a.gett()<<endl<<"Price: "<<a.getp();

}