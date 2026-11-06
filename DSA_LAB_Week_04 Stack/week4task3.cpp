
#include <iostream>
#include <string>
using namespace std;

class myCarStack {
private:
    string cars[8];
    int topIndex;

public:
    myCarStack() {
        topIndex = -1;
    }

    bool isEmpty() {
        return topIndex == -1;
    }

    bool isFull() {
        return topIndex == 7;
    }

    void push(string car) {
        if (isFull()) {
            cout << "Parking Lot is Full!\n";
            return;
        }

        cars[++topIndex] = car;
        cout << "Car Parked Successfully.\n";
    }

    string pop() {
        if (isEmpty())
            return "";

        return cars[topIndex--];
    }

    string top() {
        if (isEmpty())
            return "";

        return cars[topIndex];
    }

    int count() {
        return topIndex + 1;
    }

    bool search(string car) {
        for (int i = 0; i <= topIndex; i++) {
            if (cars[i] == car)
                return true;
        }

        return false;
    }

    void display() {
        if (isEmpty()) {
            cout << "No Cars Parked.\n";
            return;
        }

        cout << "\nParked Cars (Last In First Out):\n";

        for (int i = topIndex; i >= 0; i--) {
            cout << cars[i] << endl;
        }
    }

    void removeCar(string car) {
        if (isEmpty()) {
            cout << "Parking Lot is Empty!\n";
            return;
        }

        myCarStack temp;
        bool found = false;

        while (!isEmpty()) {
            string current = pop();

            if (current == car) {
                found = true;
                break;
            }

            temp.push(current);
        }

        while (!temp.isEmpty()) {
            push(temp.pop());
        }

        if (found)
            cout << "Car " << car << " Removed Successfully.\n";
        else
            cout << "Car Not Found!\n";
    }
};

int main() {
    myCarStack parking;
    int choice;
    string car;

    do {
        cout << "\n===== PARKING LOT MENU =====\n";
        cout << "1. Park New Car\n";
        cout << "2. Remove Car\n";
        cout << "3. Search Car\n";
        cout << "4. View Parked Cars\n";
        cout << "5. Total Cars Parked\n";
        cout << "6. Show Top Car\n";
        cout << "7. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Car Number: ";
            cin >> car;
            parking.push(car);
            break;

        case 2:
            cout << "Enter Car Number to Remove: ";
            cin >> car;
            parking.removeCar(car);
            break;

        case 3:
            cout << "Enter Car Number to Search: ";
            cin >> car;

            if (parking.search(car))
                cout << "Car Found in Parking Lot.\n";
            else
                cout << "Car Not Found.\n";
            break;

        case 4:
            parking.display();
            break;

        case 5:
            cout << "Total Cars: " << parking.count() << endl;
            break;

        case 6:
            if (!parking.isEmpty())
                cout << "Top Car: " << parking.top() << endl;
            else
                cout << "Parking Lot is Empty!\n";
            break;

        case 7:
            cout << "Program Exited.\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 7);

    return 0;
}
