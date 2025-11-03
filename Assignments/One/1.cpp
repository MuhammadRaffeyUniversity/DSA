#include <iostream>
#include <string>
using namespace std;

bool LinearSearch(string arr[], int n, string target, int &index)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            index = i;
            return true;
        }
    }
    return false;
}

bool binarySearch(string arr[], int n, string target, int &index)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
        {
            index = mid;
            return true;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return false;
}

void bubbleSort(string arr[], int n)
{
    bool sorted;
    int i = 0;
    do
    {
        sorted = false;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                sorted = true;
            }
        }
        i++;
    } while (sorted);
}

int main()
{
    string books[] = {"The Hobbit", "1984", "To Kill a Mockingbird", "Pride and Prejudice",
                      "War and Peace", "The Great Gatsby", "Crime and Punishment"};
    int n = 7;

    string sortedBooks[8];
    for (int i = 0; i < n; i++)
    {
        sortedBooks[i] = books[i];
    }
    bubbleSort(sortedBooks, n);

    string searchBook = "1984";
    int index;

    cout << "Library Book Search System\n\n";
    cout << "Searching for: " << searchBook << "\n\n";

    if (LinearSearch(books, n, searchBook, index))
    {
        cout << "Linear Search: Found at index " << index << "\n";
    }
    else
    {
        cout << "Linear Search: Not found\n";
    }

    if (binarySearch(sortedBooks, n, searchBook, index))
    {
        cout << "Binary Search: Found at index " << index << "\n";
    }
    else
    {
        cout << "Binary Search: Not found\n";
    }

    return 0;
}