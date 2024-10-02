
#include <iostream>
using namespace std;
int main()
{
    int matrix[3][3];
    cout << "Enter 9 values for the 3x3 matrix:" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> matrix[i][j];
        }
    }

    cout << "Before Transposed Matrix:" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Transposed Matrix: " << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << matrix[j][i] << " ";
        }
        cout << endl;
    }
    system("pasue");
}
