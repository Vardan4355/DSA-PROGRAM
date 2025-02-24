 #include <stdio.h>
#include <stdlib.h>
#define MAX 10 // Define the maximum size of the stack
typedef struct Stack {
    int arr[MAX];
    int top;
} Stack;
// Function to initialize the stack
void initStack(Stack* s) {
    s->top = -1; // Stack is initially empty
}
// Function to check if the stack is full
int isFull(Stack* s) {
    return s->top == MAX - 1;
}
// Function to check if the stack is empty
int isEmpty(Stack* s) {
    return s->top == -1;
}
// Function to push an element onto the stack
void push(Stack* s, int item) {

    if (!isFull(s)) {
        s->arr[++(s->top)] = item; // Increment top and add item
    } else {
        printf("Stack Overflow: Cannot push %d\n", item);
  }
}
// Function to pop an element from the stack
int pop(Stack* s) {
    if (!isEmpty(s)) {
        return s->arr[(s->top)--]; // Return top item and decrement top
    } else {
        printf("Stack Underflow: Cannot pop from empty stack\n");
        return -1; // Return -1 to indicate an error
    }
}
// Function to display all elements in the stack
void display(Stack* s) {
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}
int main() {
    Stack stack;
    initStack(&stack);
    // Push 3 elements in the stack
    push(&stack, 90);
    push(&stack, 12);
    push(&stack, 56);
    // Pop 1 element from the stack
    pop(&stack);
    // Push 2 elements in the stack
    push(&stack, 88);
    push(&stack, 12);
    // Pop 3 elements from the stack
    pop(&stack);
    pop(&stack);
    pop(&stack);
    // Display all stack elements
    display(&stack);
    return 0;
}