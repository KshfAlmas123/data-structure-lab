
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class myQueue {
private:
    queue<int> q;

public:

    // Enqueue: Insert element
    void enqueue(int value) {
        q.push(value);
    }

    // Dequeue: Remove front element
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return -1;
        }

        int value = q.front();
        q.pop();
        return value;
    }

    // Return front element
    int front() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return -1;
        }

        return q.front();
    }

    // Check whether queue is empty
    bool isEmpty() {
        return q.empty();
    }

    // Display queue elements
    void display() {
        queue<int> temp = q;

        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }

        cout << endl;
    }

    // Reverse first K elements
    void reverseFirstK(int k) {

        int n = q.size();

        // Handle invalid or unnecessary K
        if (k <= 1 || n == 0) {
            cout << "No reversal needed." << endl;
            return;
        }

        // If K is greater than queue size
        if (k > n) {
            k = n;
        }

        stack<int> s;

        // Step 1: Remove first K elements
        // and push them into stack
        for (int i = 0; i < k; i++) {
            s.push(q.front());
            q.pop();
        }

        // Step 2: Insert stack elements back
        // into the queue
        while (!s.empty()) {
            q.push(s.top());
            s.pop();
        }

        // Step 3: Move remaining elements
        // to the back of the queue
        for (int i = 0; i < n - k; i++) {
            q.push(q.front());
            q.pop();
        }
    }
};

// Main Function
int main() {

    myQueue q;
    int n, value, k;

    cout << "Enter number of queue elements: ";
    cin >> n;

    if (n < 0) {
        cout << "Invalid number of elements!" << endl;
        return 0;
    }

    // Read queue elements
    cout << "Enter queue elements:" << endl;

    for (int i = 0; i < n; i++) {
        cin >> value;
        q.enqueue(value);
    }

    cout << "\nOriginal Queue: ";
    q.display();

    // Read K
    cout << "Enter value of K: ";
    cin >> k;

    // Reverse first K elements
    q.reverseFirstK(k);

    // Display result
    cout << "\nQueue after reversing first K elements: ";
    q.display();

    return 0;
}
