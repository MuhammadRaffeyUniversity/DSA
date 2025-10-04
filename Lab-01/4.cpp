#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> marks = {95, 20, 100, 39, 48, 57};
    cout << marks.back() << endl;
    cout << marks.front() << endl;
    cout << marks.size() << endl;
    marks.pop_back();
    cout << marks.size() << endl;
    marks.push_back(77);
    marks.insert(marks.begin() + 2, 99);
    marks.erase(marks.begin() + 3);
    cout << marks.size() << endl;
    cout << "\n\nElements are: ";
    for (int i = 0; i < marks.size(); i++)
    {
        cout << marks[i] << " ";
    }

    cout << endl;
    return 0;
}