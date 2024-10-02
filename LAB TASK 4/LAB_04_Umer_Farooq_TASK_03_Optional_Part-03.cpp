#include <iostream>
#include <string>
using namespace std;

// Function to perform linear search on an unsorted array of names
int linearSearch(string arr[], int size, string target) {
    // Loop through the array to search for the target name
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;  // Return the index if the target is found
        }
    }
    return -1;  // Return -1 if the target is not found
}

// Function to perform binary search on a sorted array of names
int binarySearch(string arr[], int low, int high, string target) {
    if (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid;  // Return the index if the target is found
        }
        if (arr[mid] > target) {
            return binarySearch(arr, low, mid - 1, target);  // Search the left half
        }
        return binarySearch(arr, mid + 1, high, target);  // Search the right half
    }
    return -1;  // Return -1 if the target is not found
}

int main() {
    cout << "**DSA LAB 04**" << endl;
    cout << "**PHONE BOOK **" << endl;
    int size = 6; // Fixed size of arrays
    string unsortedPhoneBook[] = { "umer", "haseeb", "waleed", "hunain", "shahzaib", "haris" }; // Unsorted names
    string sortedPhoneBook[] = { "ali", "babar","daud", "ehtesham", "jamal" };   // Sorted names for binary search

    int searchType;
    cout << "Phone Book Application\n";
    cout << "1. Linear Search\n";
    cout << "2. Binary Search\n";
    cout << "Select search type (1 for Linear, 2 for Binary): ";
    cin >> searchType;

    string target;
    cout << "Enter the name to search: ";
    cin >> target;

    // Linear search on unsorted phone book
    if (searchType == 1) {
        int linearResult = linearSearch(unsortedPhoneBook, size, target);
        if (linearResult != -1) {
            cout << "Name " << target << " found at index (linear search): " << linearResult << " in unsorted phone book." << endl;
        }
        else {
            cout << "Name " << target << " not found in phone book (linear search)." << endl;
        }
    }
    // Binary search on sorted phone book
    else if (searchType == 2) {
        int binaryResult = binarySearch(sortedPhoneBook, 0, size - 1, target);
        if (binaryResult != -1) {
            cout << "Name " << target << " found at index (binary search): " << binaryResult << " in sorted phone book." << endl;
        }
        else {
            cout << "Name " << target << " not found in phone book (binary search)." << endl;
        }
    }
    else {
        cout << "Invalid selection. Please select 1 for Linear Search or 2 for Binary Search." << endl;
    }

    return 0;
}
