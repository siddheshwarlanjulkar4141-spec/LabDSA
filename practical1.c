#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

// Stack structure for integer operands
typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int val) {
    if (s->top >= MAX_SIZE - 1) {
        printf("Error: Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    s->data[++(s->top)] = val;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Error: Invalid postfix expression (Stack underflow)\n");
        exit(EXIT_FAILURE);
    }
    return s->data[(s->top)--];
}

int evaluatePostfix(const char *expr) {
    Stack s;
    initStack(&s);

    for (int i = 0; expr[i] != '\0'; i++) {
        // Skip spaces and tabs
        if (expr[i] == ' ' || expr[i] == '\t') {
            continue;
        }

        // Parse multi-digit numbers
        if (isdigit(expr[i])) {
            int num = 0;
            while (isdigit(expr[i])) {
                num = num * 10 + (expr[i] - '0');
                i++;
            }
            i--; // Step back to align with main loop increment
            push(&s, num);
        }
        // Operator evaluation
        else {
            int operand2 = pop(&s);
            int operand1 = pop(&s);

            switch (expr[i]) {
                case '+': push(&s, operand1 + operand2); break;
                case '-': push(&s, operand1 - operand2); break;
                case '*': push(&s, operand1 * operand2); break;
                case '/':
                    if (operand2 == 0) {
                        printf("Error: Division by zero\n");
                        exit(EXIT_FAILURE);
                    }
                    push(&s, operand1 / operand2);
                    break;
                default:
                    printf("Error: Unsupported operator '%c'\n", expr[i]);
                    exit(EXIT_FAILURE);
            }
        }
    }

    int result = pop(&s);

    // If stack is not empty after popping result, expression was invalid
    if (!isEmpty(&s)) {
        printf("Error: Invalid postfix expression\n");
        exit(EXIT_FAILURE);
    }

    return result;
}

int main() {
    // Example: "5 3 10 * + 9 -" translates to 5 + (3 * 10) - 9 = 26
    const char *expression = "5 3 10 * + 9 -";
    
    printf("Postfix Expression: %s\n", expression);
    printf("Result: %d\n", evaluatePostfix(expression));

    return 0;
}