#pragma once
class BST {

public:

 struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    //I have never made a struct constructor before
    Node(int num) : data(num),  left(nullptr),  right(nullptr) {}
  };
  Node* root;
  BST();
  Node* min();
  Node* max();
  void insertNode(int data);
  void deleteNode(int data);
  Node* pred(int data);
  Node* succ(int data);
  void print(Node* tree);

private:
  Node* insertHelper(int data, Node* root);
  Node* deleteHelper(Node* root);


};

