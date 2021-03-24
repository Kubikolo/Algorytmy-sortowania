#include <iostream>

using namespace std;

void zamiana(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (arr[j-1] > arr[j])
            {
                swap(arr[j-1], arr[j]);
            }
        }
    }
}

void printArray(int arr[], int n)
{
    for (int i=0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {64, 25, 12, 22, 11, 15};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);

    printArray(arr, n);

    return 0;
}
