#include<stdio.h>
#include<stdbool.h>

#define MAX_SIZE 100

typedef struct{
  int arr[MAX_SIZE];
  int top;
}Stack;

void initialize(Stack *stack){
  stack->top = -1;
}

bool isEmpty(Stack *stack){
  if(stack->top == -1)
    return true;
  else return false;
}

bool isFull(Stack *stack){
  if(stack->top == MAX_SIZE-1)
    return true;
  else return false;
}

void push(Stack *stack, int ndata){
  if(isFull(stack)){
    printf("Stack is Full.. Overflow!\n");
    return;
  }
  stack->top++;
  stack->arr[(stack->top)] = ndata;
  printf("Pushed %d onto the stack\n", ndata);
}


int pop(Stack *stack){
  if(isEmpty(stack)){
    printf("Stack is empty!\n");
    return -1;
  }
  int popped = stack->arr[stack->top];
  stack->top--;
  //printf("The popped element : %d\n", popped);
  return popped;
}

int peek(Stack *stack){
  if(isEmpty(stack)){
    printf("Stack is empty\n");
    return -1;
  }
  return stack->arr[stack->top];
}

int main() {
    Stack stack;
    // Initialize the stack
    initialize(&stack);  

    // Push elements onto the stack and print the stack after each push
    push(&stack, 3);
    //printf("Top element: %d\n", peek(&stack));

    push(&stack, 5);
    //printf("Top element: %d\n", peek(&stack));

    push(&stack, 2);
    //printf("Top element: %d\n", peek(&stack));

    push(&stack, 8);
    //printf("Top element: %d\n", peek(&stack));

    // Pop elements from the stack and print the stack after each pop
    while (!isEmpty(&stack)) {
    //    printf("Top element: %d\n", peek(&stack));
        printf("Popped element: %d\n", pop(&stack));
    }

    return 0;
}
