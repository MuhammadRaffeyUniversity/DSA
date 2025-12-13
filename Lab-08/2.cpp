#include <iostream>
using namespace std;

void printArray(const int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int partition(int arr[], int low, int high, int n)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
            cout << "Swap (i=" << i << ", j=" << j << ") -> ";
            printArray(arr, n);
        }
    }
    swap(arr[i + 1], arr[high]);
    cout << "Pivot swap (" << (i + 1) << " with " << high << ") -> ";
    printArray(arr, n);
    return i + 1;
}

void quicksort(int arr[], int low, int high, int n)
{
    if (low < high)
    {
        int pi = partition(arr, low, high, n);
        cout << "After partition (pi=" << pi << ") -> ";
        printArray(arr, n);

        quicksort(arr, low, pi - 1, n);
        quicksort(arr, pi + 1, high, n);
    }
}
int main()
{
    int elements;
    cout << "Enter number of elements: ";
    cin >> elements;
    int arr[elements];
    cout << "Enter " << elements << " elements: ";
    for (int i = 0; i < elements; i++)
    {
        cin >> arr[i];
    }
    cout << "Initial array: ";
    printArray(arr, elements);

    quicksort(arr, 0, elements - 1, elements);
    cout << "Sorted array: ";
    for (int i = 0; i < elements; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}