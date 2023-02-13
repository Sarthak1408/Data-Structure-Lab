#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *HEAD = NULL;

Node *createNode(int a)
{
    Node *newnode = malloc(sizeof(Node));
    newnode->data = a;
    newnode->next = NULL;
    return newnode;
}

void addNode(int a)
{
    Node *newNode = createNode(a);
    if (HEAD == NULL)
        HEAD = newNode;
    else
    {
        Node *lastNode = HEAD;
        while (lastNode->next != NULL)
            lastNode = lastNode->next;

        lastNode->next = newNode;
    }
}

void delBeg()
{
    if (HEAD == NULL)
        return;
    else if (HEAD->next == NULL)
        HEAD = NULL;
    else
    {
        Node *p = HEAD;
        while (p->next->next != NULL)
            p = p->next;
        
        p->next = NULL;
    }
}

void printList()
{
    Node *p = HEAD;
    while (p != NULL)
    {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

void main()
{
    int ch, val;
    printf("\n\t NAME -> Sarthak Mathur \t Reg_no. -> 2247262");
    while (1)
    {
        printf("\n1. Insert Node in a Queue.");
        printf("\n2. Delete Node in a Queue.");
        printf("\n3. Print the Queue.");
        printf("\n4. EXIT.");

        printf("\nEnter your Choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\nEnter value to Insert : ");
            scanf("%d", &val);
            addNode(val);
            break;

        case 2:
            printf("\nOne item deleted from the Queue..\n");
            delBeg();
            break;

        case 3:
            printf("\n");
            printList();
            break;

        case 4:
            printf("\nYou opted to Exit. ");
            exit(0);

        default:
            printf("\nInvalid Choice, Try Again");
            break;
        }
    }
}