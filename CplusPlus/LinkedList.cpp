#include <stdio.h>
struct Node {
  int data;
  Node* next;
  Node* prev;
  Node(int newNum)
  {
    data = newNum;
    next = nullptr;
    prev = nullptr;
  }
};
Node* insertAtFront(Node* root, int newNum)
{
  Node* newNode = new Node(newNum);
  newNode->next = root;
  root->prev = newNode;
  return newNode;
}
int main (void)
{
  Node* first = new Node(10);
  first = insertAtFront(first, 20);
  first = insertAtFront(first, 30);
  first = insertAtFront(first, 40);
  while (first != nullptr)
  {
    printf("%d\n", first->data);
    first = first->next;
  }
}


