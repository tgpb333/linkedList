#include<stdio.h>

struct Node{
  int data;
  struct Node* next;
};

struct Node* createNode(int ndata){
  struct Node* nnode = (struct Node*)malloc(sizeof(struct Node));
  nnode->data = ndata;
  nnode->next = NULL;
  return nnode;
}

void printList(struct Node* head){
  struct Node* curr = head;
  while(curr){
    printf("%d ", curr->data);
    curr = curr->next;
  }
  printf("\n");
}

struct Node* reverseList(struct Node* head){
  struct Node *curr = head, *next = head;
  struct Node* prev = NULL;
  while(curr){
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;    
  }
  return prev;
}

int main() {

    // Create a hard-coded linked list:
    // 1 -> 2 -> 3 -> 4 -> 5
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Given Linked list:");
    printList(head);

    head = reverseList(head);

    printf("\nReversed Linked List:");
    printList(head);

    return 0;
}
