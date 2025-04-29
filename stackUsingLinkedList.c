#include<stdio.h>
#include<limits.h>

typedef struct Node{
  int data;
  struct Node* next;
}Node;

Node* createNode(int ndata){
  Node* nnode = (Node*)malloc(sizeof(Node));
  nnode->data = ndata;
  nnode->next = NULL;
  return nnode;
}

typedef struct Stack{
  Node* head;
}Stack;

void initialize(Stack* stack){
  stack->head = NULL;
}

int isEmpty(Stack* stack){
  return (stack->head == NULL);
}

void push(Stack* stack, int data){
  Node* nnode = createNode(data);
  if(!nnode){
    printf("Stack Overflow!!\n");
    return;     
  }
  nnode->next = stack->head;
  stack->head = nnode;
}

int pop(Stack* stack){
  if(!stack->head){
    printf("Stack Underflow!!\n");
    return INT_MIN;
  }
  else{
    Node* temp = stack->head;
    stack->head = stack->head->next;
    int popped = temp->data;
    free(temp);
    return popped;
  }
}

int peek(Stack* stack){
  if(!stack->head){
    printf("No elements in stack!!\n");
    return INT_MIN;
  }
  return stack->head->data;
}

int main(){
  Stack stack;
  initialize(&stack);
  push(&stack, 11);
  push(&stack, 12);
  push(&stack, 13);
  push(&stack, 14);
  printf("Top element is %d\n", peek(&stack));
  printf("Removing two elements...\n");
  pop(&stack);
  pop(&stack);

  // Print top element of the stack
  printf("Top element is %d\n", peek(&stack));

  return 0;
}
