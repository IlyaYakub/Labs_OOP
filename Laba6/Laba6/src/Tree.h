#pragma once

#include <iostream>

// Узел дерева
template <typename T>
struct TreeNode {
    T value;
    TreeNode<T>* left;
    TreeNode<T>* right;

    TreeNode(const T& value) : value(value), left(nullptr), right(nullptr) {}
};

// Шаблон класса Tree
template <typename T>
class Tree {
public:
    Tree();
    ~Tree();

    void insert(const T& value);
    TreeNode<T>* find(const T& value);
    void remove(const T& value);
    void preOrderTraversal() const;
    void postOrderTraversal() const;

private:
    TreeNode<T>* root;

    void insertNode(TreeNode<T>*& node, const T& value);
    TreeNode<T>* findNode(TreeNode<T>* node, const T& value);
    void removeNode(TreeNode<T>*& node, const T& value);
    void preOrder(TreeNode<T>* node) const;
    void postOrder(TreeNode<T>* node) const;
    void destroyTree(TreeNode<T>* node);
};

// Глобальный шаблонный метод для симметричного обхода дерева
template <typename T>
void inOrderTraversal(TreeNode<T>* node);


// Конструктор по умолчанию
template <typename T>
Tree<T>::Tree() : root(nullptr) {}

// Деструктор
template <typename T>
Tree<T>::~Tree() {
    destroyTree(root);
}

template <typename T>
void Tree<T>::destroyTree(TreeNode<T>* node) {
    if (node) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

// Метод insert()
template <typename T>
void Tree<T>::insert(const T& value) {
    insertNode(root, value);
}

template <typename T>
void Tree<T>::insertNode(TreeNode<T>*& node, const T& value) {
    if (!node) {
        node = new TreeNode<T>(value);
    }
    else if (value < node->value) {
        insertNode(node->left, value);
    }
    else if (value > node->value) {
        insertNode(node->right, value);
    }
}

// Метод find()
template <typename T>
TreeNode<T>* Tree<T>::find(const T& value) {
    return findNode(root, value);
}

template <typename T>
TreeNode<T>* Tree<T>::findNode(TreeNode<T>* node, const T& value) {
    if (!node || node->value == value) {
        return node;
    }
    else if (value < node->value) {
        return findNode(node->left, value);
    }
    else {
        return findNode(node->right, value);
    }
}

// Метод remove()
template <typename T>
void Tree<T>::remove(const T& value) {
    removeNode(root, value);
}

template <typename T>
void Tree<T>::removeNode(TreeNode<T>*& node, const T& value) {
    if (!node) 
        return;

    if (value < node->value) {
        removeNode(node->left, value);
    }
    else if (value > node->value) {
        removeNode(node->right, value);
    }
    else {
        if (!node->left) {
            TreeNode<T>* temp = node;
            node = node->right;
            delete temp;
        }
        else if (!node->right) {
            TreeNode<T>* temp = node;
            node = node->left;
            delete temp;
        }
        else {
            TreeNode<T>* minNode = node->right;
            while (minNode->left) {
                minNode = minNode->left;
            }
            node->value = minNode->value;
            removeNode(node->right, minNode->value);
        }
    }
}

// Метод preOrderTraversal()
template <typename T>
void Tree<T>::preOrderTraversal() const {
    preOrder(root);
    std::cout << std::endl;
}

template <typename T>
void Tree<T>::preOrder(TreeNode<T>* node) const {
    if (node) {
        std::cout << node->value << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

// Метод postOrderTraversal()
template <typename T>
void Tree<T>::postOrderTraversal() const {
    postOrder(root);
    std::cout << std::endl;
}

template <typename T>
void Tree<T>::postOrder(TreeNode<T>* node) const {
    if (node) {
        postOrder(node->left);
        postOrder(node->right);
        std::cout << node->value << " ";
    }
}