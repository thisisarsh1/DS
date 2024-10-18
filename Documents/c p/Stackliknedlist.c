#include <stdio.h>
#include <stdlib.h>

struct Node{
int data;
struct Node *link;
};

struct Stack{
struct Node *top;
};

struct Node *newNode (int data){
struct Node *head = (struct Node *) malloc(sizeof(struct Node));
(*head).data = data;
(*head).link = NULL;
return head;
}

struct Stack *createStack () {
struct Stack *stack = (struct Stack *) malloc(sizeof (struct Stack));
(*stack).top = NULL;
return stack;
}

int isEmpty (struct Stack *stack) {
return !stack->top;
}

void push_data (struct Stack *stack, int data) {
printf("Push data %d\n", data);
struct Node *head = newNode (data);
head->link = stack->top;
stack->top = head;
}

int pop_data (struct Stack *stack) {
if (isEmpty (stack)) {
printf("\nStack is empty\n");
return -1;
}
struct Node *ptr = stack->top;
int popped = ptr->data;
stack->top = ptr->link;
free (ptr);
return popped;
}

int main() {
int n,i,element;
struct Stack *stackl = createStack();
printf("\n Enter the number of elements to be inserted by Rehbar Khan: ");
scanf("%d", &n);
for (i=0;i<n;i++){
printf("\nEnter the element to be inserted: ");
scanf("%d", &element);
push_data(stackl, element);
}
for (i=0;i<n;i++)
{
printf("\nPop data: %d", pop_data (stackl));
}
struct Stack *stack2 = createStack();
if (isEmpty (stack2)) {
printf("\n\nStack is empty\n");
}
else{
printf(" Stack is not empty!\n");
}
}