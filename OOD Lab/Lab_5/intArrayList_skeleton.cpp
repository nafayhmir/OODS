#include <iostream>
using namespace std;

class intArrayList
{
public:
    bool isEmpty() const;
    bool isFull() const;
    int listSize() const;
    int maxListSize() const;
    void print() const;
    bool isItemAtEqual(int location, int item) const;
    void insertAt(int location, int insertItem);
    void insertEnd(int insertItem);
    void removeAt(int location);
    void retrieveAt(int location, int &retItem) const;
    void replaceAt(int location, int repItem);
    void clearList();
    int seqSearch(int item) const;
    void insert(int insertItem);
    void remove(int removeItem);
    intArrayList(int size = 100);
    intArrayList(const intArrayList &otherList);
    ~intArrayList();
    const intArrayList &operator=(const intArrayList &otherList);

protected:
    int *list;
    int length;
    int maxSize;
};

bool intArrayList::isEmpty() const
{ // empty only if length is 0
    return length == 0;
}

bool intArrayList::isFull() const
{ // checks if length is same as max size
    return length == maxSize;
}

int intArrayList::listSize() const
{ // same as get length
    return length;
}

int intArrayList::maxListSize() const
{ // same as get maxsize
    return maxSize;
}

void intArrayList::print() const
{ // DIsplay FUnction
    for (int i = 0; i < length; i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;
}

bool intArrayList::isItemAtEqual(int pos, int item) const
{
    if (pos < 0 || pos >= length)
        return false; // checks if pos is inside array

    return list[pos] == item; // check if position given value is same as parameter value
}

void intArrayList::insertAt(int pos, int insertItem)
{ // insert at pos
    if (isFull() || pos < 0 || pos > length)
        return; // checks if array has space and pos is in array

        // Shifts everything right
        for (int i = length; i > pos; i--)
    {
        list[i] = list[i - 1];
    }
    list[pos] = insertItem;
    length++;
}

void intArrayList::insertEnd(int insertItem)
{ // inserts item at end
    if (isFull())
        return;

    list[length] = insertItem;
    length++;
}

void intArrayList::removeAt(int pos)
{ // Position based removal
    if (pos < 0 || pos >= length)
        return;

    // Shift everything left
    for (int i = pos; i < length - 1; i++)
    {
        list[i] = list[i + 1];
    }
    length--;
}

void intArrayList::retrieveAt(int pos, int &retItem) const
{
    // Position based retrival
    if (pos >= 0 && pos < length)
    {
        retItem = list[pos];
    }
}

void intArrayList::replaceAt(int pos, int repItem)
{ // Replace by Pos
    if (pos >= 0 && pos < length)
    {
        list[pos] = repItem;
    }
}

void intArrayList::clearList()
{ // empty the list
    length = 0;
}

int intArrayList::seqSearch(int item) const
{ // search using for loop
    for (int i = 0; i < length; i++)
    {
        if (list[i] == item)
            return i;
    }
    return -1;
}

void intArrayList::insert(int insertItem)
{
    // Only insert if it doesn't already exist
    if (seqSearch(insertItem) == -1)
    {
        insertEnd(insertItem);
    }
}

void intArrayList::remove(int removeItem)
{
    int loc = seqSearch(removeItem);
    if (loc != -1)
    {
        removeAt(loc);
    }
}

// Constructor
intArrayList::intArrayList(int size)
{
    maxSize = (size <= 0) ? 100 : size;
    length = 0;
    list = new int[maxSize];
}

// Copy Constructor
intArrayList::intArrayList(const intArrayList &otherList)
{
    maxSize = otherList.maxSize;
    length = otherList.length;
    list = new int[maxSize];
    for (int i = 0; i < length; i++)
    {
        list[i] = otherList.list[i];
    }
}

// Destructor
intArrayList::~intArrayList()
{
    delete[] list;
}

// Assignment Operator
const intArrayList &intArrayList::operator=(const intArrayList &otherList)
{
    if (this != &otherList)
    {
        delete[] list;
        maxSize = otherList.maxSize;
        length = otherList.length;
        list = new int[maxSize];
        for (int i = 0; i < length; i++)
        {
            list[i] = otherList.list[i];
        }
    }
    return *this;
}

int main()
{
    intArrayList list(10);
    cout << "Is list empty? " << list.isEmpty() << endl;

    list.insertEnd(10);
    list.insertEnd(20);
    cout << "After inserting 10 and 20 at end: ";
    list.print(); //will display the list with only 2 members 10 and 20

    list.insertAt(1, 99); 
    list.print();// Will insert Value of 99 at position 1 of list

    cout << "Index of 30: " << list.seqSearch(30) << endl;
    cout << "Index of 500" << list.seqSearch(500) << endl;

    list.removeAt(0);
    cout << "After removing element at location 0: ";
    list.print();

    int val;
    list.retrieveAt(0, val);
    cout << "Element at location 0: " << val << endl; //Changes val to value stored at 0

    list.replaceAt(0, 777);
    cout << "After replacing location 0 with 777: ";
    list.print();

    list.insert(777);
    list.insert(555);
    cout << "After insert(777) [dup] and insert(555): ";
    list.print();

    list.remove(20);
    cout << "After remove(20): ";
    list.print();

    intArrayList copyList = list;
    cout << "Copy of list: ";
    copyList.print();

    intArrayList assignedList(5);
    assignedList = list;
    cout << "Assigned list: ";
    assignedList.print();

    list.clearList();
    cout << "After clearList, isEmpty? " << (list.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
