#include <iostream>
using namespace std;

class InsertionSort
{
public:
    void sort(int arr[], int size)
    {
        for (int i = 1; i < size; i++)
        {
            int key = arr[i];
            int j = i - 1;

            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }
};

int main()
{
    int a[] = {23, 5, 17, 8, 42, 3, 29, 15, 11, 37};
    int size = sizeof(a) / sizeof(a[0]);
    InsertionSort is;
    is.sort(a, size);
    cout << "Sorted array: ";
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}