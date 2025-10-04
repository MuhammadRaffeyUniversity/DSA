#include <iostream>
using namespace std;

int main()
{
    int arr[6] = {1, 2, 10, 3, 4, 5};
    int newArr[5];
    int size = sizeof(arr) / sizeof(arr[0]);
    int index = 2;
    int s = 0;
    for (int i = 0; i < size; i++)
    {
        if (i == index)
            continue;
        newArr[s] = arr[i];
        s++;
    }

    for (int i = 0; i < size - 1; i++)
    {
        cout << newArr[i] << " ";
    }
    cout << endl;
    return 0;
}