#include <iostream>
using namespace std;
int main()
{
    int marks[] = {78, 92, 67, 85, 90, 81, 69};
    int size = sizeof(marks) / sizeof(marks[0]);
    bool sorted = false;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (marks[j] > marks[j + 1])
            {

                int temp = marks[j];
                marks[j] = marks[j + 1];
                marks[j + 1] = temp;
            }
            else
            {
                sorted = true;
            }
        }
        if (!sorted)
        {
            break;
        }
    }

    for (int i = 0; i < size; i++)
    {
        cout << marks[i] << endl;
    }
    return 0;
}