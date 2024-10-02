#include <iostream>

using namespace std;
int main()
{
    int array1[5] = { 13, 6, 8, 22, 1 };
    int index;
    int numbers1;
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter the index of an array between 0 to 4: ";
        cin >> index;
        if (index >= 0 && index <= 4)
        {

            cout << "insert any number: ";
            cin >> numbers1;
            array1[index] = numbers1;
            cout << "updated value of array" << endl;
            break;
        }
        else
        {
            cout << "Enter correct index" << endl;
            break;
        }
    }
    system("pause");
}