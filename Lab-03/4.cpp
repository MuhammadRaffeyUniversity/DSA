#include <iostream>
using namespace std;
int main()
{
    int saleData[] = {12500, 9800, 14300, 11200, 15700, 8900, 13400};
    int size = sizeof(saleData) / sizeof(saleData[0]);

    for (int i = 1; i < size; i++)
    {
        int key = saleData[i];
        int j = i - 1;

        while (j >= 0 && saleData[j] < key)
        {
            saleData[j + 1] = saleData[j];
            j--;
        }
        saleData[j + 1] = key;
    }
    for (int i = 0; i < size; i++)
    {
        cout << saleData[i] << endl;
    }
    return 0;
}