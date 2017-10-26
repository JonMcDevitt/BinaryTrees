//
// Created by jon_m on 10/26/2017.
//

#ifndef BINARYTREES_BINARYSEARCHTREE_H
#define BINARYTREES_BINARYSEARCHTREE_H

#include <cmath>

#include "BinaryTree.h"

template <class T>
class BinarySearchTree : BinaryTree<T> {
private:
    int size;
    TreeNode<T>* root;

    int Height(TreeNode<T>* node) {
        if(node == nullptr) {
            return 0;
        }
        return 1 + max(Height(node->GetLeft()), Height(node->GetRight()));
    }

    /* Traversals */
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

    /* We do not allow for duplicates when adding */
    void Add(T data, TreeNode<T> *pNode) {
        TreeNode<T>* node = new TreeNode<T>(data);

        int cmp = node->CompareTo(pNode);

        if(cmp < 0) {
            if(node->GetLeft() != nullptr) {
                Add(data, node->GetLeft());
            } else {
                node->SetParent(pNode);
                pNode->SetLeft(node);
                size++;
            }
        } else if (cmp > 0) {
            if(node->GetRight() != nullptr) {
                Add(data, node->GetRight());
            } else {
                node->SetParent(pNode);
                pNode->SetRight(node);
            }
        }
    }
public:
    explicit BinarySearchTree<T>() {
        root = nullptr;
        size = 0;
    }

    explicit BinarySearchTree<T>(T data) {
        root = new TreeNode<T>(data);
        size = 1;
    }

    int Size() override {
        return size;
    }

    int Height() override {
        return Height(root);
    }

    void Add(T data) override {
        if(root != nullptr) {
            Add(data, root);
        } else {
            root = new TreeNode<T>(data);
        }
    }

    T Remove(T data) override {
        return nullptr;
    }

    TreeNode<T> *FindNode() override {
        return nullptr;
    }

    /* Traversals */
    void PrintInOrder() override {   /* Rt -> L -> R */
        PrintInOrder(root);
    }

    void PrintPreOrder() override { /* L -> Rt -> R */
        PrintPreOrder(root);
    }

    void PrintPostOrder() override { /* L -> R -> Rt */
        PrintPreOrder(root);
    }

    void PrintLevelOrder() override { /* Level-by-level */
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


#endif //BINARYTREES_BINARYSEARCHTREE_H
