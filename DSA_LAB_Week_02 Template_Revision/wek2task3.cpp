
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Abstract Base Class
class LibraryItem
{
public:
    virtual void display() = 0;
    virtual ~LibraryItem() {}
};

// Book Class
class Book : public LibraryItem
{
private:
    string title;
    string author;
    int pages;

public:
    Book(string t, string a, int p)
    {
        title = t;
        author = a;
        pages = p;
    }

    string getTitle()
    {
        return title;
    }

    int getPages()
    {
        return pages;
    }

    void display() override
    {
        cout << "Book Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Pages: " << pages << endl;
    }
};

// Newspaper Class
class Newspaper : public LibraryItem
{
private:
    string name;
    string date;
    string edition;

public:
    Newspaper(string n, string d, string e)
    {
        name = n;
        date = d;
        edition = e;
    }

    string getName()
    {
        return name;
    }

    string getEdition()
    {
        return edition;
    }

    void display() override
    {
        cout << "Newspaper Name: " << name << endl;
        cout << "Date: " << date << endl;
        cout << "Edition: " << edition << endl;
    }
};

// Library Class
class Library
{
private:
    vector<Book> books;
    vector<Newspaper> newspapers;

public:

    // Add Book
    void addBook(Book book)
    {
        books.push_back(book);
    }

    // Add Newspaper
    void addNewspaper(Newspaper newspaper)
    {
        newspapers.push_back(newspaper);
    }

    // Display Collection
    void displayCollection()
    {
        cout << "\nBooks Collection:\n";

        for (int i = 0; i < books.size(); i++)
        {
            cout << "\n";
            books[i].display();
        }

        cout << "\nNewspapers Collection:\n";

        for (int i = 0; i < newspapers.size(); i++)
        {
            cout << "\n";
            newspapers[i].display();
        }
    }

    // Sort Books by Pages
    void sortBooksByPages()
    {
        sort(books.begin(), books.end(),
            [](Book a, Book b)
            {
                return a.getPages() < b.getPages();
            });
    }

    // Sort Newspapers by Edition
    void sortNewspapersByEdition()
    {
        sort(newspapers.begin(), newspapers.end(),
            [](Newspaper a, Newspaper b)
            {
                return a.getEdition() < b.getEdition();
            });
    }

    // Linear Search for Book by Title
    Book* searchBookByTitle(string title)
    {
        for (int i = 0; i < books.size(); i++)
        {
            if (books[i].getTitle() == title)
            {
                return &books[i];
            }
        }

        return nullptr;
    }

    // Linear Search for Newspaper by Name
    Newspaper* searchNewspaperByName(string name)
    {
        for (int i = 0; i < newspapers.size(); i++)
        {
            if (newspapers[i].getName() == name)
            {
                return &newspapers[i];
            }
        }

        return nullptr;
    }
};

// Main Function
int main()
{
    // Create book objects
    Book book1("The Catcher in the Rye",
        "J.D. Salinger", 277);

    Book book2("To Kill a Mockingbird",
        "Harper Lee", 324);

    // Create newspaper objects
    Newspaper newspaper1("Washington Post",
        "2024-10-13",
        "Morning Edition");

    Newspaper newspaper2("The Times",
        "2024-10-12",
        "Weekend Edition");

    // Create Library object
    Library library;

    // Add books and newspapers
    library.addBook(book1);
    library.addBook(book2);

    library.addNewspaper(newspaper1);
    library.addNewspaper(newspaper2);

    // Display collection before sorting
    cout << "Before Sorting:\n";
    library.displayCollection();

    // Sort books and newspapers
    library.sortBooksByPages();
    library.sortNewspapersByEdition();

    // Display collection after sorting
    cout << "\nAfter Sorting:\n";
    library.displayCollection();

    // Search for a book
    Book* foundBook =
        library.searchBookByTitle("The Catcher in the Rye");

    if (foundBook)
    {
        cout << "\nFound Book:\n";
        foundBook->display();
    }
    else
    {
        cout << "\nBook not found.\n";
    }

    // Search for a newspaper
    Newspaper* foundNewspaper =
        library.searchNewspaperByName("The Times");

    if (foundNewspaper)
    {
        cout << "\nFound Newspaper:\n";
        foundNewspaper->display();
    }
    else
    {
        cout << "\nNewspaper not found.\n";
    }

    return 0;
}
