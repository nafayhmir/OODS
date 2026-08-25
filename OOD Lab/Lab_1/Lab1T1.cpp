#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Book {
private:
    string title;
    string author;
    string price;

public:
    // Default Constructor
    Book() 
    {
        title = "";
        author = "";
        price = 0.0;
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
    void display() const {
        cout<<title<<endl<<author<<endl<<price<<endl;
    }
};

int main() {
    ifstream file("books.txt");
    Book books[10];
    int count=0;

    if (!file.is_open()) {
        cout << "Error: Could not open Books.txt" << endl;
        return 1;
    }

    cout << "File opened successfully. Reading data...\n";
    string title, author, price;
    while (count < 10 && getline(file, title)) {
        if (!getline(file, author)) break;
        if (!getline(file, price)) break;
        books[count].setTitle(title);
        books[count].setAuthor(author);
        books[count].setPrice(price);
        count++;
    }

    file.close();
    for (int i = 0; i < count; i++) {
        books[i].display();
    }

    return 0;
}