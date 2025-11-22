#include <iostream>
#include <string>
using namespace std;

class Stack
{
    string arr[100];
    int top;

public:
    Stack()
    {
        top = -1;
    }
    bool isEmpty()
    {
        return top == -1;
    }
    void push(string word)
    {
        arr[++top] = word;
    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "Nothing to undo." << endl;
            return;
        }
        cout << "Undo performed. Removed: " << arr[top--] << endl;
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Text is empty." << endl;
            return;
        }
        cout << "Current text:\n----------------------------------------\n ";
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << "\n";
        }
        cout << "\n------------------------------------------\n";
    }
};

int main()
{
    Stack s;
    int choice;
    string word;

    while (true)
    {
        cout << "1. Add a word (Push)" << endl;
        cout << "2. Perform Undo (Pop)" << endl;
        cout << "3. Display current text" << endl;
        cout << "4. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter a word: ";
            cin >> word;
            s.push(word);
        }
        else if (choice == 2)
        {
            s.pop();
        }
        else if (choice == 3)
        {
            s.display();
        }
        else if (choice == 4)
        {
            break;
        }
    }
    return 0;
}
