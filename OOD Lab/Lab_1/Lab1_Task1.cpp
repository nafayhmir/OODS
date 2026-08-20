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
   void display()
   {
    cout<<gett()<<endl<<geta()<<endl<<getp()<<endl;
   }
};

int main()
{
    ifstream file("books_list.txt");
    book b[10];

    if (file.is_open())
    {
        cout << "File has opened retrieving data";
    }

    string title, author;
    double price;
    int i = 0;

    while (file >> title >> author >> price && i < 10)
    {
        b[i].sett(title);
        b[i].seta(author);
        b[i].setp(price);
        i++;
    }
    file.close();
    
    for (int i=0; i < 10; i++)
    {
        cout <<endl << b[i].gett();
    }
    
return 0;
}
