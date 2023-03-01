#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

void print_Array(int arr[], int start, int n)
{
    int i;
    if(start>n) return;
    printf("[");
    for (i = start; i <= n; i++)
    {
        if (i == n)
            printf("%d", arr[i]);
        else
            printf("%d, ", arr[i]);
    }
    printf("] ");
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int low, int high, int n)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, high);
    return (i + 1);
}

void quickSort(int arr[], int low, int high, int n)
{
    if (low < high)
    {
        int pi = partition(arr, low, high, n);

        print_Array(arr, 0, pi); 
        print_Array(arr, pi + 1, high);
        printf("\n");

        quickSort(arr, low, pi - 1, n);
        quickSort(arr, pi + 1, high, n);
    }
}

void main()
{
    int n = 10;
    int i;
    int arr[n];
    time_t t;

    srand((unsigned)time(&t));

    for (i = 0; i < n; i++)
        arr[i] = rand() % 100;

    printf("\nUnsorted Array : ");
    display(arr, n);

    quickSort(arr, 0, n - 1, n);

    printf("\nSorted Array : ");
    display(arr, n);
}