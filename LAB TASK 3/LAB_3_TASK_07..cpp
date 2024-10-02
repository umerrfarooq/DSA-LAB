#include <iostream>
using namespace std;
int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int* arr = new int[size];
    cout << "Enter" << size << " elements: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    int key;
    cout << "Enter the value to search for: ";
    cin >> key;

    bool found = false;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            cout << "Value found at index: " << i << endl;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Value not found in the array." << endl;
    }
    delete[] arr;
}