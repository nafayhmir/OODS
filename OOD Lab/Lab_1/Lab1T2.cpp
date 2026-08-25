//Lab 1 Task2
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Book 
{
    private:
        string title;
        string author;
        string price;

    public:
        Book() 
        {
            title = "";
            author = "";
            price="0";
        }

        // Parameterized Constructor
        Book(string t, string a, string p) 
        {
            title = t;
            author = a;
            price = p;
        }
        void setTitle(string t)  { title = t; }
        void setAuthor(string a) { author = a; }
        void setPrice(string p)  { price = p; }

        string getTitle()  const 
        {
        return title; 
        }
        string getAuthor() const 
        {
        return author; 
        }
        string getPrice()  const 
        { 
        return price; 
        }
        void dis() const {
            cout<<title<<endl<<author<<endl<<price<<endl;
        }
};

class student
{
    private:
        string name;
        int rollno;
        double cgpa;
        Book books[7];

    public:
        student()
        {
            name="";
            rollno=0;
            cgpa=0;
            for(int i=0;i<7;i++)
            {
                books[i].setTitle(" ");
                books[i].setAuthor(" ");
                books[i].setPrice(0);
            }
        }
        student(string s,int r,double c)
        {
            name=s;
            rollno=r;
            cgpa=c;
        }
        void setn(string n){name=n;}
        void setrol(int n){rollno=n;}
        void setcgp(double n){cgpa=n;}

        string getn(){return name;}
        int getrol(){return rollno;}
        double getcgpa(){return cgpa;}

        void display()
        {
            cout<<"Name:"<<name<<endl;
            cout<<"Roll No:"<<rollno<<endl;
            cout<<"CGPA:"<<cgpa<<endl;
            for (int i=0;i<7;i++)
            {
                books[i].dis();
            }
        }
        void setAllBooks(Book bookArr[], int count) 
        {
            for (int i = 0; i < 7 && i < count; i++) 
            {
                books[i] = bookArr[i];
            }
        }
};

int main()
{
    cout<<"Enter New Name: ";
    string n;
    cin>>n;
    cout<<"RollNo:";
    int r;
    cin>>r;
    cout<<"CGPA";
    double c;
    cin>>c;

    student s(n,r,c);
    s.display();
}