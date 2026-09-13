#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

using namespace std;

class MyString
{
private:
    char *strPtr;
    int strLength;

public:
    MyString() //Default Constructor
    {
        strLength = 0;
        strPtr = new char[1];
        strPtr[0] = '\0';
    }

    MyString(const char *s) // copy Constructor
    {
        if (s == nullptr)
        {
            strLength = 0;
            strPtr = new char[1];
            strPtr[0] = '\0';
        }
        else
        {
            strLength = 0;
            while (s[strLength] != '\0')
            {
                strLength++; //Calculate length
            }

            strPtr = new char[strLength + 1]; //declaration of dynamic char array
            for (int i = 0; i < strLength; i++)
            {
                strPtr[i] = s[i];
            }
            strPtr[strLength] = '\0'; //adding null at end of char array
        }
    }

    MyString(const MyString &other) 
    {
        strLength = other.strLength;
        strPtr = new char[strLength + 1];
        for (int i = 0; i <= strLength; i++)
        {
            strPtr[i] = other.strPtr[i];
        }
    }

    ~MyString() //deconstructor
    {
        delete[] strPtr;
    }

    MyString &operator=(const MyString &other) //overloaded = operator
    {
        if (this != &other) //calling function
        {
            delete[] strPtr;
            strLength = other.strLength;
            strPtr = new char[strLength + 1];
            for (int i = 0; i <= strLength; i++)
            {
                strPtr[i] = other.strPtr[i];
            }
        }
        return *this;
    }

    char &operator[](int index) //overloading [] operator for our class
    {
        return strPtr[index];
    }

    const char &operator[](int index) const //required if we use strings that should not be changed
    {
        return strPtr[index];
    }

    int length()
    {
        return strLength;
    }

    const char *c_str() const
    {
        return strPtr;
    }

    bool operator==(const MyString &right) const
    {
        int i = 0;
        while (strPtr[i] != '\0' && right.strPtr[i] != '\0') //checks if any string starts at null
        {
            if (strPtr[i] != right.strPtr[i])
                return false;
            i++;
        }
        return strPtr[i] == right.strPtr[i];
    }

    bool operator!=(const MyString &right) const
    {
        return !(*this == right); //checks if both obj are same
    }

    bool operator<(const MyString &right) const //checks if right object is larger
    {
        int i = 0;
        while (strPtr[i] != '\0' && right.strPtr[i] != '\0')
        {
            if (strPtr[i] != right.strPtr[i])
                return strPtr[i] < right.strPtr[i];
            i++;
        }
        return strPtr[i] < right.strPtr[i];
    }

    bool operator<=(const MyString &right) const
    {
        return (*this < right) || (*this == right);
    }

    bool operator>(const MyString &right) const
    {
        return !(*this <= right);
    }

    bool operator>=(const MyString &right) const
    {
        return !(*this < right);
    }

    MyString operator+(const MyString &right) const //adding two strings
    {
        MyString temp;
        delete[] temp.strPtr;

        temp.strLength = strLength + right.strLength;
        temp.strPtr = new char[temp.strLength + 1];

        for (int i = 0; i < strLength; i++)
        {
            temp.strPtr[i] = strPtr[i];
        }
        for (int j = 0; j <= right.strLength; j++)
        {
            temp.strPtr[strLength + j] = right.strPtr[j];
        }

        return temp;
    }

    MyString &operator+=(const MyString &right)
    {
        *this = *this + right;
        return *this;
    }

    friend ostream &operator<<(ostream &os, const MyString &str)
    {
        os << str.strPtr;
        return os;
    }

    friend istream &operator>>(istream &is, MyString &str)
    {
        char temp[1024];
        if (is >> temp)
        {
            str = temp;
        }
        return is;
    }
};
#endif