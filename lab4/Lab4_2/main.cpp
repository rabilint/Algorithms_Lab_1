#include <iostream>
#include "Tree.h"

int main()
{
    Node* rootForPart2 = nullptr;
    for (std::array array = {4, 2, 6, 1, 3, 5, 7}; int i : array)
    {
        insertNodeBST( rootForPart2, i);
    }
    std::cout << "BST : " << std::endl;
    displayTree(rootForPart2,0);
    int input = 0;
    std::cout << "Search Tree BST: " << std::endl;
    Node* foundNode = searchTreeBST(rootForPart2, input);

    if (foundNode != nullptr)
    {
        std::cout << "Node with key " << foundNode->data << " found at address " << foundNode << std::endl;
    }
    else
    {
        std::cout << "Node with key " << input << " not found." << std::endl;
    }

    displayTree(rootForPart2,0);
    int input2;
    std::cout << "Key to delete";
    std::cin >> input2;
    rootForPart2 = deleteNodeBST(rootForPart2, input2);

    displayTree(rootForPart2,0);

    foundNode = successor(rootForPart2);
    std::cout << "Node with key " << foundNode->data << " is successor of " << rootForPart2->data << std::endl;

    Node* predecessor = PredecessorNodeBST(rootForPart2);
    std::cout << "Node with key: " << predecessor->data << " is Predecessor of " << rootForPart2->data << std::endl;


}