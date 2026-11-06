
#include <iostream>
using namespace std;

template <typename Type>
class List
{
protected:
    Type* arr;
    int maxSize;
    int currentSize;

public:
    List(int size = 10)
    {
        maxSize = (size > 0) ? size : 1;
        currentSize = 0;
        arr = new Type[maxSize];
    }

    List(const List<Type>& other)
    {
        maxSize = other.maxSize;
        currentSize = other.currentSize;

        arr = new Type[maxSize];

        for (int i = 0; i < currentSize; i++)
            arr[i] = other.arr[i];
    }

    virtual void addElementAtFirstIndex(Type value) = 0;
    virtual void addElementAtLastIndex(Type value) = 0;
    virtual Type removeElementFromEnd() = 0;
    virtual void removeElementFromStart() = 0;

    virtual ~List()
    {
        delete[] arr;
    }
};

template <typename Type>
class MyList : public List<Type>
{
public:

    MyList(int size = 10) : List<Type>(size) {}

    MyList(const MyList<Type>& other) : List<Type>(other) {}

    bool empty()
    {
        return this->currentSize == 0;
    }

    bool full()
    {
        return this->currentSize == this->maxSize;
    }

    int size()
    {
        return this->currentSize;
    }

    void addElementAtFirstIndex(Type value) override
    {
        if (full())
        {
            cout << "List is full!" << endl;
            return;
        }

        for (int i = this->currentSize; i > 0; i--)
            this->arr[i] = this->arr[i - 1];

        this->arr[0] = value;
        this->currentSize++;
    }

    void addElementAtLastIndex(Type value) override
    {
        if (full())
        {
            cout << "List is full!" << endl;
            return;
        }

        this->arr[this->currentSize] = value;
        this->currentSize++;
    }

    Type removeElementFromEnd() override
    {
        if (empty())
        {
            cout << "List is empty!" << endl;
            return Type{};
        }

        Type value = this->arr[this->currentSize - 1];
        this->currentSize--;

        return value;
    }

    void removeElementFromStart() override
    {
        if (empty())
        {
            cout << "List is empty!" << endl;
            return;
        }

        for (int i = 0; i < this->currentSize - 1; i++)
            this->arr[i] = this->arr[i + 1];

        this->currentSize--;
    }

    bool insertAt(int index, Type value)
    {
        if (full() || index < 0 ||
            index > this->currentSize)
            return false;

        for (int i = this->currentSize; i > index; i--)
            this->arr[i] = this->arr[i - 1];

        this->arr[index] = value;
        this->currentSize++;

        return true;
    }

    Type last()
    {
        if (empty())
        {
            cout << "List is empty!" << endl;
            return Type{};
        }

        return this->arr[this->currentSize - 1];
    }

    bool search(Type value)
    {
        for (int i = 0; i < this->currentSize; i++)
        {
            if (this->arr[i] == value)
                return true;
        }

        return false;
    }

    void display()
    {
        if (empty())
        {
            cout << "List is empty!" << endl;
            return;
        }

        cout << "List: ";

        for (int i = 0; i < this->currentSize; i++)
            cout << this->arr[i] << " ";

        cout << endl;
    }

    ~MyList() override = default;
};

int main()
{
    int capacity;

    cout << "Enter maximum size: ";
    cin >> capacity;

    if (capacity <= 0)
    {
        cout << "Invalid size!" << endl;
        return 0;
    }

    MyList<int> list(capacity);

    int choice, value, index;

    do
    {
        cout << "\n===== MY LIST MENU =====" << endl;
        cout << "1. Add at First" << endl;
        cout << "2. Add at Last" << endl;
        cout << "3. Remove from End" << endl;
        cout << "4. Remove from Start" << endl;
        cout << "5. Check Empty" << endl;
        cout << "6. Check Full" << endl;
        cout << "7. Current Size" << endl;
        cout << "8. Insert At Index" << endl;
        cout << "9. Last Element" << endl;
        cout << "10. Search Element" << endl;
        cout << "11. Display List" << endl;
        cout << "0. Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            list.addElementAtFirstIndex(value);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            list.addElementAtLastIndex(value);
            break;

        case 3:
            cout << "Removed: "
                << list.removeElementFromEnd() << endl;
            break;

        case 4:
            list.removeElementFromStart();
            cout << "First element removed." << endl;
            break;

        case 5:
            cout << (list.empty() ? "List is empty" :
                "List is not empty") << endl;
            break;

        case 6:
            cout << (list.full() ? "List is full" :
                "List is not full") << endl;
            break;

        case 7:
            cout << "Current size: " << list.size() << endl;
            break;

        case 8:
            cout << "Enter index: ";
            cin >> index;

            cout << "Enter value: ";
            cin >> value;

            if (list.insertAt(index, value))
                cout << "Inserted successfully!" << endl;
            else
                cout << "Invalid index or list is full!" << endl;
            break;

        case 9:
            if (!list.empty())
                cout << "Last element: " << list.last() << endl;
            else
                cout << "List is empty!" << endl;
            break;

        case 10:
            cout << "Enter value to search: ";
            cin >> value;

            if (list.search(value))
                cout << "Element found!" << endl;
            else
                cout << "Element not found!" << endl;
            break;

        case 11:
            list.display();
            break;

        case 0:
            cout << "Program terminated." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 0);

    return 0;
}
