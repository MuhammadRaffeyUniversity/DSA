#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int val)
    {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

class LinkedList
{
private:
    Node *head;
    Node *tail;

public:
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }
    void addNode(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    void display()
    {
        if (head == NULL)
        {
            cout << "LinkedList Empty" << endl;
            return;
        }
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void arrange()
    {
        if (head == NULL || head->next == NULL)
        {
            cout << "Linked List Empty or Already Sorted.\n";
            return;
        }
        Node *odd = head;
        Node *even = head->next;
        Node *oddHead = head;
        Node *evenHead = head->next;
        while (even && even->next)
        {
            odd->next = even->next;
            even->next->prev = odd;
            odd = odd->next;

            even->next = odd->next;
            if (odd->next)
                odd->next->prev = even;
            even = even->next;
        }
        evenHead->prev = odd;
        odd->next = evenHead;
        tail = odd;
        while (tail->next)
            tail = tail->next;
    }
};

int main()
{
    LinkedList L;
    L.addNode(1);
    L.addNode(2);
    L.addNode(3);
    L.addNode(4);
    L.addNode(5);
    L.arrange();
    L.display();
    return 0;
}