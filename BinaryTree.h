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
private:
    void PrintInOrder(TreeNode<T> *pNode) {
        if(pNode != nullptr) {
            cout << pNode->GetData() << endl;
            PrintInOrder(pNode->GetLeft());
            PrintInOrder(pNode->GetRight());
        }
    }

    void PrintPreOrder(TreeNode<T> *pNode) {
        if(pNode != nullptr) {
            PrintPreOrder(pNode->GetLeft());
            cout << pNode->GetData() << endl;
            PrintPreOrder(pNode->GetRight());
        }
    }

    void PrintPostOrder(TreeNode<T> *pNode) {
        if(pNode != nullptr) {
            PrintPostOrder(pNode->GetLeft());
            PrintPostOrder(pNode->GetRight());
            cout << pNode->GetData() << endl;
        }
    }

public:
    virtual int Size() = 0;
    virtual int Height() = 0;
    virtual void Add(T data) = 0;
    virtual T Remove(T data) = 0;
    virtual TreeNode<T>* FindNode() = 0;

    void PrintInOrder() {   /* Rt -> L -> R */
        PrintInOrder(root);
    }

    void PrintPreOrder() { /* L -> Rt -> R */
        PrintPreOrder(root);
    }
    void PrintPostOrder() { /* L -> R -> Rt */
        PrintPreOrder(root);
    }
    void PrintLevelOrder() { /* Level-by-level */
        vector<TreeNode<T>*> queue;
        queue.emplace_back(root);
        int size = queue.size();
        while(size == 0) {
            for(TreeNode<T>* node : queue) {
                cout << node->GetData() << "\t";
            }
            for(int i = size; i > 0; i++) {
                queue.erase(queue.front());
            }
            size = queue.size();
        }
    }
};


#endif //BINARYTREES_BINARYTREE_H
