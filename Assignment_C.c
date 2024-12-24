#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAX 100
char stack[MAX];
int top = -1;

void pushChar(char x) {
    stack[++top] = x;
}

char popChar() {
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

int precedence(char x) {
    if (x == '^')
        return 3;
    if (x == '*' || x == '/')
        return 2;
    if (x == '+' || x == '-')
        return 1;
    return 0;
}

void infixToPostfix(char *exp) {
    char *e, x;
    e = exp;

    while (*e != '\0') {
        if (isalnum(*e))
            printf("%c", *e);
        else if (*e == '(')
            pushChar(*e);
        else if (*e == ')') {
            while ((x = popChar()) != '(')
                printf("%c", x);
        } else {
            while (precedence(stack[top]) >= precedence(*e))
                printf("%c", popChar());
            pushChar(*e);
        }
        e++;
    }
    while (top != -1) {
        printf("%c", popChar());
    }
}

int main() {
    char exp[] = "((a+b)^((c/d)*e))";
    printf("Postfix expression: ");
    infixToPostfix(exp);
    return 0;
}
