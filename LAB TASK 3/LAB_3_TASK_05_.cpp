#include <iostream>
using namespace std;
int main()
{
    int const size = 6;
    int array[size];
    for (int i = 0; i < size; i++)
    {
        int value;
        cout << "Enter the Value " << i + 1 << " :";
        cin >> value;
        array[i] = value;
    }
    bool check = true;
    for (int i = 0; i < size / 2; i++)
    {
        if (array[i] != array[size - 1 - i])
        {
            check = false;
            break;
        }
        else
        {
            check = true;
        }
    }
    if (check)
    {
        cout << "Yes it is Palidrome";
    }
    else
        cout << "No its not Palidrome";

    system("pause");
}
