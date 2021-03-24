#include <iostream>

using namespace std;

void printArray(int arr[], int n)
{
    for (int i=0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void zamiana(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void shiftDown(int arr[], int n, int i)
{
    int l = 2*i+1;
    int r = 2*i+2;

    if (l > n - 1 && r > n - 1)
    {
        return;
    }
    if (r > n - 1)
    {
        r = i;
    }

    if (arr[l] > arr[r] && arr[i] < arr[l])
    {
        zamiana(&arr[i], &arr[l]);
        shiftDown(arr, n, l);
    }
    else if (arr[l] < arr[r] && arr[i] < arr[r])
    {
        zamiana(&arr[i], &arr[r]);
        shiftDown(arr, n, r);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        shiftDown(arr, n, i);
    }
    int rozmiar = n;
    for (int j = 0; j < n; j++)
    {
        zamiana(&arr[0], &arr[rozmiar-1]);
        rozmiar--;
        shiftDown(arr, rozmiar, 0);
    }
}

int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    printArray(arr, n);
}
