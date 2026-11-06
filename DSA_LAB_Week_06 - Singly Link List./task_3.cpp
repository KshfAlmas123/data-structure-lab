
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class SinglyLinkedList {
private:
    Node* head;

public:
   
    SinglyLinkedList() {
        head = nullptr;
    }

   
    void Insert(int value, int position) {
        if (position < 1) {
            cout << "Invalid position!\n";
            return;
        }

        Node* newNode = new Node(value);

      
        if (position == 1) {
            newNode->next = head;
            head = newNode;
            cout << "Node inserted successfully.\n";
            return;
        }

        Node* temp = head;

        for (int i = 1; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Invalid position!\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;

        cout << "Node inserted successfully.\n";
    }

    void Delete(int position) {
        if (head == nullptr || position < 1) {
            cout << "List is empty or invalid position!\n";
            return;
        }

        Node* temp = head;
        if (position == 1) {
            head = head->next;
            delete temp;
            cout << "Node deleted successfully.\n";
            return;
        }

        Node* prev = nullptr;

        for (int i = 1; i < position && temp != nullptr; i++) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Invalid position!\n";
            return;
        }

        prev->next = temp->next;
        delete temp;

        cout << "Node deleted successfully.\n";
    }

    void Search(int value) {
        Node* temp = head;
        int position = 1;

        while (temp != nullptr) {
            if (temp->data == value) {
                cout << "Element found at position "
                    << position << ".\n";
                return;
            }

            temp = temp->next;
            position++;
        }

        cout << "Element not found in the list.\n";
    }
    void Count() {
        Node* temp = head;
        int count = 0;

        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        cout << "Total number of nodes: " << count << endl;
    }

  
    void Display() {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }

        Node* temp = head;

        cout << "Linked List: ";

        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }
     ~SinglyLinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};
int main() {
    SinglyLinkedList list;

    int choice, value, position;

    do {
        cout << "\n===== SINGLY LINKED LIST MENU =====\n";
        cout << "1. Insert Node at Specific Position\n";
        cout << "2. Delete Node at Specific Position\n";
        cout << "3. Search Element\n";
        cout << "4. Count Total Nodes\n";
        cout << "5. Display List\n";
        cout << "6. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter value: ";
            cin >> value;

            cout << "Enter position: ";
            cin >> position;

            list.Insert(value, position);
            break;

        case 2:
            cout << "Enter position to delete: ";
            cin >> position;

            list.Delete(position);
            break;

        case 3:
            cout << "Enter element to search: ";
            cin >> value;

            list.Search(value);
            break;

        case 4:
            list.Count();
            break;

        case 5:
            list.Display();
            break;

        case 6:
            cout << "Program terminated.\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 6);

    return 0;
}
