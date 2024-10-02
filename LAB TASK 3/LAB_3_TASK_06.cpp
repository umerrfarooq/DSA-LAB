
#include <iostream>
using namespace std;
int main()
{
    int size;
    cout << "Enter the size of the array (1-20): ";
    cin >> size;
    if (size < 1 || size > 20)
    {
        cout << "Invalid size!" << endl;
        return 1;
    }
    int arr[20]; // Use a fixed-size array with the maximum size 20
    cout << "Enter" << size << " integer values (0-12): ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
        if (arr[i] < 0 || arr[i] > 12)
        {
            cout << "Invalid value!" << endl;
            return 1;
        }
    }
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    double average = sum / size;
    cout << "Average: " << average << endl;
    cout << "Factorials:" << endl;
    for (int i = 0; i < size; i++)
    {
        int num = arr[i];
        int factorial = 1;
        for (int j = 1; j <= num; j++)
        {

            factorial *= j;
        }

        cout << "Factorial of " << arr[i] << " is " << factorial << endl;
    }
}