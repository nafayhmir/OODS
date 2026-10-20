// Assignment #3
// 25i-6180,Muhammad Nafayh Akhlaq
// All mentioned functions are working in header file
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

#ifndef HASHCHAIN_H
#define HASHCHAIN_H

class HashChain
{
private:
    list<string>* Table;
    int size;
    int totalWords;

    int hashFunction(const string& key) const
    {
        if (size <= 0)
        {
            return 0;
        }
        unsigned long long hash = 0;
        for (char c : key)
        {
            hash = (hash * 31 + static_cast<unsigned char>(c)) % size;
        }
        return static_cast<int>(hash);
    }

public:
    HashChain(int tableSize) // Parameterized Constructor
    {
        size = (tableSize > 0) ? tableSize : 9973;
        totalWords = 0;
        Table = new list<string>[size];
    }

    ~HashChain() // Destructor
    {
        delete[] Table;
    }

    void insert(string word)
    {
        int index = hashFunction(word);
        Table[index].push_back(word);
        totalWords++;
    }

    bool search(string word) const
    {
        int index = hashFunction(word);
        for (const string& item : Table[index])
        {
            if (item == word)
            {
                return true;
            }
        }
        return false;
    }

    void printLoadFactor() const
    {
        int nonEmptySlots = 0;
        for (int i = 0; i < size; i++)
        {
            if (!Table[i].empty())
            {
                nonEmptySlots++;
            }
        }

        if (nonEmptySlots > 0)
        {
            double loadFactor = (double)totalWords / nonEmptySlots;
            cout << "\n--- HASH TABLE STATS ---" << endl;
            cout << "Total Words: " << totalWords << endl;
            cout << "Non-Empty Slots: " << nonEmptySlots << " / " << size << endl;
            cout << "Load Factor: " << loadFactor << endl;
            cout << "------------------------\n" << endl;
        }
    }
};

inline string cleanWord(string word)
{
    string cleaned = "";
    for (char c : word)
    {
        if (isalpha(static_cast<unsigned char>(c)))
        {
            cleaned += tolower(static_cast<unsigned char>(c));
        }
    }
    return cleaned;
}

inline string toUpperWord(string word)
{
    for (char& c : word)
    {
        c = toupper(static_cast<unsigned char>(c));
    }
    return word;
}

inline bool loadDictionary(HashChain& hashTable, string dictionaryFilename = "words.txt")
{
    ifstream file(dictionaryFilename);
    if (!file.is_open())
    {
        cout << "Error: Cannot open " << dictionaryFilename << ". Make sure 'words.txt' is in the project folder." << endl;
        return false;
    }

    string word;
    while (file >> word)
    {
        string cleaned = cleanWord(word);
        if (!cleaned.empty())
        {
            hashTable.insert(cleaned);
        }
    }
    file.close();
    return true;
}

inline void processText(string text, const HashChain& hashTable, ostream* outFileStream = nullptr)
{
    if (text.empty())
    {
        cout << "\nNo input text provided." << endl;
        return;
    }

    stringstream ss(text);
    string token;
    vector<string> missingWords;
    string reproducedText = "";

    while (ss >> token)
    {
        string cleaned = cleanWord(token);

        if (!cleaned.empty() && !hashTable.search(cleaned))
        {
            if (find(missingWords.begin(), missingWords.end(), cleaned) == missingWords.end())
            {
                missingWords.push_back(cleaned);
            }
            reproducedText += toUpperWord(token) + " ";
        }
        else
        {
            reproducedText += token + " ";
        }
    }

    cout << "\n--- WORDS NOT FOUND ---" << endl;
    if (missingWords.empty())
    {
        cout << "All words were found in 'words.txt'!" << endl;
    }
    else
    {
        for (const string& word : missingWords)
        {
            cout << "- " << word << endl;
        }
    }

    cout << "\n--- REPRODUCED TEXT (BONUS) ---" << endl;
    cout << reproducedText << endl;

    if (outFileStream != nullptr)
    {
        *outFileStream << reproducedText;
    }
}

#endif