#include <stdio.h>
#include <string.h>
#define MAX 10

int top = -1;
char stk[MAX];

// Function prototypes
void push(char c);
char pop();
int isMatchingPair(char left, char right);

int main()
{
    char exp[MAX];
    char temp;
    int i, flag = 1;

    printf("Enter an expression: ");
    gets(exp);

    for (i = 0; i < strlen(exp); i++)
    {
        // Push opening brackets onto the stack
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(exp[i]);
        }
        // Check for closing brackets
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            // If the stack is empty, it's an invalid expression
            if (top == -1)
            {
                flag = 0;
                break;
            }
            else
            {
                temp = pop();
                if (!isMatchingPair(temp, exp[i]))
                {
                    flag = 0;
                    break;
                }
            }
        }
    }

    // If the stack is not empty, it's an invalid expression
    if (top >= 0)
        flag = 0;

    if (flag == 1)
        printf("\nValid expression\n");
    else
        printf("\nInvalid expression\n");

    return 0;
}

// Function to push a character onto the stack
void push(char c)
{
    if (top == (MAX - 1))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top = top + 1;
        stk[top] = c;
    }
}

// Function to pop a character from the stack
char pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return '\0';
    }
    else
    {
        return stk[top--];
    }
}

// Function to check if a pair of brackets match
int isMatchingPair(char left, char right)
{
    if (left == '(' && right == ')')
        return 1;
    if (left == '{' && right == '}')
        return 1;
    if (left == '[' && right == ']')
        return 1;
    return 0;
}
