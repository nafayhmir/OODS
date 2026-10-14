#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <string>

using namespace std;


void runQueueLab() {
    cout << "=== LAB TASK 3: QUEUE LAB ===" << endl;

    // Step 1: Push names and print size
    queue<string> q;
    q.push("Ali");
    q.push("Sara");
    q.push("Omar");
    q.push("Hina");
    cout << "Size: " << q.size() << endl;

    // Step 2: Print front and back
    cout << "Front: " << q.front() << endl;
    cout << "Back: " << q.back() << endl;

    // Step 3: Serve one person and print next
    q.pop();
    cout << "Next in line: " << q.front() << endl;

    // Step 4: Serve remaining people (Queues do not support iterators)
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    // Step 5: Check empty
    if (q.empty()) {
        cout << "Queue is empty" << endl;
    }
    cout << endl;
}

int main() 
{

    runQueueLab();

    return 0;
}
