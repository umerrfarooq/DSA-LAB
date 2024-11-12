#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

// Quick Sort functions
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low]; // Pivot is now the first element
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

void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

// Merge Sort functions
void merge(vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> leftArr(n1);
    vector<int> rightArr(n2);

    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Print Array
void printArray(const vector<int> &arr)
{
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
}

// Main function
int main()
{
    // Sample arrays for testing
    vector<int> array1 = {38, 27, 43, 3, 9, 82, 10};
    vector<int> array2 = {3, 4, 45, 2, 54, 23, 657, 23, 3, 5, 2, 436, 23, 56};
    vector<int> array3 = {99, 53, 45, 467, 234, 34, 25, 24, 43, 23, 51, 99, 53, 45, 467, 234, 34, 25, 24, 43, 23, 51};

    // Measure time for Merge Sort on array1
    cout << "Original Array 1: ";
    printArray(array1);
    clock_t start1 = clock();
    mergeSort(array1, 0, array1.size() - 1);
    clock_t end1 = clock();
    cout << "Sorted Array 1 (Merge Sort): ";
    printArray(array1);
    double time_taken_merge1 = double(end1 - start1) / CLOCKS_PER_SEC;
    cout << "Time Taken by Merge Sort: " << time_taken_merge1 << " seconds" << endl;

    // Measure time for Quick Sort on array1
    cout << "Original Array 1: ";
    printArray(array1);
    clock_t startQuick1 = clock();
    quickSort(array1, 0, array1.size() - 1);
    clock_t endQuick1 = clock();
    cout << "Sorted Array 1 (Quick Sort): ";
    printArray(array1);
    double time_taken_quick1 = double(endQuick1 - startQuick1) / CLOCKS_PER_SEC;
    cout << "Time Taken by Quick Sort: " << time_taken_quick1 << " seconds" << endl;

    // Measure time for Merge Sort on array2
    cout << "Original Array 2: ";
    printArray(array2);
    clock_t start2 = clock();
    mergeSort(array2, 0, array2.size() - 1);
    clock_t end2 = clock();
    cout << "Sorted Array 2 (Merge Sort): ";
    printArray(array2);
    double time_taken_merge2 = double(end2 - start2) / CLOCKS_PER_SEC;
    cout << "Time Taken by Merge Sort: " << time_taken_merge2 << " seconds" << endl;

    // Measure time for Quick Sort on array2
    cout << "Original Array 2: ";
    printArray(array2);
    clock_t startQuick2 = clock();
    quickSort(array2, 0, array2.size() - 1);
    clock_t endQuick2 = clock();
    cout << "Sorted Array 2 (Quick Sort): ";
    printArray(array2);
    double time_taken_quick2 = double(endQuick2 - startQuick2) / CLOCKS_PER_SEC;
    cout << "Time Taken by Quick Sort: " << time_taken_quick2 << " seconds" << endl;

    // Measure time for Merge Sort on array3
    cout << "Original Array 3: ";
    printArray(array3);
    clock_t start3 = clock();
    mergeSort(array3, 0, array3.size() - 1);
    clock_t end3 = clock();
    cout << "Sorted Array 3 (Merge Sort): ";
    printArray(array3);
    double time_taken_merge3 = double(end3 - start3) / CLOCKS_PER_SEC;
    cout << "Time Taken by Merge Sort: " << time_taken_merge3 << " seconds" << endl;

    // Measure time for Quick Sort on array3
    cout << "Original Array 3: ";
    printArray(array3);
    clock_t startQuick3 = clock();
    quickSort(array3, 0, array3.size() - 1);
    clock_t endQuick3 = clock();
    cout << "Sorted Array 3 (Quick Sort): ";
    printArray(array3);
    double time_taken_quick3 = double(endQuick3 - startQuick3) / CLOCKS_PER_SEC;
    cout << "Time Taken by Quick Sort: " << time_taken_quick3 << " seconds" << endl;

    system("pause");
    return 0;
}