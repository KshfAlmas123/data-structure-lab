
#include <iostream>
#include <string>
using namespace std;

// Booking Structure
struct Booking {
    int customerID;
    string customerName;
    int numberOfTickets;
};

class CircularQueue {
private:
    Booking arr[5];
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

    // Add Booking
    void enqueue(Booking b) {
        if (isFull()) {
            cout << "Queue Overflow! Booking Queue is Full.\n";
            return;
        }

        rear = (rear + 1) % 5;
        arr[rear] = b;
        count++;

        cout << "Booking Added Successfully!\n";
    }

    // Cancel First Booking
    Booking dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! No Booking Available.\n";
            return { 0, "", 0 };
        }

        Booking b = arr[front];

        front = (front + 1) % 5;
        count--;

        return b;
    }

    // Display Next Booking
    void peek() {
        if (isEmpty()) {
            cout << "No Booking Available.\n";
            return;
        }

        cout << "\nNext Booking:\n";
        cout << "Customer ID: " << arr[front].customerID << endl;
        cout << "Customer Name: " << arr[front].customerName << endl;
        cout << "Tickets: " << arr[front].numberOfTickets << endl;
    }

    // Display All Bookings
    void display() {
        if (isEmpty()) {
            cout << "No Bookings Available.\n";
            return;
        }

        cout << "\n===== ALL BOOKINGS =====\n";

        for (int i = 0; i < count; i++) {
            int index = (front + i) % 5;

            cout << "\nCustomer ID: " << arr[index].customerID;
            cout << "\nCustomer Name: " << arr[index].customerName;
            cout << "\nNumber of Tickets: "
                << arr[index].numberOfTickets << endl;
        }
    }

    int totalBookings() {
        return count;
    }
};

int main() {
    CircularQueue q;
    Booking b;
    int choice;

    do {
        cout << "\n===== CINEMA TICKET SYSTEM =====\n";
        cout << "1. Book Tickets\n";
        cout << "2. Cancel First Booking\n";
        cout << "3. Display Next Booking\n";
        cout << "4. Display All Bookings\n";
        cout << "5. Total Bookings\n";
        cout << "6. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Customer ID: ";
            cin >> b.customerID;

            cin.ignore();

            cout << "Enter Customer Name: ";
            getline(cin, b.customerName);

            cout << "Enter Number of Tickets: ";
            cin >> b.numberOfTickets;

            if (b.numberOfTickets <= 0) {
                cout << "Invalid Number of Tickets!\n";
                break;
            }

            q.enqueue(b);
            break;

        case 2:
            b = q.dequeue();

            if (b.customerID != 0) {
                cout << "\nBooking Cancelled Successfully!";
                cout << "\nCustomer ID: " << b.customerID;
                cout << "\nCustomer Name: " << b.customerName << endl;
            }
            break;

        case 3:
            q.peek();
            break;

        case 4:
            q.display();
            break;

        case 5:
            cout << "Total Bookings: "
                << q.totalBookings() << endl;
            break;

        case 6:
            cout << "Cinema System Closed.\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 6);

    return 0;
}
