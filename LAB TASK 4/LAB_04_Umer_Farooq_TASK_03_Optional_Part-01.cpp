#include <iostream>
using namespace std;

// Function to perform rotated binary search on a rotated sorted array
int rotatedBinarySearch(int arr[], int size, int target) {
    int low = 0;                 // Initialize low pointer
    int high = size - 1;         // Initialize high pointer

    while (low <= high) {
        int mid = low + (high - low) / 2;  // Calculate mid to avoid overflow

        // If target is found at the middle
        if (arr[mid] == target) {
            return mid;
        }

        // Check if the left half is sorted
        if (arr[low] <= arr[mid]) {
            // Target lies in the left half
            if (arr[low] <= target && target < arr[mid]) {
                high = mid - 1;
            }
            // Target lies in the right half
            else {
                low = mid + 1;
            }
        }
        // Else, the right half must be sorted
        else {
            // Target lies in the right half
            if (arr[mid] < target && target <= arr[high]) {
                low = mid + 1;
            }
            // Target lies in the left half
            else {
                high = mid - 1;
            }
        }
    }
    // If the element is not found
    return -1;
}

int main() {
    cout << "**DSA LAB 04**" << endl;
    cout << "**Rotated binary search**" << endl;
    // Ask the user for the size of the array
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    // Dynamically allocate memory for the array
    int* arr = new int[size];

    // Prompt the user to input the elements of the rotated sorted array
    cout << "Enter the elements of the rotated sorted array: " << endl;
    for (int i = 0; i < size; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    // Ask the user for the target to search
    int target;
    cout << "Enter the target to search: ";
    cin >> target;

    // Call the rotated binary search function
    int result = rotatedBinarySearch(arr, size, target);

    // Display the result
    if (result != -1) {
        cout << "Element " << target << " found at index: " << result << endl;
    }
    else {
        cout << "Element " << target << " not found" << endl;
    }

    // Free the dynamically allocated memory
    delete[] arr;

    return 0;
}
