//
// Created by rabilint on 01.10.25.
//

#ifndef LAB4_1_TREE_H
#define LAB4_1_TREE_H
#include <array>

typedef int datatype;
struct Node
{
    datatype data;
    Node* parent;
    Node* left;
    Node* right;
};

void createTree(Node*& node,int n, int& iterrator);
void preOrder(const Node* node);
void inOrder(const Node* node);
void postOrder(const Node* node);
void displayTree(const Node* node, int level);
Node* searchTree( Node* root, int key);
Node* searchTreeBST(Node* node, int key);
void insertNodeBST(Node*& node, int key);


Node* deleteNodeBST(Node*& root, int key);

Node* findMin(Node* node);
Node* findMax(Node* node);

Node* successor(Node* node);
Node* PredecessorNodeBST(Node* node);



#endif //LAB4_1_TREE_H