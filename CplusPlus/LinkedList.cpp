#include <stdio.h>
//the basic Node class to handle the data points
struct Node {
  int data;
  Node* next;
  Node* prev;
  Node(int newNum){
    data = newNum;
    next = nullptr;
    prev = nullptr;
  }
};
Node* insertAtFront(Node* root, int newNum){
  Node* newNode = new Node(newNum);
  newNode->next = root;
  root->prev = newNode;
  return newNode;
}

class LinkedList{
  Node* head;
  Node* tail;
  Node* cursor;
  LinkedList()
  {
    head = nullptr;
    cursor = head;
    tail = nullptr;  
  }
};

int main (void){
  Node* first = new Node(10);
  first = insertAtFront(first, 20);
  first = insertAtFront(first, 30);
  first = insertAtFront(first, 40);
  while (first != nullptr){
    printf("%d\n", first->data);
    first = first->next;
  }
}


