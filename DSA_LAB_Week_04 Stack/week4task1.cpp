
#include <iostream>
using namespace std;

// Abstract Stack Class
template <typename T>
class AbstractStack {
public:
    virtual void push(T value) = 0;
    virtual T pop() = 0;
    virtual T top() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual ~AbstractStack() {}
};

// Child Stack Class
template <typename T>
class myStack : public AbstractStack<T> {
private:
    T* arr;
    int maxSize;
    int stackTop;

public:
    myStack(int size) {
        maxSize = size;
        arr = new T[maxSize];
        stackTop = -1;
    }

    void push(T value) override {
        if (isFull()) {
            cout << "Stack is Full!\n";
            return;
        }

        arr[++stackTop] = value;
        cout << "Element pushed successfully.\n";
    }

    T pop() override {
        if (isEmpty()) {
            cout << "Stack is Empty!\n";
            return T();
        }

        return arr[stackTop--];
    }

    T top() const override {
        if (isEmpty()) {
            cout << "Stack is Empty!\n";
            return T();
        }

        return arr[stackTop];
    }

    bool isEmpty() const override {
        return stackTop == -1;
    }

    bool isFull() const override {
        return stackTop == maxSize - 1;
    }

    void display() const {
        if (isEmpty()) {
            cout << "Stack is Empty!\n";
            return;
        }

        cout << "Stack Elements (Top to Bottom):\n";

        for (int i = stackTop; i >= 0; i--) {
            cout << arr[i] << endl;
        }
    }

    ~myStack() {
        delete[] arr;
    }
};

int main() {
    myStack<int> s(5);
    int choice, value;

    do {
        cout << "\n===== STACK MENU =====\n";
        cout << "1. Push Element\n";
        cout << "2. Pop Element\n";
        cout << "3. Show Top Element\n";
        cout << "4. Check Empty\n";
        cout << "5. Check Full\n";
        cout << "6. Display Stack\n";
        cout << "7. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Value: ";
            cin >> value;
            s.push(value);
            break;

        case 2:
            cout << "Popped Element: " << s.pop() << endl;
            break;

        case 3:
            cout << "Top Element: " << s.top() << endl;
            break;

        case 4:
            cout << (s.isEmpty() ? "Stack is Empty" : "Stack is Not Empty") << endl;
            break;

        case 5:
            cout << (s.isFull() ? "Stack is Full" : "Stack is Not Full") << endl;
            break;

        case 6:
            s.display();
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
