#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cmpfunc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void LinearSearch()
{
    int i, n = 10, srh, count = 0;
    int arr[n];
    time_t t;

    srand((unsigned)time(&t));

    for (i = 0; i < n; i++)
        arr[i] = rand() % 100;

    printf("\nEnter number to Search : ");
    scanf("%d", &srh);

    for (i = 0; i < n; i++)
    {
        if (arr[i] == srh)
            count++;
    }

    printf("Array : ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    if (count > 0)
        printf("\nItem Found");
    else
        printf("\nItem not Found");
}

void BinarySearch()
{
    int i, n = 10, count = 0;
    int arr[n];
    time_t t;

    srand((unsigned)time(&t));

    for (i = 0; i < n; i++)
        arr[i] = rand() % 100;

    qsort(arr, 10, sizeof(int), cmpfunc);

    int low = 0, high = n - 1, srh;

    printf("\nEnter number to Search : ");
    scanf("%d", &srh);

    for (i = 0; i < n; i++)
    {
        int mid = (low + high) / 2;
        if (srh == arr[mid])
            count++;
        else if (srh > arr[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }

    printf("Array : ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    if (count > 0)
        printf("\nItem Found");
    else
        printf("\nItem not Found");
}

int binarySerach(int arr[], int srh, int low, int high)
{
    if (high >= low)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == srh)
            return mid;

        if (arr[mid] > srh)
            return binarySerach(arr, srh, low, mid - 1);

        return binarySerach(arr, srh, mid + 1, high);
    }
    return -1;
}

void main()
{
    int choice;
    int i;
    int n = 10;
    int srh;
    int array[n];
    time_t t;
    while (1)
    {
        printf("\n");
        printf("\n************************************************");
        printf("\n1. Perform Linear Search.");
        printf("\n2. Perform Binary Search using Iterative method.");
        printf("\n3. Perform Binary Search using Recursive method.");
        printf("\n************************************************");
        printf("\n");
        printf("\n4. EXIT.");

        printf("\nEnter your Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            LinearSearch();
            break;

        case 2:
            BinarySearch();
            break;

        case 3:
            srand((unsigned)time(&t));

            for (i = 0; i < n; i++)
                array[i] = rand() % (100 - 1 + 1) + 1;

            printf("\nEnter number to search : ");
            scanf("%d", &srh);

            int result = binarySerach(array, srh, 0, n - 1);

            printf("Array : ");
            for (size_t i = 0; i < n; i++)
                printf("%d ", array[i]);

            if (result == -1)
                printf("\nItem not Found.");
            else
                printf("\nItem Found at index %d", result);
            break;

        case 4:
            printf("You Opted to Exit...");
            exit(0);

        default:
            printf("Invalid choice, Try Again.");
            break;
        }
    }
}