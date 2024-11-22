#include "Tree.h"
#include <iostream>


int main() {

    Tree<int> intTree;

    intTree.insert(10);
    intTree.insert(5);
    intTree.insert(15);
    intTree.insert(3);
    intTree.insert(7);

    std::cout << "Pre-order traversal of intTree: ";
    intTree.preOrderTraversal();

    std::cout << "Post-order traversal of intTree: ";
    intTree.postOrderTraversal();

    Tree<std::string> stringTree;
    stringTree.insert("apple");
    stringTree.insert("banana");
    stringTree.insert("cherry");
    stringTree.insert("date");
    stringTree.insert("fig");

    std::cout << "\nPre-order traversal of stringTree: ";
    stringTree.preOrderTraversal();

    std::cout << "Post-order traversal of stringTree: ";
    stringTree.postOrderTraversal();

    return 0;
}
