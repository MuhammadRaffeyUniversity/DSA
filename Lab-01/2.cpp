#include <iostream>
using namespace std;

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int newArr[6];
    int size = sizeof(arr) / sizeof(arr[0]);
    int index = 2;
    int data = 10;
    for (int i = 0; i < size + 1; i++)
    {
        if (i < index)
        {
            newArr[i] = arr[i];
        }
        else if (i == index)
        {
            newArr[i] = data;
        }
        else
        {
            newArr[i] = arr[i - 1];
        }
    }

    for (int i = 0; i < size + 1; i++)
    {
        cout << newArr[i] << " ";
    }
    cout << endl;
    return 0;
}