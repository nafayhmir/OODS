#include <iostream>
#include <stdexcept>

// ---------------------------------------------------------------
// Node: one element of the list
// ---------------------------------------------------------------
struct Node
{
    int data;
    Node *next;

    explicit Node(int value) : data(value), next(nullptr) {}
};

// ---------------------------------------------------------------
// LinkedList: manages the nodes
// ---------------------------------------------------------------
class LinkedList
{
private:
    Node *head;
    int size;

public:
    LinkedList() : head(nullptr), size(0) {}

    // Destructor: C++ has no garbage collector, so we must free every node.
    ~LinkedList()
    {
        clear();
    }

    // Rule of three: forbid copying to avoid double-free bugs.
    // (Keeps this example simple and safe.)
    LinkedList(const LinkedList &) = delete;
    LinkedList &operator=(const LinkedList &) = delete;

    // 1. Insert at the beginning - O(1)
    void prepend(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = head; // new node points to the old first node
        head = newNode;       // head now points to the new node
        size++;
    }

    // 2. Insert at the end - O(n)
    void append(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        { // empty list
            head = newNode;
        }
        else
        {
            Node *current = head;
            while (current->next != nullptr)
            { // stop ON the last node
                current = current->next;
            }
            current->next = newNode;
        }
        size++;
    }

    // 3. Insert at a position (0 = front) - O(n)
    void insertAt(int index, int value)
    {
        if (index < 0 || index > size)
        {
            throw std::out_of_range("insertAt: index out of range");
        }
        if (index == 0)
        {
            prepend(value);
            return;
        }
        Node *current = head;
        for (int i = 0; i < index - 1; i++)
        { // walk to node BEFORE the spot
            current = current->next;
        }
        Node *newNode = new Node(value);
        newNode->next = current->next; // 1) new node points forward first
        current->next = newNode;       // 2) then previous node points to it
        size++;
    }

    // 4. Delete the first node holding this value - O(n)
    bool remove(int value)
    {
        if (head == nullptr)
            return false;

        // Case: the head is the target
        if (head->data == value)
        {
            Node *toDelete = head;
            head = head->next;
            delete toDelete;
            size--;
            return true;
        }

        // Case: target is somewhere after the head
        Node *current = head;
        while (current->next != nullptr)
        {
            if (current->next->data == value)
            {
                Node *toDelete = current->next;
                current->next = toDelete->next; // skip over it
                delete toDelete;                // free memory
                size--;
                return true;
            }
            current = current->next;
        }
        return false; // not found
    }

    // 5. Delete by index - O(n)
    void removeAt(int index)
    {
        if (index < 0 || index >= size)
        {
            throw std::out_of_range("removeAt: index out of range");
        }
        Node *toDelete;
        if (index == 0)
        {
            toDelete = head;
            head = head->next;
        }
        else
        {
            Node *current = head;
            for (int i = 0; i < index - 1; i++)
            {
                current = current->next;
            }
            toDelete = current->next;
            current->next = toDelete->next;
        }
        delete toDelete;
        size--;
    }

    // 6. Search - O(n)
    bool contains(int value) const
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (current->data == value)
                return true;
            current = current->next;
        }
        return false;
    }

    // 7. Get value at index - O(n)
    int get(int index) const
    {
        if (index < 0 || index >= size)
        {
            throw std::out_of_range("get: index out of range");
        }
        Node *current = head;
        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }
        return current->data;
    }

    // 8. Reverse in place - O(n)
    void reverse()
    {
        Node *prev = nullptr;
        Node *current = head;
        while (current != nullptr)
        {
            Node *nxt = current->next; // save next
            current->next = prev;      // flip the link
            prev = current;            // move prev forward
            current = nxt;             // move current forward
        }
        head = prev;
    }

    // 9. Print the list
    void display() const
    {
        Node *current = head;
        while (current != nullptr)
        {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr\n";
    }

    // 10. Free every node
    void clear()
    {
        while (head != nullptr)
        {
            Node *toDelete = head;
            head = head->next;
            delete toDelete;
        }
        size = 0;
    }

    int length() const { return size; }
    bool empty() const { return head == nullptr; }
};

// ---------------------------------------------------------------
// Demo
// ---------------------------------------------------------------
int main()
{
    LinkedList list;

    std::cout << "--- Building the list ---\n";
    list.append(10);
    list.append(20);
    list.append(30);
    list.prepend(5);
    list.display(); // 5 -> 10 -> 20 -> 30 -> nullptr

    std::cout << "\n--- Insert 15 at index 2 ---\n";
    list.insertAt(2, 15);
    list.display(); // 5 -> 10 -> 15 -> 20 -> 30 -> nullptr

    std::cout << "\n--- Search ---\n";
    std::cout << "contains(20)? " << (list.contains(20) ? "yes" : "no") << "\n";
    std::cout << "contains(99)? " << (list.contains(99) ? "yes" : "no") << "\n";
    std::cout << "get(3) = " << list.get(3) << "\n";

    std::cout << "\n--- Remove value 10 ---\n";
    list.remove(10);
    list.display(); // 5 -> 15 -> 20 -> 30 -> nullptr

    std::cout << "\n--- Remove index 0 ---\n";
    list.removeAt(0);
    list.display(); // 15 -> 20 -> 30 -> nullptr

    std::cout << "\n--- Reverse ---\n";
    list.reverse();
    list.display(); // 30 -> 20 -> 15 -> nullptr

    std::cout << "\nLength: " << list.length() << "\n";

    std::cout << "\n--- Error handling ---\n";
    try
    {
        list.get(100);
    }
    catch (const std::out_of_range &e)
    {
        std::cout << "Caught error: " << e.what() << "\n";
    }

    return 0; // destructor frees all remaining nodes automatically
}