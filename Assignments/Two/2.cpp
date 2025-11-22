#include <iostream>
#include <string>
using namespace std;

class Patient
{
public:
    int patient_id;
    string name;
    int age;
    string symptoms;
    Patient *next;

    Patient(int id, string n, int a, string s) : patient_id(id), name(n), age(a), symptoms(s), next(NULL) {}
};

class Queue
{
    Patient *front, *rear;

public:
    Queue()
    {
        front = rear = NULL;
    }

    bool isEmpty()
    {
        return front == NULL;
    }

    void enqueue(int patient_id, string name, int age, string symptoms)
    {
        Patient *newPatient = new Patient(patient_id, name, age, symptoms);
        if (rear == NULL)
        {
            front = rear = newPatient;
            cout << "Patient Added: " << name << endl;
            return;
        }
        rear->next = newPatient;
        rear = newPatient;
        cout << "Patient Added: " << name << endl;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "No patients waiting for treatment." << endl;
            return;
        }
        Patient *temp = front;
        cout << "Treating Patient: " << front->name << endl;
        front = front->next;
        if (front == NULL)
        {
            rear = NULL;
        }
        delete temp;
    }

    void frontPatient()
    {
        if (isEmpty())
        {
            cout << "No patients waiting for treatment." << endl;
            return;
        }
        cout << "Next Patient to Treat:" << endl;
        cout << "ID: " << front->patient_id << ", Name: " << front->name << ", Age: " << front->age << ", Symptoms: " << front->symptoms << endl;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "No patients waiting for treatment." << endl;
            return;
        }
        cout << "Current Emergency Queue:" << endl;
        Patient *current = front;
        while (current != NULL)
        {
            cout << current->patient_id << " - " << current->name << " (" << current->age << ") - " << current->symptoms << endl;
            current = current->next;
        }
    }
};

int main()
{
    Queue q;

    q.enqueue(101, "Ahmed", 45, "Chest pain");
    q.enqueue(102, "Sonia", 30, "High fever");
    q.enqueue(103, "Bilal", 60, "Breathing difficulty");

    q.dequeue();

    q.enqueue(104, "Mina", 28, "Migraine");
    q.enqueue(105, "Zaid", 50, "High blood pressure");

    q.frontPatient();

    q.display();

    return 0;
}
