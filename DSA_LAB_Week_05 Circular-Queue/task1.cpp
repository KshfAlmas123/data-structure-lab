
#include <iostream>
#include <string>
using namespace std;

// Customer Structure
struct Customer {
    string name;
    string transaction;
};

class CircularQueue {
private:
    Customer arr[5];
    int front, rear, count;

public:
    CircularQueue() {
        front = 0;
        rear = -1;
        count = 0;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == 5;
    }

    // Add Customer
    void enqueue(Customer c) {
        if (isFull()) {
            cout << "Queue Overflow! Bank line is full.\n";
            return;
        }

        rear = (rear + 1) % 5;
        arr[rear] = c;
        count++;

        cout << "Customer Added Successfully!\n";
    }

    // Serve Customer
    Customer dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! No customer to serve.\n";
            return { "", "" };
        }

        Customer c = arr[front];
        front = (front + 1) % 5;
        count--;

        return c;
    }

    // Display Customers
    void display() {
        if (isEmpty()) {
            cout << "No Customers Waiting.\n";
            return;
        }

        cout << "\nWaiting Customers:\n";

        for (int i = 0; i < count; i++) {
            int index = (front + i) % 5;

            cout << "\nName: " << arr[index].name;
            cout << "\nTransaction: " << arr[index].transaction << endl;
        }
    }

    int totalCustomers() {
        return count;
    }
};

int main() {
    CircularQueue q;
    Customer c;
    int choice;

    do {
        cout << "\n===== BANK QUEUE SYSTEM =====\n";
        cout << "1. Add Customer\n";
        cout << "2. Serve Customer\n";
        cout << "3. Display Customers\n";
        cout << "4. Total Customers\n";
        cout << "5. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cin.ignore();

            cout << "Enter Customer Name: ";
            getline(cin, c.name);

            cout << "Enter Transaction Type: ";
            getline(cin, c.transaction);

            q.enqueue(c);
            break;

        case 2:
            c = q.dequeue();

            if (c.name != "") {
                cout << "\nCustomer Served Successfully!";
                cout << "\nName: " << c.name;
                cout << "\nTransaction: " << c.transaction << endl;
            }
            break;

        case 3:
            q.display();
            break;

        case 4:
            cout << "Total Waiting Customers: "
                << q.totalCustomers() << endl;
            break;

        case 5:
            cout << "Bank Queue System Closed.\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}
