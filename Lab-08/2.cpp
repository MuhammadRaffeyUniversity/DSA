#include <iostream>
#include <iomanip>
#include <string>
#include <utility>
using namespace std;

// Debug levels:
// 0 = no debug
// 1 = pretty dry-run (recommended)
// 2 = verbose (also prints swaps)
static const int DEBUG_LEVEL = 1;

static int gStep = 0;

string indent(int depth)
{
    return string(depth * 2, ' ');
}

void logLine(int depth, const string &msg)
{
    if (DEBUG_LEVEL == 0)
        return;
    cout << setw(3) << ++gStep << " | " << indent(depth) << msg << '\n';
}

void logArray(int depth, const int arr[], int n)
{
    if (DEBUG_LEVEL == 0)
        return;
    cout << setw(3) << ++gStep << " | " << indent(depth) << "A = [ ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
        if (i + 1 < n)
            cout << ' ';
    }
    cout << " ]\n";
}

int partition(int arr[], int low, int high, int n, int depth)
{
    int pivot = arr[high];
    int i = low - 1;

    logLine(depth, "PART [" + to_string(low) + ".." + to_string(high) + "] pivot=" + to_string(pivot) + "@" + to_string(high));
    logArray(depth, arr, n);

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
            if (DEBUG_LEVEL >= 2)
            {
                logLine(depth, "swap(" + to_string(i) + ", " + to_string(j) + ")");
                logArray(depth, arr, n);
            }
        }
    }

    swap(arr[i + 1], arr[high]);

    logLine(depth, "pivot swap(" + to_string(i + 1) + ", " + to_string(high) + ")");
    logArray(depth, arr, n);
    logLine(depth, "pi = " + to_string(i + 1));
    return i + 1;
}

void quicksort(int arr[], int low, int high, int n, int depth)
{
    logLine(depth, "QS [" + to_string(low) + ".." + to_string(high) + "]");

    if (low < high)
    {
        int pi = partition(arr, low, high, n, depth + 1);

        quicksort(arr, low, pi - 1, n, depth + 1);
        quicksort(arr, pi + 1, high, n, depth + 1);
    }
    else
    {
        logLine(depth, "return (base case)");
    }
}
int main()
{
    int elements = 7;
    int arr[] = {10, 7, 8, 9, 1, 5, 3};
    cout << "Initial array:\n";
    logArray(0, arr, elements);

    quicksort(arr, 0, elements - 1, elements, 0);
    cout << "Sorted array: ";
    for (int i = 0; i < elements; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}