
#include <iostream>
#include <string>
using namespace std;

// Node class for student reservation
class Node {
public:
    int studentID;
    string studentName;
    int priority;
    Node* next;

    Node(int id, string name, int p) {
        studentID = id;
        studentName = name;
        priority = p;
        next = nullptr;
    }
};

// Singly Linked List ADT for each book
class ReservationQueue {
private:
    Node* head;

public:
    ReservationQueue() {
        head = nullptr;
    }

    // Add student according to priority
    void AddStudent(int id, string name, int priority) {
        Node* newNode = new Node(id, name, priority);

        // Insert at beginning if queue is empty
        // or new student has higher priority
        if (head == nullptr || priority < head->priority) {
            newNode->next = head;
            head = newNode;
        }
        else {
            Node* temp = head;

            // Maintain FIFO for students with same priority
            while (temp->next != nullptr &&
                temp->next->priority <= priority) {
                temp = temp->next;
            }

            newNode->next = temp->next;
            temp->next = newNode;
        }

        cout << "Student " << name
            << " added successfully.\n";
    }

    // Remove student if reservation is cancelled
    void RemoveStudent(int id) {
        if (head == nullptr) {
            cout << "Reservation list is empty!\n";
            return;
        }

        Node* temp = head;

        // If first student cancels
        if (head->studentID == id) {
            head = head->next;

            cout << temp->studentName
                << " cancelled reservation.\n";

            delete temp;
            return;
        }

        Node* prev = nullptr;

        while (temp != nullptr && temp->studentID != id) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Student not found!\n";
            return;
        }

        prev->next = temp->next;

        cout << temp->studentName
            << " cancelled reservation.\n";

        delete temp;
    }

    // Update student's priority
    void UpdatePriority(int id, int newPriority) {
        if (newPriority < 1 || newPriority > 3) {
            cout << "Invalid priority!\n";
            return;
        }

        Node* temp = head;

        while (temp != nullptr && temp->studentID != id) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Student not found!\n";
            return;
        }

        string name = temp->studentName;

        // Remove student from old position
        RemoveStudent(id);

        // Add student again with updated priority
        AddStudent(id, name, newPriority);

        cout << "Priority updated successfully.\n";
    }

    // Display reservation list
    void Display() {
        if (head == nullptr) {
            cout << "No students waiting.\n";
            return;
        }

        Node* temp = head;

        cout << "\nStudent Reservation List:\n";

        while (temp != nullptr) {
            cout << "ID: " << temp->studentID
                << " | Name: " << temp->studentName
                << " | Priority: ";

            if (temp->priority == 1)
                cout << "Research";
            else if (temp->priority == 2)
                cout << "Assignment";
            else
                cout << "Casual Reading";

            cout << endl;

            temp = temp->next;
        }
    }

    // Count students in queue
    void CountStudents() {
        int count = 0;
        Node* temp = head;

        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        cout << "Total students waiting: "
            << count << endl;
    }

    // Issue book to first student when returned
    void BookReturned() {
        if (head == nullptr) {
            cout << "No reservations for this book.\n";
            return;
        }

        Node* temp = head;

        cout << "\nBook issued to: "
            << temp->studentName
            << " (ID: " << temp->studentID << ")\n";

        head = head->next;

        delete temp;
    }

    // Destructor
    ~ReservationQueue() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Main function
int main() {

    // Two separate book reservation queues
    ReservationQueue book1;
    ReservationQueue book2;

    int choice, bookChoice;
    int id, priority;
    string name;

    do {
        cout << "\n===== UNIVERSITY LIBRARY SYSTEM =====\n";

        cout << "1. Add Student Reservation\n";
        cout << "2. Cancel Student Reservation\n";
        cout << "3. Update Student Priority\n";
        cout << "4. Display Reservation List\n";
        cout << "5. Count Waiting Students\n";
        cout << "6. Return Book and Issue to Next Student\n";
        cout << "7. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 6) {
            cout << "\nSelect Book:\n";
            cout << "1. Data Structures\n";
            cout << "2. Database Systems\n";
            cout << "Enter book choice: ";
            cin >> bookChoice;

            if (bookChoice != 1 && bookChoice != 2) {
                cout << "Invalid book choice!\n";
                continue;
            }
        }

        // Select the required reservation queue
        ReservationQueue* selectedBook;

        if (bookChoice == 1)
            selectedBook = &book1;
        else
            selectedBook = &book2;

        switch (choice) {

        case 1:
            cout << "Enter Student ID: ";
            cin >> id;

            cout << "Enter Student Name: ";
            cin >> ws;
            getline(cin, name);

            cout << "\nPriority Levels:\n";
            cout << "1. Research\n";
            cout << "2. Assignment\n";
            cout << "3. Casual Reading\n";

            cout << "Enter priority: ";
            cin >> priority;

            selectedBook->AddStudent(id, name, priority);
            break;

        case 2:
            cout << "Enter Student ID to cancel: ";
            cin >> id;

            selectedBook->RemoveStudent(id);
            break;

        case 3:
            cout << "Enter Student ID: ";
            cin >> id;

            cout << "Enter New Priority (1-3): ";
            cin >> priority;

            selectedBook->UpdatePriority(id, priority);
            break;

        case 4:
            selectedBook->Display();
            break;

        case 5:
            selectedBook->CountStudents();
            break;

        case 6:
            selectedBook->BookReturned();
            break;

        case 7:
            cout << "Exiting Library System.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 7);

    return 0;
}
