//
// Created by jon_m on 10/26/2017.
//

#ifndef BINARYTREES_BINARYTREE_H
#define BINARYTREES_BINARYTREE_H

#include <iostream>
#include <vector>

#include "TreeNode.h"

using namespace std;

template <class T>
class BinaryTree {
protected:
public:
    virtual int Size() = 0;
    virtual int Height() = 0;
    virtual void Add(T data) = 0;
    virtual T Remove(T data) = 0;
    virtual TreeNode<T>* FindNode(T data, TreeNode<T>* node) = 0;
    virtual bool IsBalanced() = 0;

    /* Traversals */
    virtual void PrintInOrder() = 0;
    virtual void PrintPreOrder() = 0;
    virtual void PrintPostOrder() = 0;
    virtual void PrintLevelOrder() = 0;
};


#endif //BINARYTREES_BINARYTREE_H
