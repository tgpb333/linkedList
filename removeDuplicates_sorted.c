
// C Program to remove duplicates from a 
// sorted linked list
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
    printf("%d ", curr->data);
    curr = curr->next;
  }
  printf("\n");
}

struct Node* removeDups(struct Node* head){
  struct Node* curr = head;
  while(curr != NULL && curr->next !=NULL){
    if(curr->data == curr->next->data){
      curr->next = curr->next->next;
    }
    else
      curr = curr->next;
  }
  return head;
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
  	head->next->next->next->next->next->next =createNode(20);
  	head->next->next->next->next->next->next->next = createNode(20);
  	head->next->next->next->next->next->next->next->next = createNode(20);

    printf("Linked list before duplicate removal:\n");
    printList(head);

    head = removeDups(head);

    printf("Linked list after duplicate removal:\n");
    printList(head);

    return 0;
}
