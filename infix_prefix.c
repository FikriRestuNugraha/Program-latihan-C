#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

typedef struct {
    int top;
    char items[MAX];
} Stack;

void push(Stack *s, char c) {
    s->items[++(s->top)] = c;
}

char pop(Stack *s) {
    if (s->top == -1)
        return '\0';

    return s->items[(s->top)--];
}

char peek(Stack *s) {
    return s->items[s->top];
}

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int isOperator(char c) {
    return c == '+' || c == '-' ||
           c == '*' || c == '/' || c == '^';
}

void reverse(char *str) {
    int i = 0;
    int j = strlen(str) - 1;

    while (i < j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

void infixToPrefix(char *infix, char *prefix) {
    char reversed[MAX];
    char postfix[MAX];

    strcpy(reversed, infix);

    reverse(reversed);

    for (int i = 0; reversed[i] != '\0'; i++) {
        if (reversed[i] == '(')
            reversed[i] = ')';
        else if (reversed[i] == ')')
            reversed[i] = '(';
    }

    Stack s;
    s.top = -1;

    int i = 0;
    int j = 0;

    while (reversed[i] != '\0') {
        if (isalnum(reversed[i])) {
            postfix[j++] = reversed[i];
        }
        else if (reversed[i] == '(') {
            push(&s, reversed[i]);
        }
        else if (reversed[i] == ')') {
            while (s.top != -1 && peek(&s) != '(') {
                postfix[j++] = pop(&s);
            }

            pop(&s);
        }
        else if (isOperator(reversed[i])) {
            while (s.top != -1 &&
                   precedence(peek(&s)) > precedence(reversed[i])) {
                postfix[j++] = pop(&s);
            }

            push(&s, reversed[i]);
        }

        i++;
    }

    while (s.top != -1) {
        postfix[j++] = pop(&s);
    }

    postfix[j] = '\0';

    strcpy(prefix, postfix);
    reverse(prefix);
}

int main() {
    char infix[MAX];
    char prefix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}