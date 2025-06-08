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
  Node* min(Node* tree);
  Node* max(Node* tree);
  void insertNode(int data);
  void deleteNode(int data);
  Node* pred(int data);
  Node* succ(int data);
  void print(Node* tree);
  bool find(Node* tree, int data);

private:
  int manyItems;
  Node* balance(int data, Node* tree);
  void deleteTree(Node* tree);
  Node* rotateToRoot(Node* newNode, Node* root);
  Node* insertHelper(int data, Node* root);
  Node* deleteHelper(int data, Node* root);
};

