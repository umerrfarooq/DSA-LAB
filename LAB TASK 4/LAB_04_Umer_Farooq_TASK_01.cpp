#include<iostream>
#include<string>
using namespace std;

//Function to perform a linear search on the array
//Returns the index of the target if found, otherwise returns -1
int linearSearch(int arr[], int size, int target)
{
    //Loop through the array
    for (int i = 0; i < size; i++)
    {
        //If the target is found at index i, return the index
        if (arr[i] == target)
        {
            return i;
        }
    }
    //If the target is not found, return -1
    return -1;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               

int main()
{
    //Display a heading for the program
    cout << "**DSA LAB 04**" << endl;
    cout << "**LINEAR SEARCH**" << endl;
    //Initialize size and create a dynamic array of integers
    int size = 0;
    int* arr = new int[size];  // Memory allocation before size is entered is incorrect (should be allocated after input)

    //Ask the user for the size of the array
    cout << "Enter the size of array: ";
    cin >> size;

    //Populate the array with values entered by the user
    for (int i = 0; i < size; i++)
    {
        cout << endl << "Enter the array at index: " << i << " ";
        cin >> arr[i];
    }

    //Ask the user for the target value to search
    int target;
    cout << "Enter the value to be search: ";
    cin >> target;

    //Call the linear search function to find the target in the array
    int result = linearSearch(arr, size, target);

    //If the target is found, display the index
    if (result != -1)
    {
        cout << "Element: " << target << " found at index: " << result << endl;
    }
    else
    {
        //If the target is not found, display a message
        cout << "Element " << target << " not found in the array" << endl;
    }

    //Pause the system (for Windows systems)
    system("pause");

    delete[] arr;

    return 0;
}




