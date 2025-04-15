#include<stdio.h>

#include <stdbool.h>
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

int detectCycle(struct Node* head){
  struct Node* slow = head;
  struct Node* fast = head;
  while(slow && fast && fast->next){
    slow = slow->next;
    fast = fast->next->next;
    if(slow == fast)
      return true;
    }
  return false;
}

int main() {

    // Create a hard-coded linked list:
    // 1 -> 3-> 4
    struct Node* head = createNode(1);
    head->next = createNode(3);
    head->next->next = createNode(4);
  
	// Create a loop
    head->next->next->next = head->next;

    if (detectCycle(head))
        printf("true");
    else
        printf("false");

    return 0;
}
