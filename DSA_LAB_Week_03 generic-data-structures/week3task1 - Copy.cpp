
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
    // Parameterized constructor
    List(int size = 10)
    {
        maxSize = (size > 0) ? size : 1;
        currentSize = 0;
        arr = new Type[maxSize];
    }

    // Copy constructor
    List(const List<Type>& other)
    {
        maxSize = other.maxSize;
        currentSize = other.currentSize;

        arr = new Type[maxSize];

        for (int i = 0; i < currentSize; i++)
        {
            arr[i] = other.arr[i];
        }
    }

    virtual void addElementAtFirstIndex(Type value) = 0;

    virtual void addElementAtLastIndex(Type value) = 0;

    virtual Type removeElementFromEnd() = 0;

    virtual void removeElementFromStart() = 0;

    // Virtual destructor
    virtual ~List()
    {
        delete[] arr;
    }
};

// Main function
int main()
{
    cout << "Task 1: Abstract Generic List Class" << endl;

    cout << "List class created successfully." << endl;

    return 0;
}
