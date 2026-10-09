#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push operation
void push(int value)
{
    stack[++top] = value;
}

// Pop operation
int pop()
{
    return stack[top--];
}

// Evaluate postfix expression
int evaluatePostfix(char postfix[])
{
    int i, a, b;

    for (i = 0; postfix[i] != '\0'; i++)
    {
        // If operand, push it
        if (isdigit(postfix[i]))
        {
            push(postfix[i] - '0');
        }
        // If operator, pop two operands
        else
        {
            b = pop();
            a = pop();

            switch (postfix[i])
            {
                case '+':
                    push(a + b);
                    break;

                case '-':
                    push(a - b);
                    break;sss

                case '*':
                    push(a * b);
                    break;

                case '/':
                    push(a / b);
                    break;
            }
        }
    }

    return pop();
}

int main()
{
    char postfix[MAX];
    int result;

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    result = evaluatePostfix(postfix);

    printf("Result = %d\n", result);

    return 0;
}
