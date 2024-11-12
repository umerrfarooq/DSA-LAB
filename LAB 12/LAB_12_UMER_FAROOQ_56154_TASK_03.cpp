#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib> // For rand()
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

vector<int> generateRandomArray(int size) {
    vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000 + 1; 
    }
    return arr;
}

int main()
{
    srand(time(0)); // Seed for random number generation

    vector<int> array1 = generateRandomArray(100);
    vector<int> array2 = generateRandomArray(1000);
    vector<int> array3 = generateRandomArray(10000);
    
    // Sorting and timing array1
    cout << "Original Array of size 100: ";
    printArray(array1);

    clock_t start1 = clock();
    quickSort(array1, 0, array1.size() - 1);
    clock_t end1 = clock();
    cout << "Sorted Array of size 100: ";
    printArray(array1);
    double time_taken1 = double(end1 - start1) / CLOCKS_PER_SEC;
    cout << "Time Taken by Quick Sort on size 100: " << time_taken1 << " seconds" << endl;

    // Sorting and timing array2
    cout << "\nOriginal Array of size 1000: ";
    printArray(array2);

    clock_t start2 = clock();
    quickSort(array2, 0, array2.size() - 1);
    clock_t end2 = clock();
    cout << "Sorted Array of size 1000: ";
    printArray(array2);
    double time_taken2 = double(end2 - start2) / CLOCKS_PER_SEC;
    cout << "Time Taken by Quick Sort on size 1000: " << time_taken2 << " seconds" << endl;

    // Sorting and timing array3
    cout << "\nOriginal Array of size 10000: ";
    printArray(array3);

    clock_t start3 = clock();
    quickSort(array3, 0, array3.size() - 1);
    clock_t end3 = clock();
    cout << "Sorted Array of size 10000: ";
    printArray(array3);
    double time_taken3 = double(end3 - start3) / CLOCKS_PER_SEC;
    cout << "Time Taken by Quick Sort on size 10000: " << time_taken3 << " seconds" << endl;

    system("pause");
    return 0;
}