#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val) : data(val), next(NULL) {}
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

    void insertAtBeginning(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }
    void insertAtEnd(int value)
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
    void insertAtPosition(int value, int position)
    {
        if (position == 0)
        {
            insertAtBeginning(value);
            return;
        }

        Node *newNode = new Node(value);

        Node *temp = head;
        for (int i = 0; i < position - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "Position out of bounds" << endl;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }
    void remove()
    {
        if (head == NULL)
        {
            return;
        }

        Node *temp = head;
        head = temp->next;
        delete temp;
    }
    void removeAtEnd()
    {
        if (head == NULL)
        {
            return;
        }
        Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    void removeAtPosition(int pos)
    {
        if (head == NULL)
        {
            return;
        }
        if (pos == 0)
        {
            remove();
        }
        Node *temp = head;
        for (int i = 0; i < pos - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }
        if (temp == NULL || temp->next == NULL)
        {
            cout << "Position out of bounds" << endl;
            return;
        }
        Node *toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
    }
    void bubbleSort()
    {
        if (head == NULL)
        {
            return;
        }
        bool swapped;
        Node *start;
        Node *end = NULL;
        do
        {
            swapped = false;
            start = head;

            while (start->next != end)
            {
                if (start->data > start->next->data)
                {
                    swap(start->data, start->next->data);
                    swapped = true;
                }
                start = start->next;
            }
            end = start;
        } while (swapped);
    }

    int searchElement(int key)
    {
        Node *temp = head;
        int position = 1;

        while (temp != NULL)
        {
            if (temp->data == key)
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
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.display();
    list.insertAtBeginning(50);
    list.display();
    list.insertAtPosition(3, 2);
    list.display();
    cout << "Sorting the Linked List now\n\n";
    list.bubbleSort();
    list.display();
    // list.display();
    // list.remove();
    // list.display();
    // list.removeAtEnd();
    // list.display();
    // list.removeAtPosition(1);
    // list.display();
    return 0;
}