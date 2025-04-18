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
  while(curr != NULL){
    printf("%d ", curr->data);
    curr = curr->next;
  }
  printf("\n");
};

int getMedian(struct Node* head){
  struct Node *slow = head, *fast = head;
  struct Node *prev = NULL;
  while(fast && fast->next){
    prev = slow;
    slow = slow->next;
    fast = fast->next->next;
  }
  if(fast ==  NULL)
    return ((slow->data + prev->data)/2);
  else
    return slow->data;
}

int main() {
    // Create a hard-coded linked list:
    // 10 -> 20 -> 30 -> 40 -> 50 -> 60 
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);
    head->next->next->next->next = createNode(50);
    head->next->next->next->next->next = createNode(60);
    printList(head);
    printf("%d\n", getMedian(head));

    return 0;
}
