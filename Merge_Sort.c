#include <stdio.h>
#include <stdlib.h>

int *arr;

void print_Array(int start, int n)
{
    int i;
    printf("[");
    for (i = start; i <= n; i++)
    {
        if (i == n)
            printf("%d", arr[i]);
        else
            printf("%d,", arr[i]);
    }
    printf("] ");
}

int random_Array_Generator()
{
    int i, n;
    free(arr);

    printf("\n\n\nEnter the number of values: ");
    scanf("%d", &n);

    arr = (int *)calloc(n, sizeof(int));

    for (i = 0; i < n; i++)
        arr[i] = rand() % 50 + 1;

    printf("Generated list of numbers were: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n\n");

    return n;
}

void merge(int l, int mid, int h)
{
    int lsize = mid - l + 1;
    int rsize = h - mid;
    int L[lsize], R[rsize];
    int i, j, k;

    for (i = 0; i < lsize; i++)
        L[i] = arr[l + i];
    for (j = 0; j < rsize; j++)
        R[j] = arr[mid + 1 + j];

    i = 0, j = 0, k = l;

    while (i < lsize && j < rsize)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k = k + 1;
    }

    while (i < lsize)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < rsize)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int l, int h, int choice)
{
    if (l < h)
    {
        int mid = (l + h) / 2;
        if (choice == 1)
        {
            printf("Division step : ");
            print_Array(l, mid);
            print_Array(mid + 1, h);
            printf("\n");
        }
        mergeSort(l, mid, choice);
        mergeSort(mid + 1, h, choice);
        merge(l, mid, h);
    }
}

void display()
{
    printf("\n\nEnter 1 to show the divisions.");
    printf("\nEnter 2 to show the sorted array.");
    printf("\nEnter 3 to Exit.");
}

int main()
{
    int choice, *arr, size;
    printf("\n----------------------------------------");
    printf("\nName : SARTHAK MATHUR\tRoll : 2247262");
    printf("\n----------------------------------------");
    do
    {
        display();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            size = random_Array_Generator();
            mergeSort(0, size - 1, 1);
            printf("\n\nSorted Array: ");
            print_Array(0, size - 1);
            break;

        case 2:
            size = random_Array_Generator();
            mergeSort(0, size - 1, 0);
            printf("\n\nSorted Array: ");
            print_Array(0, size - 1);
            break;

        case 3:
            printf("\n\nYou opted to exit!!");
            break;

        default:
            printf("\n\nWrong choice selected. Please try again!!");
            break;
        }
    } while (choice != 3);
}
