#include <iostream>
using namespace std;

void printList(int list[], int length)
{
    cout << "List:";
    for (int i = 0; i < length; i++)
    {
        cout << " " << list[i];
    }
    cout << endl;
}
//Printing array

void insertionSort(int list[], int length)
{
    for (int i = 1; i < length; i++)
    {
        int temp = list[i];
        int j = i - 1;

        while (j >= 0 && list[j] > temp) //traversal till value in array is greater than intitial (type of bubble sort)
        {
            list[j + 1] = list[j];
            j--;
        }
        list[j + 1] = temp;

        cout << "After pass " << i << ":";
        for (int k = 0; k < length; k++)
        {
            cout << " " << list[k];
        }
        cout << endl;
    }
}

int main()
{
    int list1[] = {25, 12, 40, 8, 19, 33};
    int length1 = 6;

    cout << "First list" << endl;
    printList(list1, length1);
    insertionSort(list1, length1);
    printList(list1, length1);

    cout << endl;

    int list2[] = {9, 7, 5, 3, 1};
    int length2 = 5;

    cout << "Second list" << endl;
    printList(list2, length2);
    insertionSort(list2, length2);
    printList(list2, length2);

    return 0;
}