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
        return rear + 1 % size == front;
    }
    bool isEmpty()
    {
        return front == -1;
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
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % size;
        }
        arr[rear] = value;
    }
    void dequeue(int size)
    {
        if (isEmpty())
        {
            cout << "Queue is Empty\n";
            return;
        }
        if (front == rear)
        {
            cout << "Dequeued: " << arr[front] << endl;
            front = rear = -1;
        }
        else
        {
            cout << "Dequeued: " << arr[front] << endl;
            front = (front + 1) % size;
        }
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
    q.dequeue(size);
    q.display();
    q.dequeue(size);
    q.display();
    return 0;
}