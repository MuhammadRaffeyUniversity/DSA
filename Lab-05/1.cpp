#include <iostream>
using namespace std;

class Queue
{
    int *arr;
    int front, rear;

public:
    Queue(int size)
    {
        arr = new int[size];
        rear = front = -1;
    }
    bool isFull(int size)
    {
        return rear == size - 1;
    }
    bool isEmpty()
    {
        return front == -1 || front > rear;
    }
    void enqueue(int size, int value)
    {
        if (isFull(size))
        {
            cout << "Queue is Full\n";
            return;
        }
        if (front == -1)
        {
            front = 0;
        }
        arr[++rear] = value;
    }
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty\n";
            return;
        }
        cout << "Dequeued: " << arr[front++] << endl;
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int size;
    cout << "Enter the size of the queue: ";
    cin >> size;
    Queue q(size);
    q.enqueue(size, 10);
    q.enqueue(size, 20);
    q.enqueue(size, 30);
    q.display();
    q.dequeue();
    q.display();
    q.dequeue();
    q.display();    
    return 0;
}