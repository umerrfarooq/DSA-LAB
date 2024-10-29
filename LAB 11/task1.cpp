#include<iostream>
using namespace std;
void insertionSort(int arr[],int size){
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i -1;

        while (j >= 0 && arr[j] > key)
        {	arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;

    }
    
}
void PrintArray(int arr[], int size){
for (int i = 0; i < size; i++)
{
    cout<< arr[i] << " ";
}
cout<< endl;
}
int main()
{

    int arr[] = {12, 11, 5 ,6,4,77,44};
    int size = sizeof(arr) / sizeof(arr[0]); 


    cout<<"origal Array : " ;
    PrintArray(arr,size);

    insertionSort(arr,size);

    cout<<"Sorted array : ";
    PrintArray(arr,size);
    system("pause");
    return 0;
}


