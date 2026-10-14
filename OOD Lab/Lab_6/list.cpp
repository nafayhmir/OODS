#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <string>

using namespace std;

void runListLab() {
    cout << "=== LAB TASK 4: LIST LAB ===" << endl;

    // Step 1: Add 20, 30, 40 using push_back
    list<int> l;
    l.push_back(20);
    l.push_back(30);
    l.push_back(40);
    for (list<int>::iterator it = l.begin(); it != l.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Step 2: Add 10 at the front
    l.push_front(10);
    for (list<int>::iterator it = l.begin(); it != l.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Step 3: Remove first and last value
    l.pop_front();
    l.pop_back();
    for (list<int>::iterator it = l.begin(); it != l.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Step 4: Add 50 and 10 at the end
    l.push_back(50);
    l.push_back(10);
    for (list<int>::iterator it = l.begin(); it != l.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Step 5: Sort the list
    l.sort();
    for (list<int>::iterator it = l.begin(); it != l.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Step 6: Reverse the list
    l.reverse();
    for (list<int>::iterator it = l.begin(); it != l.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Step 7: Remove value 30
    l.remove(30);
    for (list<int>::iterator it = l.begin(); it != l.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Step 8: Clear list and print size
    l.clear();
    cout << "Size: " << l.size() << endl;
}

int main()
{
       runListLab();

    return 0;
}
