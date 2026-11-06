
#include <iostream>
#include <string>
using namespace std;

// Print Job Structure
struct PrintJob {
    int jobID;
    string userName;
    int pages;
};

class CircularQueue {
private:
    PrintJob arr[5];
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

    // Submit Print Job
    void enqueue(PrintJob p) {
        if (isFull()) {
            cout << "Queue Overflow! Printer Queue is Full.\n";
            return;
        }

        rear = (rear + 1) % 5;
        arr[rear] = p;
        count++;

        cout << "Print Job Submitted Successfully!\n";
    }

    // Process Print Job
    PrintJob dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! No Print Job Available.\n";
            return { 0, "", 0 };
        }

        PrintJob p = arr[front];

        front = (front + 1) % 5;
        count--;

        return p;
    }

    // Display Next Print Job
    void peek() {
        if (isEmpty()) {
            cout << "No Pending Print Jobs.\n";
            return;
        }

        cout << "\nNext Print Job:\n";
        cout << "Job ID: " << arr[front].jobID << endl;
        cout << "User Name: " << arr[front].userName << endl;
        cout << "Pages: " << arr[front].pages << endl;
    }

    // Display All Pending Jobs
    void display() {
        if (isEmpty()) {
            cout << "No Pending Print Jobs.\n";
            return;
        }

        cout << "\n===== PENDING PRINT JOBS =====\n";

        for (int i = 0; i < count; i++) {
            int index = (front + i) % 5;

            cout << "\nJob ID: " << arr[index].jobID;
            cout << "\nUser Name: " << arr[index].userName;
            cout << "\nTotal Pages: " << arr[index].pages << endl;
        }
    }

    int totalJobs() {
        return count;
    }
};

int main() {
    CircularQueue q;
    PrintJob p;
    int choice;

    do {
        cout << "\n===== PRINTER MANAGEMENT SYSTEM =====\n";
        cout << "1. Submit New Print Job\n";
        cout << "2. Process Next Print Job\n";
        cout << "3. Display Next Print Job\n";
        cout << "4. Display All Pending Jobs\n";
        cout << "5. Total Pending Jobs\n";
        cout << "6. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Job ID: ";
            cin >> p.jobID;

            cin.ignore();

            cout << "Enter User Name: ";
            getline(cin, p.userName);

            cout << "Enter Number of Pages: ";
            cin >> p.pages;

            if (p.pages <= 0) {
                cout << "Invalid Number of Pages!\n";
                break;
            }

            q.enqueue(p);
            break;

        case 2:
            p = q.dequeue();

            if (p.jobID != 0) {
                cout << "\nPrint Job Processed Successfully!";
                cout << "\nJob ID: " << p.jobID;
                cout << "\nUser Name: " << p.userName;
                cout << "\nPages Printed: " << p.pages << endl;
            }
            break;

        case 3:
            q.peek();
            break;

        case 4:
            q.display();
            break;

        case 5:
            cout << "Total Pending Jobs: "
                << q.totalJobs() << endl;
            break;

        case 6:
            cout << "Printer System Closed.\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 6);

    return 0;
}
