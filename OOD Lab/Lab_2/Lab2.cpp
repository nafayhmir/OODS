#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Book
{
  private:
     int book_ID;
     string author;
     string bookTitle; 
  public:
      Book(int a, string b, string c) 
      {
      	book_ID=a;
      	author=b;
      	bookTitle=c;
	  }
	  void setid_b(int a)
	  {
	  	book_ID=a;
	  }
	  void setau(string a)
	  {
	  	author=a;
	  }
	  void setti(string a)
	  {
	  	bookTitle=a;
	  }
	  int getid_b()
	  {
	  	return book_ID;
	  }
	  string getau()
	  {
	  	return author;
	  }
	  string getti()
	  {
	  	return bookTitle;
	  }
};

class Student
{
private:
    string studentName;         
    int rollNo;    
    int book_ID;    

public:
    Student(string a, int b, int c)
    {
    	studentName=a;
    	rollNo=b;
    	book_ID=c;
	}
	void setname(string a)
	{
		studentName=a;
	}
	void setroll(int a)
	{
		rollNo=a;
	}
	void setid_s(int a)
	{
		book_ID=a;
	}
	string getn()
	{
		return studentName;
	}
	int getroll()
	{
		return rollNo;
	}
	int getbookid_s()
	{
		return book_ID;
	}
};

int main()
{
	ifstream file("books.txt");
	if(!file.is_open())
	{
		cout<<"File is opening";
	}
	return 0;	
}

