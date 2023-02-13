#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SIZE 50

char stack[SIZE];
int top = -1;

void push(char item)
{
	if (top >= SIZE - 1)
	{
		printf("\nStack Overflow.");
	}
	else
	{
		top = top + 1;
		stack[top] = item;
	}
}

char pop()
{
	char item;
	if (top < 0)
	{
		exit(0);
		getchar();	
	}
	else
	{
		item = stack[top];
		top = top - 1;
		return (item);
	}
}

int is_operator(char symbol)
{
	if (symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-')
		return 1;
	else
		return 0;
}

int precedence(char symbol)
{
	if (symbol == '^')
		return 3;
	else if (symbol == '*' || symbol == '/')
		return 2;
	else if (symbol == '+' || symbol == '-')
		return 1;
	else
		return 0;
}

void InfixToPostfix(char infix[], char postfix[], int choice)
{
	int i, j, k = 0,top=-1;
	char item;
	char x;

	push('(');
	strcat(infix, ")");

	i = 0;
	j = 0;

	item = infix[i];

	if (choice == 2)
		printf("\n\ninput\texpression\n");

	while (item != '\0')
	{
		if (item == '(')
			push(item);
		else if (isalnum(item))
		{
			postfix[j] = item;
			j++;
		}
		else if (is_operator(item) == 1)
		{
			x = pop();
			while (is_operator(x) == 1 && precedence(x) >= precedence(item))
			{
				postfix[j] = x;
				j++;
				x = pop();
			}
			push(x);
			push(item);
		}
		else if (item == ')')
		{
			x = pop();
			while (x != '(')
			{
				postfix[j] = x;
				j++;
				x = pop();
			}
		}
		else
		{
			printf("\nInvalid infix Expression.\n");
			getchar();
			exit(1);
		}
		
		if (choice == 2)
		{
			printf("%c\t", infix[i]);
			for (k = 0; k <= j; k++)
				printf("%c", postfix[k]);
			printf("\n");
		}

		i++;
		item = infix[i];
	}
	if (top > 0)
	{
		printf("\nInvalid infix Expression.\n");
		getchar();
		exit(1);
	}

	postfix[j] = '\0';
}

int main()
{
	char infix[SIZE], postfix[SIZE];
	int choice, i;

	printf("\nEnter Infix expression : ");
	gets(infix);

	do
	{
		printf("\n1. Print Postfix expression.");
		printf("\n2. Print Postfix expression with step by step.");
		printf("\n3. Exit");
		printf("\nEnter Choice : ");
		scanf("%d", &choice);
		for (i = 0; i < SIZE; i++)
			postfix[i] = ' ';
		switch (choice)
		{
		case 1:
			InfixToPostfix(infix, postfix, choice);
			printf("\n");
			printf("Postfix Expression : ");
			puts(postfix);
			break;

		case 2:
			InfixToPostfix(infix, postfix, choice);
			printf("\n");
			printf("Postfix Expression : ");
			puts(postfix);
			break;

		case 3:
			printf("You opted to exit.");
			exit(0);
			break;

		default:
			break;
		}
	} while (1);

	return 0;
}
