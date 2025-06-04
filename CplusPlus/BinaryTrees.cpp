#include <cstdlib>
#include <stdio.h>
#include "include/BinaryTrees.h"
BST::BST() {
  root = nullptr;
}

//  ~BST() {
//  }

BST::Node* min(BST::Node* tree) {
  BST::Node* newNode= tree;
  while (newNode ->left != nullptr) {
    newNode = newNode -> left; 
  }
  return newNode;
}

BST::Node* max(BST::Node* tree) {
  BST::Node* newNode = tree;
  while (newNode -> right != nullptr) {
    newNode = newNode -> right; 
  }
  return newNode;
}

void BST::insertNode(int data) {
  root = insertHelper(data, root);
}

BST::Node* BST::insertHelper(int data, BST::Node* tree) {
 
  if (tree == nullptr) {
    return new Node(data);
  }
  if (data > tree ->data) {
    tree->right = insertHelper(data, tree->right);
  }
  else {
    tree->left = insertHelper(data, tree->left);
  }
  return tree;
}

void BST::deleteNode(int data) {

}

BST::Node* BST::deleteHelper(BST::Node* tree) {
  return nullptr;
}

BST::Node* BST::pred(int data) {
  return nullptr;
}

BST::Node* BST::succ(int data) {
  return nullptr;
}

void BST::print(BST::Node* tree) {
  if (tree != nullptr) {
    BST::print(tree->left);
    printf("%d\n", tree->data);
    BST::print(tree->right);
  }
}



int main(void) {
BST bst;
for (int i = 0; i < (0x2 << 24); i++) {
    bst.insertNode(rand() % 10000);
}
  bst.print(bst.root);
}
