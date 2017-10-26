//
// Created by jon_m on 10/26/2017.
//

#ifndef BINARYTREES_BINARYSEARCHTREE_H
#define BINARYTREES_BINARYSEARCHTREE_H

#include "BinaryTree.h"

template <class T>
class BinarySearchTree : BinaryTree<T> {
private:
    int size;
    TreeNode<T>* root;

public:
    int Size() override {
        return size;
    }

    int Height() override {
        return 0;
    }

    void Add(T data) override {
        return;
    }

    T Remove(T data) override {
        return nullptr;
    }

    TreeNode<T> *FindNode() override {
        return nullptr;
    }
};


#endif //BINARYTREES_BINARYSEARCHTREE_H
