
#include <iostream>
using namespace std;

// Abstract Queue Class
template <typename T>
class AbstractQueue {
public:
    virtual void enQueue(T value) = 0;
    virtual T deQueue() = 0;
    virtual T front() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;

    virtual ~AbstractQueue() {}
};

// Child Class myQueue
template <typename T>
class myQueue : public AbstractQueue<T> {
private:
    T* arr;
    int capacity;
    int count;
    int rear;

public:
    // Constructor
    myQueue(int size) {
        capacity = size;
        arr = new T[capacity];
        count = 0;
        rear = -1;
    }

    // Insert element into queue
    void enQueue(T value) override {
        if (isFull()) {
            cout << "Queue is Full!" << endl;
            return;
        }

        rear++;
        arr[rear] = value;
        count++;

        cout << value << " inserted successfully." << endl;
    }

    // Remove and return front element
    T deQueue() override {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return T();
        }

        T value = arr[0];

        for (int i = 0; i < count - 1; i++) {
            arr[i] = arr[i + 1];
        }

        count--;
        rear--;

        cout << value << " removed successfully." << endl;
        return value;
    }

    // Return front element
    T front() const override {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return T();
        }

        return arr[0];
    }
    bool isEmpty() const override {
        return count == 0;
    }
    bool isFull() const override {
        return count == capacity;
    }
    void display() const {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }

        cout << "Queue Elements (Front to Rear): ";

        for (int i = 0; i < count; i++) {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
    ~myQueue() {
        delete[] arr;
    }
};
int main() {
    int size;
    int choice;
    int value;

    cout << "Enter maximum size of Queue: ";
    cin >> size;

    if (size <= 0) {
        cout << "Invalid queue size!" << endl;
        return 0;
    }

    myQueue<int> q(size);

    do {
        cout << "\n===== QUEUE MENU =====" << endl;
        cout << "1. Enqueue (Insert)" << endl;
        cout << "2. Dequeue (Remove)" << endl;
        cout << "3. Front Element" << endl;
        cout << "4. Display Queue" << endl;
        cout << "5. Check Empty" << endl;
        cout << "6. Check Full" << endl;
        cout << "7. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            q.enQueue(value);
            break;

        case 2:
            if (!q.isEmpty())
                q.deQueue();
            else
                cout << "Queue is Empty!" << endl;
            break;

        case 3:
            if (!q.isEmpty())
                cout << "Front Element: " << q.front() << endl;
            else
                cout << "Queue is Empty!" << endl;
            break;

        case 4:
            q.display();
            break;

        case 5:
            if (q.isEmpty())
                cout << "Queue is Empty." << endl;
            else
                cout << "Queue is Not Empty." << endl;
            break;

        case 6:
            if (q.isFull())
                cout << "Queue is Full." << endl;
            else
                cout << "Queue is Not Full." << endl;
            break;

        case 7:
            cout << "Program Terminated!" << endl;
            break;

        default:
            cout << "Invalid Choice! Try Again." << endl;
        }

    } while (choice != 7);

    return 0;
}
