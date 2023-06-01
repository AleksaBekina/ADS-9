// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

template <class T> BST<T>::BST() : root(nullptr) {}

template <class T>
typename BST<T>::BTNode* BST<T>::addBST(BTNode* node, T value) {
    if (node == nullptr)
        node = new BTNode(value);
    else if (value < node->value)
        node->left = addBST(node->left, value);
    else if (value > root->value)
        node->right = addBST(node->right, value);
    else
        node->count++;
    return node;
}

template <class T>
void BST<T>::add(T value) {
    root = addBST(root, value);
}

template <class T>
int BST<T>::depth() {
    if (root == nullptr)
        return 0;
    else {
        int hleft = depth(root->left);
        int hright = depth(root->right);
        return (hleft > hright ? hleft : hright);
    }
}

template <class T>
int BST<T>::searchBST(T value) {
    if (root == nullptr) {
        return 0;
    }
    while (true) {
        if (value > root->value) {
            root = root->right;
        }
        else if (value < root->value) {
            root = root->left;
        }
        else {
            return root->count;
        }
    }
}


BST<std::string> makeTree(const char* filename) {
    std::ifstream file(filename);
    std::string word;
    BST<std::string> binTree;

    if (!file) {
        std::cout << "File error!" << std::endl;
        return binTree;
    }
    
    while (!file.eof()) {
        char s = file.get();
        if ((s >= 'A' && s <= 'Z') || (s >= 'a' && s <= 'z')) {
            word += tolower(s);
        } else {
            binTree.add(word);
            word.clear();
        }  
    }
    file.close();
    return binTree;
