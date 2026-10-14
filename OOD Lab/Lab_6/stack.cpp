#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <string>

using namespace std;

void runStackLab() {
    cout << "=== LAB TASK 2: STACK LAB ===" << endl;

    // Step 1: Push values and print size
    stack<int> s;
    s.push(3);
    s.push(6);
    s.push(9);
    s.push(12);
    cout << "Size: " << s.size() << endl;

    // Step 2: Print top value
    cout << "Top: " << s.top() << endl;

    // Step 3: Pop and print new top
    s.pop();
    cout << "Top after pop: " << s.top() << endl;

    // Step 4: Remove and print remaining values (Stacks do not support iterators)
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    // Step 5: Check empty
    if (s.empty()) {
        cout << "Stack is empty" << endl;
    }

    // Step 6: Reverse string using stack
    stack<char> charStack;
    string word = "code";

    // Iterator over string characters
    for (string::iterator it = word.begin(); it != word.end(); ++it) {
        charStack.push(*it);
    }
    while (!charStack.empty()) {
        cout << charStack.top();
        charStack.pop();
    }
    cout << endl << endl;
}
int main() {
    runStackLab();

    return 0;
}
