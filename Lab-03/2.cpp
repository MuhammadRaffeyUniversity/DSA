#include <iostream>  //Muhammad Raffey
using namespace std; // 70153209
int main()
{
    int bookPrice[] = {250, 320, 450, 500, 600, 750, 800, 950, 1200};
    int toSearch = 750;
    int left = 0;
    int right = sizeof(bookPrice) / sizeof(bookPrice[0]) - 1;
    bool found = false;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (bookPrice[mid] == toSearch)
        {
            found = true;
            break;
        }
        else if (bookPrice[mid] < toSearch)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    if (found)
    {
        cout << "Book with price " << toSearch << " found in the inventory." << endl;
    }
    else
    {
        cout << "Book with price " << toSearch << " not found in the inventory." << endl;
    }

    return 0;
}