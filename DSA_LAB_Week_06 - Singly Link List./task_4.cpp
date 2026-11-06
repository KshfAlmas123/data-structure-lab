
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int patientID;
    string patientName;
    Node* next;

    Node(int id, string name) {
        patientID = id;
        patientName = name;
        next = nullptr;
    }
};
class HospitalQueue {
private:
    Node* head;

public:
    
    HospitalQueue() {
        head = nullptr;
    }

    void AddPatient(int id, string name) {
        Node* newNode = new Node(id, name);

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

        cout << "Patient " << name
            << " added successfully.\n";
    }

    void RemovePatient(int id) {
        if (head == nullptr) {
            cout << "Queue is empty!\n";
            return;
        }

        Node* temp = head;

     
        if (head->patientID == id) {
            head = head->next;

            cout << "Patient " << temp->patientName
                << " cancelled successfully.\n";

            delete temp;
            return;
        }

        Node* prev = nullptr;

      
        while (temp != nullptr && temp->patientID != id) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Patient ID not found!\n";
            return;
        }

   
        prev->next = temp->next;

        cout << "Patient " << temp->patientName
            << " cancelled successfully.\n";

        delete temp;
    }

    void DisplayPatients() {
        if (head == nullptr) {
            cout << "No patients waiting in the queue.\n";
            return;
        }

        Node* temp = head;

        cout << "\n===== PATIENT QUEUE =====\n";

        while (temp != nullptr) {
            cout << "Patient ID: " << temp->patientID
                << " | Name: " << temp->patientName << endl;

            temp = temp->next;
        }
    }

    void CountPatients() {
        Node* temp = head;
        int count = 0;

        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        cout << "Total patients waiting: " << count << endl;
    }


    ~HospitalQueue() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    HospitalQueue hospital;

    int choice, id;
    string name;

    do {
        cout << "\n===== HOSPITAL MANAGEMENT SYSTEM =====\n";
        cout << "1. Add New Patient\n";
        cout << "2. Remove Patient (Cancel Appointment)\n";
        cout << "3. Display Patient Queue\n";
        cout << "4. Count Total Patients\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter Patient ID: ";
            cin >> id;

            cout << "Enter Patient Name: ";
            cin >> ws;
            getline(cin, name);

            hospital.AddPatient(id, name);
            break;

        case 2:
            cout << "Enter Patient ID to cancel: ";
            cin >> id;

            hospital.RemovePatient(id);
            break;

        case 3:
            hospital.DisplayPatients();
            break;

        case 4:
            hospital.CountPatients();
            break;

        case 5:
            cout << "Exiting Hospital Management System.\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
