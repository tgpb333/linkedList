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
  }
  printf("\n");
}

struct Node* insertBeforeKey(struct Node* head, int key, int ndata){
  if(head == NULL) 
    return NULL;
  if(head->data == key){
    struct Node* nnode = createNode(ndata);
    nnode->next = head;
    return nnode;
  }
  struct Node* curr = head;
  struct Node* prev = NULL;
  while(curr != NULL && curr != key){
    prev = curr;
    curr = curr->next;
  }
  if(curr != NULL){
    struct Node* nnode = createNode(ndata);
    nnode->next = curr;
    prev->next = nnode;
  }
  return head;
}

int main() {
  
    // Create a hard-coded linked list: 
    // 1 -> 2 -> 3 -> 4 -> 5
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    int newData = 6;
    int key = 2;

    head = insertBeforeKey(head, key, newData);

    printList(head);

    return 0;
}
