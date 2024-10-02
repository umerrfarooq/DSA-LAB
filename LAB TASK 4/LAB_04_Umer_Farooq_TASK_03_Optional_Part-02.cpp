#include <iostream>
using namespace std;

// Recursive function to perform binary search
int recursiveBinarySearch(int arr[], int low, int high, int target) {
    if (low > high) {
        return -1;  // Base case: element not found
    }

    int mid = low + (high - low) / 2;  // Calculate mid to avoid overflow

    // If target is found at the middle
    if (arr[mid] == target) {
        return mid;
    }

    // If target is smaller, search in the left half
    if (arr[mid] > target) {
        return recursiveBinarySearch(arr, low, mid - 1, target);
    }

    // If target is larger, search in the right half
    return recursiveBinarySearch(arr, mid + 1, high, target);
}

int main() {
    cout << "**DSA LAB 04**" << endl;
    cout << "**Recursive binary search**" << endl;
    // Ask the user to input the size of the array
    int size;
    cout << "Enter the size of array: ";
    cin >> size;

    // Dynamically allocate memory for the array
    int* arr = new int[size];

    // Prompt the user to input the elements of the array
    for (int i = 0; i < size; i++) {
        cout << "Enter the array element at index " << i << ": ";
        cin >> arr[i];
    }

    // Ask the user for the target value to search for
    int target;
    cout << "Enter the value to be searched: ";
    cin >> target;

    // Call the recursive binary search function
    int result = recursiveBinarySearch(arr, 0, size - 1, target);

    // If the target is found, display its index
    if (result != -1) {
        cout << "Element " << target << " found at index: " << result << endl;
    }
    // If the target is not found, display a message
    else {
        cout << "Element " << target << " not found" << endl;
    }

    // Free the dynamically allocated memory
    delete[] arr;

    return 0;
}
