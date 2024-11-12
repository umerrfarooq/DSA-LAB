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

// Partition function with specific (first element) pivot
int partitionSpecificPivot(vector<int> &arr, int low, int high)
{
    int pivot = arr[low]; // Specific pivot (first element)
    int i = low + 1;

    for (int j = low + 1; j <= high; j++)
    {
        if (arr[j] < pivot)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[low], &arr[i - 1]);
    return i - 1;
}

// Partition function with random pivot

int partitionRandomPivot(vector<int> &arr, int low, int high)
{
    int randomPivotIndex = low + rand() % (high - low + 1);
    swap(&arr[low], &arr[randomPivotIndex]); // Move random pivot to start

    int pivot = arr[low]; // Now the pivot is the first element
    int i = low + 1;

    for (int j = low + 1; j <= high; j++)
    {
        if (arr[j] < pivot)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[low], &arr[i - 1]);
    return i - 1;
}

// QuickSort with specific pivot
void quickSortSpecificPivot(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partitionSpecificPivot(arr, low, high);
        quickSortSpecificPivot(arr, low, pivotIndex - 1);
        quickSortSpecificPivot(arr, pivotIndex + 1, high);
    }
}

// QuickSort with random pivot
void quickSortRandomPivot(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partitionRandomPivot(arr, low, high);
        quickSortRandomPivot(arr, low, pivotIndex - 1);
        quickSortRandomPivot(arr, pivotIndex + 1, high);
    }
}

int main()
{
    srand(time(0));

    vector<int> array1 = {33, 12, 52, 3, 75, 29, 41, 6, 19};
    vector<int> array2 = array1; // Duplicate array

    cout << "Original Array: ";
    printArray(array1);

    // QuickSort with specific pivot
    clock_t start = clock();
    quickSortSpecificPivot(array1, 0, array1.size() - 1);
    clock_t end = clock();
    double timeSpecificPivot = double(end - start) / CLOCKS_PER_SEC;

    cout << "Sorted Array with Specific Pivot: ";
    printArray(array1);
    cout << "Time Taken by Quick Sort with Specific Pivot: " << timeSpecificPivot << " seconds" << endl;

    // QuickSort with random pivot
    start = clock();
    quickSortRandomPivot(array2, 0, array2.size() - 1);
    end = clock();
    double timeRandomPivot = double(end - start) / CLOCKS_PER_SEC;

    cout << "Sorted Array with Random Pivot: ";
    printArray(array2);
    cout << "Time Taken by Quick Sort with Random Pivot: " << timeRandomPivot << " seconds" << endl;

    system("pause");
    return 0;
}