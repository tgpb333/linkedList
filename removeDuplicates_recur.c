#include <stdio.h>

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
    printf("%d ",curr->data);
    curr = curr->next;
  }
  printf("\n");
}

void removeDups_recur(struct Node* head){
  if(head ==  NULL)
    return;
  if(head->next != NULL){
    if(head->next->data == head->data){
      head->next = head->next->next;
      removeDups_recur(head);
    }
    else
      removeDups_recur(head->next);
  }
}

int main() {
  
    // Create a sorted linked list:
    // 11->11->11->13->13->20
    struct Node *head = createNode(11);
    head->next = createNode(11);
    head->next->next = createNode(11);
    head->next->next->next = createNode(13);
    head->next->next->next->next = createNode(13);
    head->next->next->next->next->next = createNode(20);

    printf("Linked list before duplicate removal:\n");
    printList(head);

    removeDups_recur(head);

    printf("Linked list after duplicate removal:\n");
    printList(head);

    return 0;
}
