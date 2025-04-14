// C program for insertion in a single linked
// list at a specified position
#include <stdio.h>
#include <stdlib.h>

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

struct Node* insertAtPos(struct Node* head, int pos, int ndata){
  if(pos<1)
    return NULL;
  if(pos==1){
    struct Node* nnode = createNode(ndata);
    nnode->next = head;
    head = nnode;
    return nnode;
  }
  struct Node* curr = head;
  while(pos > 2 && curr != NULL){
    curr = curr->next;
    pos--;
  }
  if(curr==NULL)
    return head;
  struct Node* nnode = createNode(ndata);
  nnode->next = curr->next;
  curr->next = nnode;
  return head;
}

void printList(struct Node* head){
  struct Node* curr = head;
  while(curr!=NULL){
    printf("%d ", curr->data);
    curr = curr->next;
  }
  printf("\n");
}

int main() {

    // Creating the list 3->5->8->10
    struct Node *head = createNode(3);
    head->next = createNode(5);
    head->next->next = createNode(8);
    head->next->next->next = createNode(10);

    int data = 12, pos = 3;
    head = insertAtPos(head, pos, data);
    printList(head);

    return 0;
}
