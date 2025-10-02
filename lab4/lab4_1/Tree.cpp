//
// Created by rabilint on 01.10.25.
//

#include "Tree.h"

#include <iostream>

int giveData(int& iterrator)
{
    return ++iterrator;
}

void displayTree(const Node* node, const int level)
{
    if(node==nullptr)
    {
        return;
    }
    displayTree(node->left,level+1);
    for(int i=0;i<level;i++)
    {
        std::cout<<"  ";
    }
    std::cout<<node->data<<"\n";
    displayTree(node->right,level+1);

}

void createTree(Node*& node, const int n, int& iterrator)
{
    if (n==0)
    {
        node=nullptr;
        return;
    }

    int n_left = n / 2;
    int n_right = n - n_left - 1;

    node = new Node;
    node->data= ++iterrator;
    node->left = nullptr;
    node->right = nullptr;

    createTree(node->left,n_left, iterrator);
    createTree(node->right,n_right, iterrator);
}

void preOrder(const Node* node)
{
    if (node==nullptr)
    {
        return;
    }
    std::cout<<node->data<<" ";
    preOrder(node->left);
    preOrder(node->right);
}
void inOrder(const Node* node)
{
    if (node==nullptr)
    {
        return;
    }
    inOrder (node->left);
    std::cout<<node->data<<" ";
    inOrder(node->right);
}
void postOrder(const Node* node)
{
    if (node==nullptr)
    {
        return;
    }
    postOrder(node->left);
    postOrder(node->right);
    std::cout<<node->data<<" ";
}

 Node* searchTree( Node* node, const int key)
{
    if (node==nullptr)
    {
        return nullptr;
    }
    if (key==node->data)
    {
        std::cout<<node->data<<" " << "Data found!" << std::endl;
        return node;
    }
     Node* foundInLeft = searchTree(node->left, key);
    if (foundInLeft!=nullptr)
    {
        return foundInLeft;
    }
    Node* foundInRight = searchTree(node->right, key);
    return foundInRight ;

}

Node* searchTreeBST(Node* node, int key)
{
    Node* currentNode = node;
    while (currentNode!=nullptr && currentNode->data!=key)
    {
        if (key < currentNode->data)
        {
            currentNode = currentNode->left;
        }
        else
        {
            currentNode = currentNode->right;
        }
    }
    return currentNode;
}


void insertNodeBST(Node*& node, const int key)
{
    if (searchTreeBST(node,key)!=nullptr)
    {
        std::cout<<"Key already exists!"<<std::endl;
        return;
    }
    Node* newNode = new Node;
    newNode->data = key;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->parent = nullptr;

    if (node==nullptr)
    {
        node = newNode;
        return;
    }
    Node* currentNode = node;
    Node* parentNode = nullptr;
    while (currentNode!=nullptr)
    {
        parentNode = currentNode;
        if (key < currentNode->data)
        {
            currentNode = currentNode->left;
        }
        else
        {
            currentNode = currentNode->right;
        }
    }

    newNode->parent = parentNode;
    if (key < parentNode->data)
    {
        parentNode->left = newNode;
    }
    else
    {
        parentNode->right = newNode;
    }
}

Node* findMin(Node* node)
{
    while (node!=nullptr && node->left!=nullptr)
    {
        node = node->left;
    }
    return node;
}

Node* findMax(Node* node)
{
    while (node!=nullptr && node->right!=nullptr)
    {
        node = node->right;
    }
    return node;
}

Node* deleteNodeBST(Node*& root, const int key)
{
    if (root==nullptr)
    {
        return root;
    }
    if (key < root->data)
    {
        root->left = deleteNodeBST(root->left, key);
    }
    else if ( key > root->data)
    {
        root->right = deleteNodeBST(root->right, key);
    }
    else
    {
        if ( root->left == nullptr)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }else if (root->right == nullptr)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* successor = findMin(root->right);
        root->data = successor->data;
        root->right = deleteNodeBST(root->right, root->data);
    }
    return root;
}


Node* successor(Node* node)
{
    if ( node==nullptr)
    {
        return nullptr;
    }

    if (node->right != nullptr)
    {
        return findMin(node->right);
    }
    Node* parent = node->parent;
    if (parent==nullptr)
    {
        return nullptr;
    }
    if (parent->right == node)
    {
        return successor(parent);
    }
    return parent;
}

Node* PredecessorNodeBST(Node* node)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    if (node->left != nullptr)
    {
        return findMax(node->left);
    }
    Node* parent = node->parent;
    if (parent==nullptr)
    {
        return nullptr;
    }
    if (parent->left== node)
    {
        return PredecessorNodeBST(parent);
    }
    return parent;
}