#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    int top;
    char items[MAX];
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, char item) {
    if (isFull(s)) return;
    s->items[++(s->top)] = item;
}

char pop(Stack *s) {
    if (isEmpty(s)) return '\0';
    return s->items[(s->top)--];
}

char peek(Stack *s) {
    if (isEmpty(s)) return '\0';
    return s->items[s->top];
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}

void InfixToPostfix(const char *infix, char *postfix) {
    Stack s;
    initStack(&s);
    int k = 0;
    
    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];
        
        if (isspace(ch)) continue;
        if (isalnum(ch)) postfix[k++] = ch;
        else if (ch == '(') push(&s, ch);
        else if (ch == ')') {
            while (!isEmpty(&s) && peek(&s) != '(')
                postfix[k++] = pop(&s);
            pop(&s);
        } else {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(ch))
                postfix[k++] = pop(&s);
            push(&s, ch);
        }
    }
    
    while (!isEmpty(&s))
        postfix[k++] = pop(&s);
    
    postfix[k] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];
    
    printf("Infix Expression entered by Rehbar Khan[231P021]: ");
    fgets(infix, MAX, stdin);
    
    InfixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    
    return 0;
}
