
#include <iostream>
using namespace std;
int main()
{
    int array[5] = { 1, 2, 3, 4, 5 };
    int index;
    cout << "Array Values: ";
    for (int i = 0; i < 5; i++)
    {
        cout << " " << array[i];
    }
    cout << endl
        << "Enter the index that you want to remove (0 to 4): ";
    cin >> index;
    if (index >= 0 && index < 5)
    {
        for (int i = index; i < 4; i++)
        {
            array[i] = array[i + 1];
        }
        for (int i = 0; i < 4; i++)
        {
            cout << "  " << array[i];
        }
    }
    else
    {
        cout << "Wrong Index" << endl;
    }
    system("pasue");
}