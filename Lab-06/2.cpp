#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

class Queue
{
    Node *front, *rear;

public:
    Queue()
    {
        front = rear = nullptr;
    }
    bool isEmpty()
    {
        return front == nullptr;
    }
    void enqueue(int value)
    {
        Node *newNode = new Node(value);
        if (rear == nullptr)
        {
            front = rear = newNode;
            rear->next = front;
            return;
        }
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty\n";
            return;
        }
        if (front == rear)
        {
            cout << "Dequeued: " << front->data << endl;
            delete front;
            front = rear = nullptr;
            return;
        }
        Node *temp = front;
        cout << "Dequeued: " << front->data << endl;
        front = front->next;
        rear->next = front;
        delete temp;
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty\n";
            return;
        }
        cout << "Queue elements: ";
        Node *current = front;
        do
        {
            cout << current->data << " ";
            current = current->next;
        } while (current != front);
        cout << endl;
    }
};

int main()
{

    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.dequeue();
    q.display();
    q.dequeue();
    q.display();
    return 0;
}