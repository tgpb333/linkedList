#include<stdio.h>
#include<stdlib.h>

struct Node{
  int data;
  struct Node* next;
};

struct Node* createNode(int newdata){
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = newdata;
  newNode->next = NULL;
  return newNode;
}

struct Node* insertAfter(int ndata, int key, struct Node* head){
  struct Node* curr = head;
  while(curr != NULL){
    if(curr->data ==key)
      break;
    curr = curr->next;
  }
  if(curr == NULL){
    printf("Node not found!!");
    return head;
  }
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = ndata;
  newNode->next = curr->next;
  curr->next = newNode;
  return head;
}

void printList(struct node* head){
  struct Node* curr = head;
  while(curr != NULL){
    printf("%d ", curr->data);
    curr = curr->next;
  }
  printf("\n");
}

int main() {
  	
    // Create the linked list 2 -> 3 -> 5 -> 6
    struct Node* head = createNode(2);
    head->next = createNode(3);
    head->next->next = createNode(5);
    head->next->next->next = createNode(6);

    printf("Original Linked List: ");
    printList(head);

    // Key: Insert node after key
    int key = 3, newData = 4;

    // Insert a new node with data 4 after the node with data 3
    head = insertAfter(newData, key, head);

    printf("Linked List after insertion: ");
    printList(head);

    return 0;
}
