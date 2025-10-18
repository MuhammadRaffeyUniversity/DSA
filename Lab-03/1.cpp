#include <iostream>  // Muhammad Raffey
#include <vector>    // 70153209
using namespace std; // DSA 4G
int main()
{
    int marks[5];
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter the Marks of Student " << i + 1 << ": ";
        cin >> marks[i];
    }
    cout << endl;
    int adStu;
    cout << "Enter Num of Additional Students: ";
    cin >> adStu;
    vector<int> allMarks(adStu);

    for (int i = 0; i < adStu; i++)
    {
        cout << "Enter the Marks of Additional Student " << i + 1 << ": ";
        cin >> allMarks[i];
    }
    for (int i = 0; i < 5; i++)
    {
        allMarks.insert(allMarks.begin() + i, marks[i]);
    }

    cout << "All Students Marks: ";

    for (int i = 0; i < allMarks.size(); i++)
    {
        cout << allMarks[i] << " ";
    }
    int total;
    for (int i = 0; i < allMarks.size(); i++)
    {
        total += allMarks[i];
    }
    cout << endl;
    float avg = total / allMarks.size();
    cout << "Average is:" << avg << endl;

    return 0;
}