
#include <iostream>
#include <stack>
#include <string>
using namespace std;

class TextEditor {
private:
    string text;
    stack<pair<char, char>> undoStack;
    stack<pair<char, char>> redoStack;

public:

    // Type a character
    void typeCharacter(char ch) {
        text += ch;

        undoStack.push({ 'T', ch });

        while (!redoStack.empty())
            redoStack.pop();

        cout << "Character Added.\n";
    }

    // Delete last character
    void deleteCharacter() {
        if (text.empty()) {
            cout << "Text is Empty!\n";
            return;
        }

        char ch = text.back();
        text.pop_back();

        undoStack.push({ 'D', ch });

        while (!redoStack.empty())
            redoStack.pop();

        cout << "Character Deleted.\n";
    }

    // Undo operation
    void undo() {
        if (undoStack.empty()) {
            cout << "Nothing to Undo!\n";
            return;
        }

        pair<char, char> action = undoStack.top();
        undoStack.pop();

        if (action.first == 'T') {
            text.pop_back();
        }
        else if (action.first == 'D') {
            text += action.second;
        }

        redoStack.push(action);

        cout << "Undo Successful.\n";
    }

    // Redo operation
    void redo() {
        if (redoStack.empty()) {
            cout << "Nothing to Redo!\n";
            return;
        }

        pair<char, char> action = redoStack.top();
        redoStack.pop();

        if (action.first == 'T') {
            text += action.second;
        }
        else if (action.first == 'D') {
            text.pop_back();
        }

        undoStack.push(action);

        cout << "Redo Successful.\n";
    }

    // Display current text
    void display() {
        cout << "\nCurrent Text: " << text << endl;
    }
};

int main() {
    TextEditor editor;
    int choice;
    char ch;

    do {
        cout << "\n===== TEXT EDITOR MENU =====\n";
        cout << "1. Type Character\n";
        cout << "2. Delete Character\n";
        cout << "3. Undo\n";
        cout << "4. Redo\n";
        cout << "5. Display Text\n";
        cout << "6. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Character: ";
            cin >> ch;
            editor.typeCharacter(ch);
            break;

        case 2:
            editor.deleteCharacter();
            break;

        case 3:
            editor.undo();
            break;

        case 4:
            editor.redo();
            break;

        case 5:
            editor.display();
            break;

        case 6:
            cout << "Text Editor Closed.\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 6);

    return 0;
}
