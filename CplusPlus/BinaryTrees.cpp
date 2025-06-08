#include <cmath>
#include <cstdlib>
#include <stdio.h>
#include "include/BinaryTrees.h"
BST::BST() {
  root = nullptr;
  manyItems = 0;
}

//  BST::~BST() {
//    deleteTree(root);
//  }
//  
//  BST::deleteTree(BST::Node* tree) {
//  deleteTree(tree->left);
//  deleteTree(tree->right);
//  delete tree;
//}

bool BST::find(BST::Node* tree, int data) {
  bool found = false;
  if (tree == nullptr) return false;
  if (data > tree->data) {
    found = find(tree->left, data);
  }
  if (data < tree->data) {
    found = find(tree->right, data);
  }
  if (tree->data == data) return true;
  return found;
}
/*
*
*/
BST::Node* BST::min(BST::Node* tree) {
  BST::Node* newNode= tree;
  while (newNode ->left != nullptr) {
    newNode = newNode -> left; 
  }
  return newNode;
}

/*
*
*/
BST::Node* BST::max(BST::Node* tree) {
  BST::Node* newNode = tree;
  while (newNode -> right != nullptr) {
    newNode = newNode -> right; 
  }
  return newNode;
}

/*
* Time inserting 2^20 nodes w/o balance:
* Time with balance: 4.42s user 4.52s system 53% cpu 16.584 total
*/
void BST::insertNode(int data) {
  root = insertHelper(data, root);
  manyItems++;
  root = balance(data, root);
}


/*
*
*/
BST::Node* BST::insertHelper(int data, BST::Node* tree) {
 
  if (tree == nullptr) {
    return new BST::Node(data);
  }
  if (data > tree ->data) {
    tree->right = insertHelper(data, tree->right);
  }
  else {
    tree->left = insertHelper(data, tree->left);
  }
  return tree;
}

BST::Node* BST::rotateToRoot(BST::Node* newNode, BST::Node* tree) {
  BST::Node* oldRoot = tree;
  BST::Node* oldLeft = nullptr;
  BST::Node* oldRight = nullptr;
  if (tree == newNode) {
    return tree;
  }
  if (oldRoot->left != nullptr) {
    oldLeft = oldRoot->left;
  }
  if (oldRoot->right != nullptr) {
    oldRight = oldRoot->right;
  }
  if ((std::rand() % 10) % 2 == 0) {
  //get right rotated idiot
    tree = newNode;
    tree->right = oldRoot;
    tree->right->left = oldRight;
  } else {
    //get left rotated idiot
    tree = newNode;
    tree->left = oldRoot;
    if (newNode->left != nullptr) {
      tree->left->right = newNode->left;
    }
  }
  return tree;
}

/*
* using random balancing, gud enuff 4 me
*/
BST::Node* BST::balance(int data, BST::Node* tree) {
  double prob = std::rand();
  double denom = 1.0 / manyItems; 
  if (prob < denom) {
    tree = insertHelper(data, tree);
    tree = rotateToRoot(new BST::Node(data), tree);
  } else {
    return tree;
  }
  return tree;
}

/*
*
*/
void BST::deleteNode(int data) {
  root = deleteHelper(data, root);
}

/*
*
*/
BST::Node* BST::deleteHelper(int data, BST::Node* tree) {
  //if tree is empty, return null.
  if (tree == nullptr) return nullptr;
  //traverse tree to find data to delete
  if (data > tree->data) {
    tree->right = deleteHelper(data, tree->right);
  }
  if (data < tree->data) {
    tree->left = deleteHelper(data, tree->left);
  }
  //delete leaf
  if (tree->left == nullptr && tree->right == nullptr) {
    return nullptr; 
  }
  //one child, return the child (deleting node above it)
  if(tree->left == nullptr && tree->right != nullptr) {
    return tree->right;
  }
  if(tree->right == nullptr && tree->left != nullptr) {
    return tree->left;
  }
  // Two children
  if (tree->left != nullptr && tree->right != nullptr) {
    BST::Node* succy = succ(data);
    tree->data = succy->data;
    tree = deleteHelper(succy->data, tree);
  }
  return tree;
}

/*
*
*/
BST::Node* BST::pred(int data) {
  BST::Node* pred = nullptr;
  if (data == root->data && root->left != nullptr) {
    pred = BST::max(root->left);
  } else {
    BST::Node* cursor = root;
    if (data > cursor->data && cursor->right != nullptr) {
      cursor = cursor->right;
    }
    if (data < cursor->data && cursor->left != nullptr) {
      cursor = cursor->left;
      pred = cursor;
    }
  }
  return pred;
}

/*
*
*/
BST::Node* BST::succ(int data) {
  BST::Node* succ = nullptr;
  if (data == root->data && root->left != nullptr) {
    succ = BST::max(root->left);
  } else {
    BST::Node* cursor = root;
    if (data > cursor->data && cursor->right != nullptr) {
      cursor = cursor->right;
      succ = cursor;
    }
    if (data < cursor->data && cursor->left != nullptr) {
      cursor = cursor->left;
    }
  }
  return succ;
}

/*
*
*/
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
    bst.insertNode(rand() % 100000000000);
}
  //bst.print(bst.root);
}
