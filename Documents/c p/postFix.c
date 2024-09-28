#include <stdio.h> //POSTFIX EXPRESSION USING STACK ADT BY Rehbar Khan [231P021]
#include <ctype.h>
#include <stdlib.h>

#define MAX 100

typedef struct Stack {
    int arr[MAX];
    int top;
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

void push(Stack *s, int val) {
    if (!isFull(s)) {
        s->arr[++(s->top)] = val;
    } else {
        printf("Stack overflow!\n");
    }
}

int pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->arr[(s->top)--];
    } else {
        printf("Stack underflow!\n");
        return -1;
    }
}

int evaluatePostfix(char *expression) {
    Stack s;
    initStack(&s);
    for (int i = 0; expression[i] != '\0'; i++) {
        if (isdigit(expression[i])) {
            push(&s, expression[i] - '0');
        } else {
            int val1 = pop(&s);
            int val2 = pop(&s);
            switch (expression[i]) {
                case '+':
                    push(&s, val2 + val1);
                    break;
                case '-':
                    push(&s, val2 - val1);
                    break;
                case '*':
                    push(&s, val2 * val1);
                    break;
                case '/':
                    push(&s, val2 / val1);
                    break;
                default:
                    printf("Invalid operator encountered: %c\n", expression[i]);
                    return -1;
            }
        }
    }
    return pop(&s);
}

int main() {
    char expression[MAX];
    printf("POSTFIX EXPRESSION ENTERED BY Rehbar Khan [231P021]: ");
    scanf("%s", expression);
    int result = evaluatePostfix(expression);
    printf("Result of Postfix Evaluation: %d\n", result);
    return 0;
}
