#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib> 
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(const vector<int> &arr)
{
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
}

// Insertion Sort function
void insertionSort(vector<int> &arr, int low, int high)
{
    for (int i = low + 1; i <= high; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= low && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Partition function for Quick Sort
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;

    for (int j = low + 1; j <= high; j++)
    {
        if (arr[j] < pivot)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[low], arr[i - 1]);
    return i - 1;
}

// Quick Sort function with Insertion Sort fallback for small subarrays
void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        // Use Insertion Sort for small subarrays
        if (high - low < 10)
        {
            insertionSort(arr, low, high);
        }
        else
        {
            int pivotIndex = partition(arr, low, high);
            quickSort(arr, low, pivotIndex - 1);
            quickSort(arr, pivotIndex + 1, high);
        }
    }
}

int main()
{
    srand(time(0)); // Seed for random number generation

    vector<int> array1 = {56, 45, 76, 34, 678, 3, 6, 576, 78, 34, 76};

    // Sorting and timing array1
    cout << "Original Array: ";
    printArray(array1);

    clock_t start1 = clock();
    quickSort(array1, 0, array1.size() - 1);
    clock_t end1 = clock();
    cout << "Sorted Array: ";
    printArray(array1);
    double time_taken1 = double(end1 - start1) / CLOCKS_PER_SEC;
    cout << "Time Taken by Hybrid Quick Sort: " << time_taken1 << " seconds" << endl;

    system("pause");
    return 0;
}