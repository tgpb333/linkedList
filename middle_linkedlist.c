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

int getMiddle(struct Node* head){
  struct Node* slow = head;
  struct Node* fast = head;
  while(fast && fast->next){
    fast = fast->next->next;
    slow = slow->next;
  }
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

    printf("%d\n", getMiddle(head));

    return 0;
}
