
#include <iostream>
using namespace std;

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

template <typename T>
class myStack : public AbstractStack<T> {
private:
    T* arr;
    T* minArr;
    int maxSize;
    int stackTop;
    int minTop;

public:
    myStack(int size) {
        maxSize = size;
        arr = new T[maxSize];
        minArr = new T[maxSize];

        stackTop = -1;
        minTop = -1;
    }

    void push(T value) override {
        if (isFull()) {
            cout << "Stack is Full!\n";
            return;
        }

        arr[++stackTop] = value;

        if (minTop == -1 || value <= minArr[minTop]) {
            minArr[++minTop] = value;
        }

        cout << "Element Pushed Successfully.\n";
    }

    T pop() override {
        if (isEmpty()) {
            cout << "Stack is Empty!\n";
            return T();
        }

        T value = arr[stackTop--];

        if (value == minArr[minTop]) {
            minTop--;
        }

        return value;
    }

    T top() const override {
        if (isEmpty()) {
            cout << "Stack is Empty!\n";
            return T();
        }

        return arr[stackTop];
    }

    T getMin() const {
        if (isEmpty()) {
            cout << "Stack is Empty!\n";
            return T();
        }

        return minArr[minTop];
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

        cout << "Stack Elements:\n";

        for (int i = stackTop; i >= 0; i--) {
            cout << arr[i] << endl;
        }
    }

    ~myStack() {
        delete[] arr;
        delete[] minArr;
    }
};

int main() {
    myStack<int> s(10);
    int choice, value;

    do {
        cout << "\n===== MIN STACK MENU =====\n";
        cout << "1. Push Element\n";
        cout << "2. Pop Element\n";
        cout << "3. Show Top Element\n";
        cout << "4. Check Empty\n";
        cout << "5. Check Full\n";
        cout << "6. Display Stack\n";
        cout << "7. Show Minimum Element\n";
        cout << "8. Exit\n";
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
            if (!s.isEmpty())
                cout << "Minimum Element: " << s.getMin() << endl;
            else
                cout << "Stack is Empty!\n";
            break;

        case 8:
            cout << "Program Exited.\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 8);

    return 0;
}
