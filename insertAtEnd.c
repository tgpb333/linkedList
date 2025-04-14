#include<stdio.h>
#include<stdlib.h>

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
  while(curr != NULL){
    printf("%d ", curr->data);
    curr = curr->next;
  }
  printf("\n");
}

struct Node* insertAtEnd(struct Node* head, int ndata){
  if (head == NULL){
    struct Node* nnode = createNode(ndata);
    nnode->next = NULL;
    return nnode;
  }
  struct Node* curr = head;
  while(curr->next != NULL){
    curr = curr->next;
  }
  struct Node* nnode = createNode(ndata);
  curr->next = nnode;
  return head;
}

int main() {
  
    // Create a hard-coded linked list: 
    // 2 -> 3 -> 4 -> 5 -> 6
    struct Node* head = createNode(2);
    head->next = createNode(3);
    head->next->next = createNode(4);
    head->next->next->next = createNode(5);
    head->next->next->next->next = createNode(6);

    printf("Created Linked list is:");
    printList(head);

    // Example of appending a node at the end
    head = insertAtEnd(head, 1);

    printf("\nAfter inserting 1 at the end:");
    printList(head);

    return 0;
}
