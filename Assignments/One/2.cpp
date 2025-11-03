#include <iostream>
#include <string>
using namespace std;

void selectionSort(string arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
        }
        if (minIdx != i)
        {
            swap(arr[i], arr[minIdx]);
        }
    }
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

void display(string arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}

int main()
{
    string books[] = {"DSA", "Linear", "Theory of Automata", "C++",
                      "Python", "TypeScript", "NextJS"};

    int n = sizeof(books) / sizeof(books[0]);

    cout << "Selection Sort:\n";
    selectionSort(books, n);
    display(books, n);

    cout << "\nBubble Sort:\n";
    bubbleSort(books, n);
    display(books, n);

    return 0;
}
