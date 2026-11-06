
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

    void InsertBeginning(int value) {
        Node* newNode = new Node(value);

        newNode->next = head;
        head = newNode;

        cout << value << " inserted at beginning.\n";
    }

 
    void InsertEnd(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* temp = head;

            while (temp->next != nullptr) {
                temp = temp->next;
            }

            temp->next = newNode;
        }

        cout << value << " inserted at end.\n";
    }


    void DeleteNode(int value) {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;

            cout << value << " deleted successfully.\n";
            return;
        }

        Node* temp = head;

        while (temp->next != nullptr &&
            temp->next->data != value) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << value << " not found in list.\n";
        }
        else {
            Node* deleteNode = temp->next;
            temp->next = deleteNode->next;
            delete deleteNode;

            cout << value << " deleted successfully.\n";
        }
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
        Node* temp;

        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};
int main() {
    SinglyLinkedList list;

    list.InsertBeginning(20);
    list.InsertBeginning(10);

    list.InsertEnd(30);
    list.InsertEnd(40);

    cout << "\nDisplaying List:\n";
    list.Display();

    cout << "\nDeleting Node:\n";
    list.DeleteNode(30);

    cout << "\nAfter Deletion:\n";
    list.Display();

    return 0;
}
