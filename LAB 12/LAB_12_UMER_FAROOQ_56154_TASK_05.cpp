#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

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

void printArray(const vector<int> &arr)
{
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> array1 = {38, 27, 43, 3, 9, 82, 10};
    vector<int> array2 = {3, 4, 45, 2, 54, 23, 657, 23, 3, 5, 2, 436, 23, 56};
    vector<int> array3 = {99, 53, 45, 467, 234, 34, 25, 24, 43, 23, 51, 99, 53, 45, 467, 234, 34, 25, 24, 43, 23, 51};
    
    cout << "Original Array: ";
    printArray(array1);

    clock_t start1 = clock();
    mergeSort(array1, 0, array1.size() - 1);
    clock_t end1 = clock();
    cout << "Sorted Array: ";
    printArray(array1);
    double time_taken = double(end1 - start1) / CLOCKS_PER_SEC;
    cout << "Time Taken by Merge Sort: " << time_taken << " seconds" << endl;


    cout << "Original Array: ";
    printArray(array2);
    clock_t start2 = clock();
    mergeSort(array2, 0, array2.size() - 1);
    clock_t end2 = clock();

    cout << "Sorted Array: ";
    printArray(array2);
    double time_taken2 = double(end2 - start2) / CLOCKS_PER_SEC;
    cout << "Time Taken by Merge Sort: " << time_taken2 << " seconds" << endl;


    cout << "Original Array: ";
    printArray(array3);

    clock_t start3 = clock();
    mergeSort(array3, 0, array3.size() - 1);
    clock_t end3 = clock();
    cout << "Sorted Array: ";
    printArray(array3);
    double time_taken3 = double(end3 - start3) / CLOCKS_PER_SEC;
    cout << "Time Taken by Merge Sort: " << time_taken3 << " seconds" << endl;

    system("pause");
    return 0;
}