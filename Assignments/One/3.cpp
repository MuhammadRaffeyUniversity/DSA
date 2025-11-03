#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string data;
    Node *next;
    Node(string val) : data(val), next(NULL) {}
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    void insertAtEnd(string value)
    {
        Node *newNode = new Node(value);

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    int searchBook(string bookTitle)
    {
        Node *temp = head;
        int position = 1;

        while (temp != NULL)
        {
            if (temp->data == bookTitle)
            {
                return position;
            }
            temp = temp->next;
            position++;
        }
        return -1;
    }

    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};

int main()
{
    LinkedList library;

    library.insertAtEnd("DSA");
    library.insertAtEnd("Linear");
    library.insertAtEnd("Theory of Automata");
    library.insertAtEnd("C++");
    library.insertAtEnd("Python");
    library.insertAtEnd("TypeScript");
    library.insertAtEnd("NextJS");

    cout << "Library Books:\n";
    library.display();

    string searchBook = "Python";
    int position = library.searchBook(searchBook);

    cout << "\nSearching for: " << searchBook << endl;
    if (position != -1)
    {
        cout << "Found at position: " << position << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }

    return 0;
}
