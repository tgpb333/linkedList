// C program to remove duplicates from an 
// unsorted linked list
#include<stdio.h>

struct Node{
  int data;
  struct Node* next;
};

int hash_arr[100]={0};

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

struct Node* removeDups_unsorted(struct Node* head){
  if(head == NULL)
    return NULL;
  //initialization
  if(head->next == NULL)
    return head;
  struct Node* prev = head;
  struct Node* curr = head->next;
  hash_arr[head->data] = 1; 
  //traversal and checking
  while(prev != NULL && curr != NULL){
    if(hash_arr[curr->data] == 1){
      struct Node* temp = curr;
      prev->next = curr->next;
      curr = curr->next;
      free(temp);
    }
    else{
      hash_arr[curr->data] = 1;
      prev = curr;
      curr = curr->next;
    }
  }
  return head;
}

int main() {
    // Create a singly linked list:
    // 12 -> 11 -> 12 -> 21 -> 41 -> 43 -> 21
    struct Node* head = createNode(12);
    head->next = createNode(11);
    head->next->next = createNode(12);
    head->next->next->next = createNode(21);
    head->next->next->next->next = createNode(41);
    head->next->next->next->next->next = createNode(43);
    head->next->next->next->next->next->next = createNode(21);
	printf("Original List:");
  	printList(head);
    head = removeDups_unsorted(head);
    printList(head);

    return 0;
}
