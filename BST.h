#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

#include <iostream>
#include "Vector.h"

template <class T>
class Bst
{
public:
    Bst();
    ~Bst();
    Bst(const Bst& other);
    Bst& operator=(const Bst& other);
    void insert(const T& value);
    void deleteValue(const T& value);
    bool search(const T& value) const;
    void inOrder(void (*visit)(const T&)) const;
    void preOrder(void (*visit)(const T&)) const;
    void postOrder(void (*visit)(const T&)) const;
    T getData(const T& searchKey) const;
    const Vector<T>& getAll() const;

private:
    struct Node {
        T data;
        Node* left;
        Node* right;

        Node(const T &value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root;

    void insertHelper(Node*& node, const T& value);
    void deleteHelper(Node*& node, const T& value);
    void deleteTree(Node*& node);

    bool searchHelper(const Node* const& node, const T& value) const;
    void inOrderHelper(const Node* const& node, void (*visit)(const T&)) const;
    void preOrderHelper(const Node* const& node, void (*visit)(const T&)) const;
    void postOrderHelper(const Node* const& node, void (*visit)(const T&)) const;

    Node* copyHelper(const Node* const& node)const;
    Node* findMin(Node*& node);
    Node* returnData(const Node* const& node, const T& searchKey) const;
    void toVector(const Node* const& node, Vector<T>& result) const;
};


template <class T>
Bst<T>::Bst() : root(nullptr) {}

template <class T>
Bst<T>::~Bst()
{
    deleteTree(root);
}

template <class T>
void Bst<T>::deleteTree(Node*& node)
{
    if (node == nullptr) {
        return;
    }
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
    node = nullptr;
}

template <class T>
Bst<T>::Bst(const Bst<T>& other)
{
    root = copyHelper(other.root);
}

template <class T>
typename Bst<T>::Node* Bst<T>::copyHelper(const Node* const& node) const
{
    if (node == nullptr) {
        return nullptr;
    }
    Node* newNode = new Node(node->data);
    newNode->left = copyHelper(node->left);
    newNode->right = copyHelper(node->right);
    return newNode;
}

template <class T>
Bst<T>& Bst<T>::operator=(const Bst<T>& other)
{
    if (this != &other) {
        deleteTree(root);
        root = copyHelper(other.root);
    }
    return *this;
}

template <class T>
void Bst<T>::insertHelper(Node*& node, const T& value)
{
    if (node == nullptr) {
        node = new Node(value);
        return;
    }

    if (value < node->data) {
        insertHelper(node->left, value);
    } else if (value > node->data) {
        insertHelper(node->right, value);
    }
    // If equal, don't insert (no duplicates)
}

template <class T>
void Bst<T>::insert(const T& value)
{
    insertHelper(root, value);
}

template <class T>
void Bst<T>::deleteHelper(Node*& node, const T& value)
{
    if (node == nullptr) {
        return;
    }

    if (value < node->data) {
        deleteHelper(node->left, value);
    } else if (value > node->data) {
        deleteHelper(node->right, value);
    } else {
        //no child
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            node = nullptr;
        }
        //a child on right
        else if (node->left == nullptr) {
            Node* temp = node;
            node = node->right;
            delete temp;
        }
        // a child on left
        else if (node->right == nullptr) {
            Node* temp = node;
            node = node->left;
            delete temp;
        }
        // 2 children
        else {
            Node* minRight = findMin(node->right);
            node->data = minRight->data;
            deleteHelper(node->right, minRight->data);
        }
    }
}

template <class T>
void Bst<T>::deleteValue(const T& value)
{
    deleteHelper(root, value);
}

template <class T>
typename Bst<T>::Node* Bst<T>::findMin(Node*& node)
{
    if (node->left == nullptr) {
        return node;
    }
    return findMin(node->left);
}

template <class T>
bool Bst<T>::searchHelper(const Node* const& node, const T& value) const
{
    if (node == nullptr) {
        return false;
    }

    if (value == node->data) {
        return true;
    } else if (value < node->data) {
        return searchHelper(node->left, value);
    } else {
        return searchHelper(node->right, value);
    }
}

template <class T>
bool Bst<T>::search(const T& value) const
{
    return searchHelper(root, value);
}

template <class T>
void Bst<T>::inOrderHelper(const Node* const& node, void (*visit)(const T&)) const
{
    if (node == nullptr) return;
    inOrderHelper(node->left, visit);
    visit(node->data);
    inOrderHelper(node->right, visit);
}

template <class T>
void Bst<T>::inOrder(void (*visit)(const T&)) const
{
    inOrderHelper(root, visit);
}

template <class T>
void Bst<T>::preOrderHelper(const Node* const& node, void (*visit)(const T&)) const
{
    if (node == nullptr) return;
    visit(node->data);
    preOrderHelper(node->left, visit);
    preOrderHelper(node->right, visit);
}

template <class T>
void Bst<T>::preOrder(void (*visit)(const T&)) const
{
    preOrderHelper(root, visit);
}

template <class T>
void Bst<T>::postOrderHelper(const Node* const& node, void (*visit)(const T&)) const
{
    if (node == nullptr) return;
    postOrderHelper(node->left, visit);
    postOrderHelper(node->right, visit);
    visit(node->data);
}

template <class T>
void Bst<T>::postOrder(void (*visit)(const T&)) const
{
    postOrderHelper(root, visit);
}

template <class T>
typename Bst<T>::Node* Bst<T>::returnData(const Node* const& node, const T& searchKey) const
{
    if (node == nullptr) {
        return nullptr;
    }

    if (searchKey == node->data) {
        return node;
    }

    if (searchKey < node->data) {
        return returnData(node->left, searchKey);
    } else if (searchKey > node->data) {
        return returnData(node->right, searchKey);
    }
}

template <class T>
T Bst<T>::getData(const T& searchKey) const
{
    Node* node= returnData(root, searchKey);
    return node->data;

}
template <class T>
void Bst<T>::toVector(const Node* const& node, Vector<T>& result) const
{
    if (node == nullptr) {
        return;
    }
    toVector(node->left, result);
    result.addRecord(node->data);
    toVector(node->right, result);
}

template <class T>
const Vector<T>& Bst<T>::getAll() const
{
    static Vector<T> result;
    toVector(root, result);
    return result;
}

#endif // BST_H_INCLUDED
