#include <iostream>
using namespace std;

class BubbleSort
{
public:
    void sort(int arr[], int size)
    {
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {

                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
};

int main()
{
    int a[] = {23, 5, 17, 8, 42, 3, 29, 15, 11, 37};
    int size = sizeof(a) / sizeof(a[0]);
    BubbleSort bs;
    bs.sort(a, size);
    cout << "Sorted array: ";
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}