#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

// Function prototypes
void push(int stack[], int val);
int pop(int stack[]);
int isEmpty();
void decimalToBinary(int decimal);

int main()
{
    int decimal;

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    if (decimal < 0)
    {
        printf("Please enter a non-negative number.\n");
        return 1;
    }

    printf("Binary equivalent: ");
    decimalToBinary(decimal);

    return 0;
}

// Function to convert decimal to binary using a stack
void decimalToBinary(int decimal)
{
    // Edge case for 0
    if (decimal == 0)
    {
        printf("0\n");
        return;
    }

    // Push remainders onto the stack
    while (decimal > 0)
    {
        push(stack, decimal % 2);
        decimal /= 2;
    }

    // Pop and print to get binary representation
    while (!isEmpty())
    {
        printf("%d", pop(stack));
    }
    printf("\n");
}

// Function to push a value onto the stack
void push(int stack[], int val)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = val;
}

// Function to pop a value from the stack
int pop(int stack[])
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

// Function to check if the stack is empty
int isEmpty()
{
    return top == -1;
}
