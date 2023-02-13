#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define SIZE 100

int stack_1[SIZE], stack_2[SIZE];
int top_1 = -1, top_2 = -1, count = 0;

void push1(int x)
{
    if (top_1 >= SIZE - 1)
        printf("\nStack Overflow");
    else
    {
        top_1 = top_1 + 1;
        stack_1[top_1] = x;
    }
}

int pop1()
{
    int x;
    if (top_1 < 0)
        printf("\nStack Underflow");
    else
    {
        x = stack_1[top_1];
        top_1 = top_1 - 1;
        return (x);
    }
}

void push2(int x)
{
    if (top_2 >= SIZE - 1)
        printf("\nStack Overflow");
    else
    {
        top_2 = top_2 + 1;
        stack_2[top_2] = x;
    }
}

int pop2()
{
    int x;
    if (top_2 < 0)
        printf("\nStack Underflow");
    else
    {
        x = stack_2[top_2];
        top_2 = top_2 - 1;
        return (x);
    }
}

void enqueue(int x)
{
    push1(x);
    count++;
}

void dequeue()
{
    if (top_1 == -1 && top_2 == -1)
        printf("\nQueue is Empty");
    else
    {
        for (int i = 0; i < count; i++)
        {
            int a = pop1();
            push2(a);
        }
        int b = pop2();
        printf("\nDequeue element : %d", b);
        printf("\n");
        count--;
        for (int i = 0; i < count; i++)
        {
            int c = pop2();
            push1(c);
        }
    }
}

void display()
{
    printf("Queue : ");
    for (int i = 0; i <= top_1; i++)
        printf("%d ", stack_1[i]);
}

void main()
{
    int ch, ele;
    while (1)
    {
        printf("\n1. Add element in Queue.");
        printf("\n2. Delete element from Queue.");
        printf("\n3. Show all element from Queue.");
        printf("\n4. Exit.");

        printf("\nEnter your Choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\nEnter element : ");
            scanf("%d", &ele);
            enqueue(ele);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            printf("\nYou opted to Exit..");
            exit(0);

        default:
            printf("\nInvalid Choice");
            break;
        }
    }
}