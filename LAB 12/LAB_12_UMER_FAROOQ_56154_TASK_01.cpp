#include <iostream>
#include <vector>
#include <ctime>
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

int main()
{
    vector<int> array = {33, 12, 52, 3, 75, 29, 41, 6, 19};
    int n = array.size();
    cout << "Original Array: ";
    printArray(array);

    clock_t start = clock();

    quickSort(array, 0, n - 1);
    clock_t end = clock();

    cout << "Sorted Array: ";
    printArray(array);

    double time_taken = double(end - start) / CLOCKS_PER_SEC;
    cout << "Time Taken by Quick Sort: " << time_taken << " seconds" << endl;

    system("pause");
    return 0;
}