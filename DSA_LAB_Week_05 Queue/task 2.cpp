
#include <iostream>
#include <stack>
using namespace std;

class myQueue {
private:
    stack<int> s1;
    stack<int> s2;


    void transfer() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
    }

public:

    // Enqueue: Insert element into queue
    void enQueue(int value) {
        s1.push(value);
        cout << value << " inserted successfully." << endl;
    }

    // Dequeue: Remove front element
    int deQueue() {
        transfer();

        if (s2.empty()) {
            cout << "Queue is Empty!" << endl;
            return -1;
        }

        int value = s2.top();
        s2.pop();

        cout << value << " removed successfully." << endl;
        return value;
    }

    // Front: Return front element without removing it
    int front() {
        transfer();

        if (s2.empty()) {
            cout << "Queue is Empty!" << endl;
            return -1;
        }

        return s2.top();
    }

    // Check whether queue is empty
    bool isEmpty() {
        return s1.empty() && s2.empty();
    }

    // Display all queue elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }

        cout << "Queue Elements (Front to Rear): ";

        // Display elements of s2
        stack<int> temp1 = s2;

        while (!temp1.empty()) {
            cout << temp1.top() << " ";
            temp1.pop();
        }

        // Display elements of s1 in reverse stack order
        stack<int> temp2 = s1;
        stack<int> temp3;

        while (!temp2.empty()) {
            temp3.push(temp2.top());
            temp2.pop();
        }

        while (!temp3.empty()) {
            cout << temp3.top() << " ";
            temp3.pop();
        }

        cout << endl;
    }
};

// Main Function
int main() {
    myQueue q;
    int choice, value;

    do {
        cout << "\n===== QUEUE USING TWO STACKS =====" << endl;
        cout << "1. Enqueue (Insert)" << endl;
        cout << "2. Dequeue (Remove)" << endl;
        cout << "3. Front Element" << endl;
        cout << "4. Display Queue" << endl;
        cout << "5. Check Empty" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter value: ";
            cin >> value;
            q.enQueue(value);
            break;

        case 2:
            q.deQueue();
            break;

        case 3:
            if (!q.isEmpty())
                cout << "Front Element: " << q.front() << endl;
            else
                cout << "Queue is Empty!" << endl;
            break;

        case 4:
            q.display();
            break;

        case 5:
            if (q.isEmpty())
                cout << "Queue is Empty." << endl;
            else
                cout << "Queue is Not Empty." << endl;
            break;

        case 6:
            cout << "Program Terminated!" << endl;
            break;

        default:
            cout << "Invalid Choice! Try Again." << endl;
        }

    } while (choice != 6);

    return 0;
}
