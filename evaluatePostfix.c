#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 100

float st[MAX];
int top = -1;

// Function prototypes
void push(float st[], float val);
float pop(float st[]);
float evaluatePostfixExp(char exp[]);

int main()
{
    float val;
    char exp[100];

    printf("\nEnter any postfix expression (numbers separated by spaces): ");
    fgets(exp, sizeof(exp), stdin); // Use fgets to read the expression safely

    val = evaluatePostfixExp(exp);

    printf("\nValue of the postfix expression = %.2f\n", val);
    return 0;
}

// Function to evaluate a postfix expression
float evaluatePostfixExp(char exp[])
{
    int i = 0;
    float op1, op2, value;
    char token[20]; // Temporary buffer for parsing numbers

    while (exp[i] != '\0' && exp[i] != '\n') // Process until the end of the string
    {
        if (isspace(exp[i]))
        {
            // Skip whitespace
            i++;
            continue;
        }
        else if (isdigit(exp[i]) || exp[i] == '.') // Handle numbers (including decimals)
        {
            int j = 0;
            // Extract the full number (including decimal part)
            while (isdigit(exp[i]) || exp[i] == '.')
            {
                token[j++] = exp[i++];
            }
            token[j] = '\0'; // Null-terminate the number string
            push(st, atof(token)); // Convert string to float and push onto stack
        }
        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '%')
        {
            // Pop two operands from the stack
            op2 = pop(st);
            op1 = pop(st);

            // Perform the operation
            switch (exp[i])
            {
            case '+':
                value = op1 + op2;
                break;
            case '-':
                value = op1 - op2;
                break;
            case '/':
                if (op2 == 0)
                {
                    printf("\nError: Division by zero\n");
                    exit(1);
                }
                value = op1 / op2;
                break;
            case '*':
                value = op1 * op2;
                break;
            case '%':
                if ((int)op2 == 0)
                {
                    printf("\nError: Modulo by zero\n");
                    exit(1);
                }
                value = (int)op1 % (int)op2; // Modulo operation on integers
                break;
            }
            // Push the result back onto the stack
            push(st, value);
            i++;
        }
        else
        {
            printf("\nError: Invalid character '%c' in expression\n", exp[i]);
            exit(1);
        }
    }

    // The final result should be the only value left in the stack
    return pop(st);
}

// Function to push a value onto the stack
void push(float st[], float val)
{
    if (top == MAX - 1)
    {
        printf("\nError: STACK OVERFLOW\n");
        exit(1);
    }
    st[++top] = val;
}

// Function to pop a value from the stack
float pop(float st[])
{
    if (top == -1)
    {
        printf("\nError: STACK UNDERFLOW\n");
        exit(1);
    }
    return st[top--];
}
