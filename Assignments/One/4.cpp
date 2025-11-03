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

class WaitingList
{
private:
    Node *head;

public:
    WaitingList()
    {
        head = NULL;
    }

    void addToWaitingList(string name)
    {
        Node *newNode = new Node(name);
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

    void displayWaitingList()
    {
        if (head == NULL)
        {
            cout << "No one in waiting list\n";
            return;
        }
        Node *temp = head;
        int position = 1;
        while (temp != NULL)
        {
            cout << position << ". " << temp->data << endl;
            temp = temp->next;
            position++;
        }
    }
};

bool searchBook(string arr[], int n, string target, int &index)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            index = i;
            return true;
        }
    }
    return false;
}

void bubbleSort(string arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void printBooks(string arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ". " << arr[i] << endl;
    }
}

int main()
{
    string books[] = {"DSA", "Linear", "Theory of Automata", "C++",
                      "Python", "TypeScript", "NextJS"};
    int n = 7;

    WaitingList waitingList;

    cout << "=== Library Management System ===\n\n";

    cout << "Available Books:\n";
    printBooks(books, n);

    cout << "\n--- Searching for a Book ---\n";
    string searchTitle = "Python";
    int index;
    if (searchBook(books, n, searchTitle, index))
    {
        cout << "'" << searchTitle << "' found at position " << (index + 1) << endl;
    }
    else
    {
        cout << "Book not found\n";
    }

    cout << "\n--- Sorting Books ---\n";
    string sortedBooks[7];
    for (int i = 0; i < n; i++)
    {
        sortedBooks[i] = books[i];
    }
    bubbleSort(sortedBooks, n);
    cout << "Books in alphabetical order:\n";
    printBooks(sortedBooks, n);

    cout << "\n--- Waiting List for 'DSA' ---\n";
    waitingList.addToWaitingList("Raffey");
    waitingList.addToWaitingList("Annas");
    waitingList.addToWaitingList("Junaid");
    waitingList.displayWaitingList();

    return 0;
}
