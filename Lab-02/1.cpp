#include <iostream>
using namespace std;

class BinarySearch
{
public:
    int search(int arr[], int size, int target)
    {
        int left = 0;
        int right = size - 1;

        while (left <= right)
        {
            int mid = left + (right) / 2;

            if (arr[mid] == target)
            {
                return mid;
            }
            else if (arr[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return -1;
    }
};

int main()
{
    int a[] = {10, 20, 30, 40, 50};
    int size = sizeof(a) / sizeof(a[0]);
    int target = 30;
    BinarySearch bs;
    int result = bs.search(a, size, target);
    if (result == -1)
    {
        cout << "Element not found in the array" << endl;
    }
    else
    {

        cout << "Element found at index: " << result << endl;
    }

    return 0;
}