
#include <iostream>
#include <limits>
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

        this->arr[this->currentSize++] = value;
    }

    Type removeElementFromEnd() override
    {
        if (empty())
        {
            cout << "List is empty!" << endl;
            return Type{};
        }

        return this->arr[--this->currentSize];
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
            return Type{};

        return this->arr[this->currentSize - 1];
    }

    bool search(Type value)
    {
        for (int i = 0; i < this->currentSize; i++)
            if (this->arr[i] == value)
                return true;

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

template <typename Type>
class CustomList : public MyList<Type>
{
private:

    bool isPrime(Type n)
    {
        if (n < 2)
            return false;

        for (long long i = 2; i <= n / i; i++)
        {
            if (n % i == 0)
                return false;
        }

        return true;
    }

    void rotateRight(int start, int end, int r)
    {
        int length = end - start;

        if (length <= 1)
            return;

        r = ((r % length) + length) % length;

        for (int k = 0; k < r; k++)
        {
            Type temp = this->arr[end - 1];

            for (int i = end - 1; i > start; i--)
                this->arr[i] = this->arr[i - 1];

            this->arr[start] = temp;
        }
    }

    void rotateLeft(int start, int end, int r)
    {
        int length = end - start;

        if (length <= 1)
            return;

        r = ((r % length) + length) % length;

        for (int k = 0; k < r; k++)
        {
            Type temp = this->arr[start];

            for (int i = start; i < end - 1; i++)
                this->arr[i] = this->arr[i + 1];

            this->arr[end - 1] = temp;
        }
    }

public:

    CustomList(int size = 10) : MyList<Type>(size) {}

    CustomList(const CustomList<Type>& other)
        : MyList<Type>(other) {}

    // Sum of prime numbers
    Type sum_ofPrime()
    {
        Type sum = Type{};

        for (int i = 0; i < this->currentSize; i++)
        {
            if (isPrime(this->arr[i]))
                sum += this->arr[i];
        }

        return sum;
    }

    // Second maximum even number
    Type secondMaxEven()
    {
        Type max = Type{};
        Type second = Type{};

        bool foundMax = false;
        bool foundSecond = false;

        for (int i = 0; i < this->currentSize; i++)
        {
            Type v = this->arr[i];

            if (v % 2 == 0)
            {
                if (!foundMax || v > max)
                {
                    if (foundMax && v != max)
                    {
                        second = max;
                        foundSecond = true;
                    }

                    max = v;
                    foundMax = true;
                }
                else if (v < max &&
                    (!foundSecond || v > second))
                {
                    second = v;
                    foundSecond = true;
                }
            }
        }

        if (!foundSecond)
        {
            cout << "Second maximum even not found!" << endl;
            return Type{};
        }

        return second;
    }

    // Second minimum odd number
    Type secondMinOdd()
    {
        Type min = Type{};
        Type second = Type{};

        bool foundMin = false;
        bool foundSecond = false;

        for (int i = 0; i < this->currentSize; i++)
        {
            Type v = this->arr[i];

            if (v % 2 != 0)
            {
                if (!foundMin || v < min)
                {
                    if (foundMin && v != min)
                    {
                        second = min;
                        foundSecond = true;
                    }

                    min = v;
                    foundMin = true;
                }
                else if (v > min &&
                    (!foundSecond || v < second))
                {
                    second = v;
                    foundSecond = true;
                }
            }
        }

        if (!foundSecond)
        {
            cout << "Second minimum odd not found!" << endl;
            return Type{};
        }

        return second;
    }

    // Print duplicates
    void printDuplicates()
    {
        bool found = false;

        cout << "Duplicates: ";

        for (int i = 0; i < this->currentSize; i++)
        {
            bool printed = false;

            for (int j = 0; j < i; j++)
            {
                if (this->arr[i] == this->arr[j])
                {
                    printed = true;
                    break;
                }
            }

            if (printed)
                continue;

            for (int j = i + 1; j < this->currentSize; j++)
            {
                if (this->arr[i] == this->arr[j])
                {
                    cout << this->arr[i] << " ";
                    found = true;
                    break;
                }
            }
        }

        if (!found)
            cout << "No duplicates found.";

        cout << endl;
    }

    // Clockwise rotation
    void rotateClockwaise(int r)
    {
        int mid = this->currentSize / 2;

        rotateRight(0, mid, r);
        rotateRight(mid, this->currentSize, r);
    }

    // Anti-clockwise rotation
    void rotateanitclockwaise(int rt)
    {
        int mid = this->currentSize / 2;

        rotateLeft(0, mid, rt);
        rotateLeft(mid, this->currentSize, rt);
    }

    ~CustomList() override = default;
};

int main()
{
    int capacity;

    cout << "Enter maximum list size: ";
    cin >> capacity;

    if (capacity <= 0)
    {
        cout << "Invalid size!" << endl;
        return 0;
    }

    CustomList<int> list(capacity);

    int choice, value, index, r;

    do
    {
        cout << "\n========== CUSTOM LIST MENU ==========\n";
        cout << "1. Add at First\n";
        cout << "2. Add at Last\n";
        cout << "3. Remove from End\n";
        cout << "4. Remove from Start\n";
        cout << "5. Check Empty\n";
        cout << "6. Check Full\n";
        cout << "7. Current Size\n";
        cout << "8. Insert At Index\n";
        cout << "9. Last Element\n";
        cout << "10. Search Element\n";
        cout << "11. Sum of Prime Numbers\n";
        cout << "12. Second Maximum Even\n";
        cout << "13. Second Minimum Odd\n";
        cout << "14. Print Duplicates\n";
        cout << "15. Rotate Clockwise\n";
        cout << "16. Rotate Anti-clockwise\n";
        cout << "17. Display List\n";
        cout << "0. Exit\n";
        cout << "======================================\n";

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
            if (!list.empty())
                cout << "Removed: "
                << list.removeElementFromEnd() << endl;
            else
                cout << "List is empty!" << endl;
            break;

        case 4:
            list.removeElementFromStart();
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
            cout << "Size: " << list.size() << endl;
            break;

        case 8:
            cout << "Enter index: ";
            cin >> index;

            cout << "Enter value: ";
            cin >> value;

            if (list.insertAt(index, value))
                cout << "Inserted successfully!" << endl;
            else
                cout << "Invalid index or list full!" << endl;
            break;

        case 9:
            if (!list.empty())
                cout << "Last element: " << list.last() << endl;
            else
                cout << "List is empty!" << endl;
            break;

        case 10:
            cout << "Enter value: ";
            cin >> value;

            cout << (list.search(value) ?
                "Element found!" : "Element not found!")
                << endl;
            break;

        case 11:
            cout << "Prime sum: "
                << list.sum_ofPrime() << endl;
            break;

        case 12:
            if (list.size() >= 2)
                cout << "Second maximum even: "
                << list.secondMaxEven() << endl;
            else
                cout << "Not enough elements!" << endl;
            break;

        case 13:
            if (list.size() >= 2)
                cout << "Second minimum odd: "
                << list.secondMinOdd() << endl;
            else
                cout << "Not enough elements!" << endl;
            break;

        case 14:
            list.printDuplicates();
            break;

        case 15:
            cout << "Enter rotations: ";
            cin >> r;

            list.rotateClockwaise(r);
            list.display();
            break;

        case 16:
            cout << "Enter rotations: ";
            cin >> r;

            list.rotateanitclockwaise(r);
            list.display();
            break;

        case 17:
            list.display();
            break;

        case 0:
            cout << "Program terminated!" << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 0);

    return 0;
}
