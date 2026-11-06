
#include <iostream>
#include <queue>
#include <string>
using namespace std;

class PrinterQueue {
private:
    queue<string> documents;

public:

    // Enqueue: Add a new document
    void enqueue(string document_name) {

        if (document_name.empty()) {
            cout << "Document name cannot be empty!" << endl;
            return;
        }

        documents.push(document_name);

        cout << document_name
            << " added to print queue successfully." << endl;
    }

    // Dequeue: Print the front document
    void dequeue() {

        if (documents.empty()) {
            cout << "Print Queue is Empty!" << endl;
            return;
        }

        cout << "Printing Document: "
            << documents.front() << endl;

        documents.pop();

        cout << "Document printed successfully." << endl;
    }

    // Front: Show next document without printing
    void front() {

        if (documents.empty()) {
            cout << "Print Queue is Empty!" << endl;
            return;
        }

        cout << "Next Document to Print: "
            << documents.front() << endl;
    }

    // Display all pending documents
    void display() {

        if (documents.empty()) {
            cout << "No Pending Print Jobs!" << endl;
            return;
        }

        queue<string> temp = documents;

        cout << "\nPending Print Jobs:" << endl;

        while (!temp.empty()) {

            cout << "Document: "
                << temp.front() << endl;

            temp.pop();
        }
    }

    // Check whether queue is empty
    bool isEmpty() {
        return documents.empty();
    }
};

// Main Function
int main() {

    PrinterQueue printer;
    int choice;
    string document_name;

    do {

        cout << "\n===== DOCUMENT PRINTING SYSTEM =====" << endl;
        cout << "1. Add Print Job" << endl;
        cout << "2. Print Document" << endl;
        cout << "3. View Next Document" << endl;
        cout << "4. Display Print Queue" << endl;
        cout << "5. Exit" << endl;

        cout << "\nEnter your choice: ";
        cin >> choice;

        cin.ignore(10000, '\n');

        switch (choice) {

        case 1:
            cout << "Enter Document Name: ";
            getline(cin, document_name);

            printer.enqueue(document_name);
            break;

        case 2:
            printer.dequeue();
            break;

        case 3:
            printer.front();
            break;

        case 4:
            printer.display();
            break;

        case 5:
            cout << "Exiting Printer Queue System!" << endl;
            break;

        default:
            cout << "Invalid Choice! Try Again." << endl;
        }

    } while (choice != 5);

    return 0;
}
