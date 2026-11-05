#include <iostream>
using namespace std;
struct nodeType//linklist!!
{
    int info;
    nodeType *link;
};
//hashfunction
int hashFunction(int key, int tableSize)
{
    return key % tableSize;
}
//searching in linked list
int searchChaining(nodeType *table[], int tableSize, int key) //parameters table,size of table,key
{
    int index = hashFunction(key, tableSize); //getting inex using hashing
    nodeType *current = table[index];

    while (current != nullptr) //checks till it reaches NULL
    {
        if (current->info == key) 
        {
            return index;
        }
        current = current->link;//else condition
    }
    return -1;
}
void insertChaining(nodeType *table[], int tableSize, int key)
{
    int index = hashFunction(key, tableSize); //index generation using hashfunction
    if (searchChaining(table, tableSize, key) != -1)
    {
        cout << key << " is already in the table" << endl;
        return;
    }

    nodeType *newNode = new nodeType;
    newNode->info = key;
    newNode->link = table[index];
    table[index] = newNode;

    cout << "Inserted " << key << " at index " << index << endl;
}

void printTable(nodeType *table[], int tableSize)
{
    for (int i = 0; i < tableSize; i++)
    {
        cout << "Index " << i << ": ";
        nodeType *current = table[i];
        while (current != nullptr)
        {
            cout << current->info << " -> ";
            current = current->link;
        }
        cout << "NULL" << endl;
    }
}

void freeTable(nodeType *table[], int tableSize)
{
    for (int i = 0; i < tableSize; i++)
    {
        nodeType *current = table[i];
        while (current != nullptr)
        {
            nodeType *temp = current;
            current = current->link;
            delete temp;
        }
        table[i] = nullptr;
    }
}
int main()
{
    const int tableSize = 7;
    nodeType *table[tableSize];

    for (int i = 0; i < tableSize; i++)
    {
        table[i] = nullptr;
    }
    int keys[] = {25, 14, 9, 32, 18, 7, 21, 11, 3, 13}; //Int Keys
    int numKeys = 10; //number of keys

    for (int i = 0; i < numKeys; i++) //length
    {
        insertChaining(table, tableSize, keys[i]);
    }
    insertChaining(table, tableSize, 18);
    printTable(table, tableSize);
    int searchKeys[] = {32, 21, 20}; 
    for (int i = 0; i < 3; i++)
    {
        int key = searchKeys[i];
        int idx = searchChaining(table, tableSize, key);
        if (idx != -1)
        {
            cout << key << " found at index " << idx << endl;
        }
        else
        {
            cout << key << " not found in the table" << endl;
        }
    }
    freeTable(table, tableSize);
    return 0;
}