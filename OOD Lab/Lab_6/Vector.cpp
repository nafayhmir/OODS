#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <string>

using namespace std;

void runVectorLab() {
    cout << "=== LAB TASK 1: VECTOR LAB ===" << endl;

    // Step 1: Create vector and add elements
    vector<int> v;
    v.push_back(5);
    v.push_back(15);
    v.push_back(25);
    v.push_back(35);
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Step 2: Print size, first, and last element
    cout << "Size: " << v.size() << endl;
    cout << "First: " << v.front() << endl;
    cout << "Last: " << v.back() << endl;

    // Step 3: Insert 20 between 15 and 25 using iterator arithmetic
    v.insert(v.begin() + 2, 20);
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Step 4: Erase first value using iterator and pop back
    v.erase(v.begin());
    v.pop_back();
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Step 5: Clear and check empty
    v.clear();
    if (v.empty()) {
        cout << "Vector is empty" << endl;
    }
    cout << endl;
}

int main() 
{
    runVectorLab();
    return 0;
}
