#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right)
{
    int s1 = mid - left + 1;
    int s2 = right - mid;
    int L[s1], R[s2];
    for (int i = 0; i < s1; i++)
    {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < s2; j++)
    {
        R[j] = arr[mid + 1 + j];
    }
    int i = 0, j = 0, k = left;
    while (i < s1 && j < s2)
    {
        if (L[i] < R[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
        }
    }
    while (i < s1)
    {
        arr[k++] = L[i++];
    }
    while (j < s2)
    {
        arr[k++] = R[j++];
    }
}

void mergesort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);
        merge(arr, left, mid, right);
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
    mergesort(arr, 0, elements - 1);
    cout << "Sorted array: ";
    for (int i = 0; i < elements; i++)
    {
        cout << arr[i]<<" ";
    }
    cout<<endl;
}