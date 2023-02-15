#include <stdio.h>
#include <stdlib.h>

void insertionSort()
{
    int arr[] = {9, 6, 5, 0, 8, 2, 7, 1, 3, 4};
    int i, j, k, key;

    printf("\n\nUnSorted Array : ");
    for (i = 0; i < 10; i++)
        printf("%d ", arr[i]);

    for (i = 1; i < 10; i++)
    {
        printf("\n\n%d Iteration", i);
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;

        printf("\n");
        for (k = 0; k < 10; k++)
            printf("%d ", arr[k]);
    }

    printf("\n\nSorted Array : ");
    for (i = 0; i < 10; i++)
        printf("%d ", arr[i]);
}

void selectionSort()
{
    int arr[] = {9, 6, 5, 0, 8, 2, 7, 1, 3, 4};
    int i, j, k, min_ixd, min, temp;

    printf("\n\nUnSorted Array : ");
    for (i = 0; i < 10; i++)
        printf("%d ", arr[i]);

    for (i = 0; i < 10 - 1; i++)
    {
        min = arr[i];
        min_ixd = i;
        printf("\n\n%d Iteration", i + 1);
        for (j = i + 1; j < 10; j++)
        {
            if (arr[j] < min)
            {
                min_ixd = j;
                min = arr[j];
            }
        }
        arr[min_ixd] = arr[i];
        arr[i] = min;

        printf("\n");
        for (k = 0; k < 10; k++)
            printf("%d ", arr[k]);
    }

    printf("\n\nSorted Array : ");
    for (i = 0; i < 10; i++)
        printf("%d ", arr[i]);
}

void bubbleSort()
{
    int arr[] = {9, 6, 5, 0, 8, 2, 7, 1, 3, 4};
    int i, j, k, temp;

    printf("\n\nUnSorted Array : ");
    for (i = 0; i < 10; i++)
        printf("%d ", arr[i]);

    for (i = 0; i < 10 - 1; i++)
    {
        printf("\n\n%d Iteration", i + 1);
        for (j = 0; j < 10 - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            printf("\n");
            for (k = 0; k < 10; k++)
                printf("%d ", arr[k]);
        }
    }
    printf("\n\nSorted Array : ");
    for (i = 0; i < 10; i++)
        printf("%d ", arr[i]);
}

void main()
{
    int choice;
    while (1)
    {
        printf("\n");
        printf("\n************************************************");
        printf("\n1. Perform Bubble Sort.");
        printf("\n2. Perform Selection Sort.");
        printf("\n3. Perform Insertion Sort");
        printf("\n4. EXIT.");
        printf("\n************************************************");
        printf("\n");

        printf("\nEnter your Choice : ");
        scanf("%d", choice);

        switch (choice)
        {
        case 1:
            printf("\n**********Bubble Sorting**********");
            bubbleSort();
            break;

        case 2:
            printf("\n**********Selection Sort**********");
            selectionSort();
            break;

        case 3:
            printf("\n**********Insertion Sorting**********");
            insertionSort();
            break;

        case 4:
            printf("\nYou opted to exit.");
            exit(0);
            break;

        default:
            printf("\nInvalid Choice, Try again.");
            break;
        }
    }
}