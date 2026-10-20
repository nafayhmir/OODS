// Assignment #3
// 25i-6180,Muhammad Nafayh Akhlaq
// All mentioned functions are working in main file
#include <iostream>
#include <fstream>
#include "25i6180-A3-Hashing.h"

using namespace std;

int main()
{
    int tableSize = 9973;
    HashChain hashTable(tableSize);

    cout << "Loading repository file 'words.txt'..." << endl;
    if (!loadDictionary(hashTable, "words.txt"))
    {
        return 1;
    }
    cout << "'words.txt' loaded successfully!" << endl;

    hashTable.printLoadFactor();

    int choice = 0;
    do
    {
        cout << "===========================" << endl;
        cout << "    SPELL CHECKER MENU     " << endl;
        cout << "===========================" << endl;
        cout << "1. Command Line Input" << endl;
        cout << "2. Read 'words.txt' File" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter choice (1-3): ";

        if (!(cin >> choice))
        {
            if (cin.eof())
            {
                cout << "\nEnd of input stream detected. Exiting program..." << endl;
                break;
            }
            cin.clear();
            cin.ignore(10000, '\n');
            choice = 0;
            cout << "Invalid choice! Try again.\n" << endl;
            continue;
        }

        cin.ignore(10000, '\n');

        if (choice == 1)
        {
            cout << "\nEnter your text: ";
            string inputLine;
            getline(cin, inputLine);
            processText(inputLine, hashTable);
        }
        else if (choice == 2)
        {
            ifstream inFile("words.txt");
            if (!inFile.is_open())
            {
                cout << "Error: 'words.txt' not found!" << endl;
                continue;
            }

            string content((istreambuf_iterator<char>(inFile)), istreambuf_iterator<char>());
            inFile.close();

            ofstream outFile("output.txt");
            processText(content, hashTable, &outFile);
            outFile.close();

            cout << "\nResult saved to 'output.txt'." << endl;
        }
        else if (choice == 3)
        {
            cout << "Exiting program..." << endl;
        }
        else
        {
            cout << "Invalid choice! Try again." << endl;
        }

        cout << endl;
    } while (choice != 3);

    return 0;
}