#include <iostream>
using namespace std;

// Function to perform Binary Search on a sorted array
// Returns the index of the target if found, otherwise returns -1
int binarySearch(int arr[], int size, int target)
{
    int low = 0;                // Initialize the low pointer to the start of the array
    int high = size - 1;         // Initialize the high pointer to the end of the array

    // Continue the loop while the low pointer is less than or equal to the high pointer
    while (low <= high)
    {
        // Calculate the middle index to avoid overflow
        int mid = low + (high - low) / 2;

        // If the middle element is the target, return the index
        if (arr[mid] == target)
        {
            return mid;
        }
        // If the target is smaller than the middle element, focus on the left half
        if (arr[mid] > target)
        {
            high = mid - 1;
        }
        // If the target is larger than the middle element, focus on the right half
        else
        {
            low = mid + 1;
        }
    }
    // If the target is not found, return -1
    return -1;
}

int main()
{       
    cout << "**DSA LAB 04**" << endl;
    cout << "**Binary SEARCH**" << endl;
    // Ask the user to input the size of the array
    int size;
    cout << "Enter the size of array: ";
    cin >> size;

    // Dynamically allocate memory for the array
    int* arr = new int[size];

    // Prompt the user to input the elements of the array
    for (int i = 0; i < size; i++)
    {
        cout << endl << "Enter the array element at index " << i << " ";
        cin >> arr[i];
    }

    // Ask the user for the target value to search for
    int target;
    cout << "Enter the value to be Search: ";
    cin >> target;

    // Call the binarySearch function to find the target in the array
    int result = binarySearch(arr, size, target);

    // If the target is found, display its index
    if (result != -1)
    {
        cout << "Element " << target << " Found on Index: " << result << endl;
    }
    // If the target is not found, display a message
    else
    {
        cout << "Element: " << target << " not Found" << endl;
    }

    // Pause the system (for Windows systems)
    system("pause");

    // Free the dynamically allocated memory
    delete[] arr;

    return 0;
}
