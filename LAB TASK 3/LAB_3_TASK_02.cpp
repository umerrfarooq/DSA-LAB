#include <iostream>
using namespace std;

int main()
{
    int numbers[10] = { 1, 23, 3, 4, 53, 6, 78, 9, 10 };
    int searchValue;
    cout << "Enter search Value: " << endl;
    cin >> searchValue;
    bool found = true;
    int i;
    for (i = 0; i < 10; i++)
    {
        if (numbers[i] == searchValue)

        {
            found = true;
            break;
        }
        else
        {
            found = false;
        }
    }
    if (found)
    {
        cout << "Search Found: " << i << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }

    system("pasue");
}