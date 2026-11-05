#include <iostream>

using namespace std;

void printList(int list[], int length) //Display List
{
    cout << "List:";
    for (int i = 0; i < length; i++)
    {
        cout << " " << list[i];
    }
    cout << endl;
}
void swap(int &a, int &b) //swap function
{
    int temp = a;
    a = b;
    b = temp;
}
int partition(int list[], int first, int last)
{
    int pivot = list[last]; //end of array
    int i = first - 1; //first-1

    for (int j = first; j < last; j++)
    {
        if (list[j] <= pivot) //if pivot is greater than list[j]
        {
            i++;
            swap(list[i], list[j]);
        }
    }
    swap(list[i + 1], list[last]);
    return i + 1;
}
void quickSort(int list[], int length, int first, int last) 
{
    if (first < last)
    {
        int pivotIndex = partition(list, first, last);

        cout << "Pivot Index " << list[pivotIndex] << " placed at index " << pivotIndex << endl;
        printList(list, length);
//recursion
        quickSort(list, length, first, pivotIndex - 1);
        quickSort(list, length, pivotIndex + 1, last);
    }
}

int main()
{
    int list[] = {38, 27, 43, 3, 9, 82, 10};
    int length = 7;

    printList(list, length);
    quickSort(list, length, 0, length - 1); //first is 0, last is 6
    printList(list, length);

    return 0;
}