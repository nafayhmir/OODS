// Assignment #2
// 25i-6180,Muhammad Nafayh Akhlaq
// All mentioned functions are working in header file
#include <iostream>
#include "25i6180-A2-string.h"
using namespace std;
int main()
{
    //Main is copied from book so formatting has problems, yet all intended operations are working.
    MyString str1 = "Sunny"; // initialize str1 using
    // the assignment operator
    const MyString str2("Warm"); // initialize str2 using the
    // conversion constructor
    MyString str3; // initialize str3 to the empty string
    MyString str4;                       // initialize str4 to the empty string
    cout << "Line 1: " << str1 << " " << str2<< " ***" << str3 << "###." << endl; // Line 1
    if (str1 <= str2)                         // compare str1 and str2; Line 2
        cout << "Line 3: " << str1 << " is less "
             << "than or equal to" << str2 << endl; // Line 3
    else                                            // Line 4
        cout << "Line 5: " << str2 << " is less "
             << "than " << str1 << endl; // Line 5

    cout << "Line 6: Enter a string with a length "
         << "of at least 7: "; // Line 6
    cin >> str1;               // input str1; Line 7
    cout << endl;              // Line 8
    cout << "Line 9: The new value of "
         << "str1 = " << str1 << endl; // Line 9
    str4 = str3 = "Birth Day";         // Line 10
    cout << "Line 11: str3 = " << str3
         << ", str4 = " << str4 << endl; // Line 11
    str3 = str1;                         // Line 12
    cout << "Line 13: The new value of str3 = "
         << str3 << endl; // Line 13
    str1 = "Bright Sky";  // Line 14
    str3[1] = str1[5];    // Line 15
    cout << "Line 16: After replacing the second "
         << "character of str3 = " << str3 << endl; // Line 16
    str3[2] = str2[0];                              // Line 17
    cout << "Line 18: After replacing the third "
         << "character of str3 = " << str3 << endl; // Line 18
    str3[5] = 'g';                                  // Line 19
    cout << "Line 20: After replacing the sixth "
         << "character of str3 = " << str3 << endl; // Line 20
    return 0;
}
