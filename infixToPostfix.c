#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int top = -1;
char st[MAX];

void push(char st[], char val);
char pop(char st[]);
void InfixtoPostfix(char source[], char target[]);
int getPriority(char op);

int main()
{
    char infix[MAX], postfix[MAX];

    printf("\nEnter any infix expression: ");
    fgets(infix, sizeof(infix), stdin); // Using fgets instead of gets for safety

    // Removing newline character if present
    size_t len = strlen(infix);
    if (len > 0 && infix[len - 1] == '\n')
        infix[len - 1] = '\0';

    InfixtoPostfix(infix, postfix);

    printf("\nThe corresponding postfix expression is: ");
    puts(postfix);

    return 0;
}

void InfixtoPostfix(char source[], char target[])
{
    int i = 0, j = 0;
    char temp;

    while (source[i] != '\0')
    {
        if (source[i] == '(')
        {
            push(st, source[i]);
        }
        else if (source[i] == ')')
        {
            while (top != -1 && st[top] != '(')
            {
                target[j++] = pop(st);
            }
            if (top == -1)
            {
                printf("\nINCORRECT EXPRESSION\n");
                exit(1);
            }
            pop(st); // Remove left parenthesis
        }
        else if (isdigit(source[i]) || isalpha(source[i]))
        {
            target[j++] = source[i];
        }
        else if (source[i] == '+' || source[i] == '-' || source[i] == '*' ||
                 source[i] == '/' || source[i] == '%')
        {
            while (top != -1 && st[top] != '(' && getPriority(st[top]) >= getPriority(source[i]))
            {
                target[j++] = pop(st);
            }
            push(st, source[i]);
        }
        else
        {
            printf("\nINCORRECT ELEMENT IN EXPRESSION\n");
            exit(1);
        }
        i++;
    }

    while (top != -1)
    {
        if (st[top] == '(')
        {
            printf("\nINCORRECT EXPRESSION\n");
            exit(1);
        }
        target[j++] = pop(st);
    }

    target[j] = '\0';
}

int getPriority(char op)
{
    if (op == '/' || op == '*' || op == '%')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

void push(char st[], char val)
{
    if (top == MAX - 1)
    {
        printf("\nSTACK OVERFLOW\n");
        exit(1);
    }
    st[++top] = val;
}

char pop(char st[])
{
    if (top == -1)
    {
        printf("\nSTACK UNDERFLOW\n");
        exit(1);
    }
    return st[top--];
}
