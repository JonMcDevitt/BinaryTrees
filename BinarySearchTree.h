//
// Created by jon_m on 10/26/2017.
//

#ifndef BINARYTREES_BINARYSEARCHTREE_H
#define BINARYTREES_BINARYSEARCHTREE_H

#include <cmath>

#include "BinaryTree.h"

template<class T>
class BinarySearchTree : BinaryTree<T> {
private:
    int size;
    TreeNode<T> *root;

    int Height(TreeNode<T> *node) {
        if (node == nullptr) {
            return 0;
        }
        return 1 + max(Height(node->GetLeft()), Height(node->GetRight()));
    }

    /* Traversals */
    void PrintInOrder(TreeNode<T> *pNode) {
        if (pNode != nullptr) {
            cout << pNode->GetData() << endl;
            PrintInOrder(pNode->GetLeft());
            PrintInOrder(pNode->GetRight());
        }
    }

    void PrintPreOrder(TreeNode<T> *pNode) {
        if (pNode != nullptr) {
            PrintPreOrder(pNode->GetLeft());
            cout << pNode->GetData() << endl;
            PrintPreOrder(pNode->GetRight());
        }
    }

    void PrintPostOrder(TreeNode<T> *pNode) {
        if (pNode != nullptr) {
            PrintPostOrder(pNode->GetLeft());
            PrintPostOrder(pNode->GetRight());
            cout << pNode->GetData() << endl;
        }
    }

    /* We do not allow for duplicates when adding */
    void Add(TreeNode<T>* node, TreeNode<T> *pNode) {

        int cmp = node->CompareTo(pNode);

        if (cmp < 0) {
            if (pNode->GetLeft() != nullptr) {
                Add(node, pNode->GetLeft());
            } else {
                node->SetParent(pNode);
                pNode->SetLeft(node);
                size++;
            }
        } else if (cmp > 0) {
            if (pNode->GetRight() != nullptr) {
                Add(node, pNode->GetRight());
            } else {
                node->SetParent(pNode);
                pNode->SetRight(node);
                size++;
            }
        } else {
            cout << "Duplicate value entered." << endl;
        }
    }

    T RemoveCaseZero(TreeNode<T>* node, bool isLeft, TreeNode<T>* parent) {
        if(left) {
            parent->SetLeft(nullptr);
        } else {
            parent->SetRight(nullptr);
        }
        node->SetParent(nullptr);
    }

    T RemoveCaseOne(TreeNode<T>* node, bool isLeft, TreeNode<T>* parent) {
        if(left) {
            parent->SetLeft(node->GetLeft());
        } else {
            parent->SetRight(node->GetLeft());
        }
        node->GetLeft()->SetParent(parent);

        node->SetLeft(nullptr);
        node->SetParent(nullptr);
    }

    T RemoveCaseTwo(TreeNode<T>* node, bool isLeft, TreeNode<T>* parent) {
        if(left) {
            parent->SetLeft(node->GetRight());
        } else {
            parent->SetRight(node->GetRight());
        }
        node->GetRight()->SetParent(parent);

        node->SetParent(nullptr);
        node->SetRight(nullptr);
    }

    void Swap(TreeNode<T>* node1, TreeNode<T>* node2) {
        TreeNode<T>* temp = new TreeNode<T>(node1);

        node1->SetLeft(node2->GetLeft());
        node1->SetRight(node2->GetRight());
        node1->SetParent(node2->GetParent());

        node2->SetLeft(temp->GetLeft());
        node2->SetRight(temp->GetRight());
        node2->SetParent(temp->GetParent());
    }

public:
    explicit BinarySearchTree() {
        root = nullptr;
        size = 0;
    }

    explicit BinarySearchTree(T data) {
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
        if (root != nullptr) {
            TreeNode<T>* node = new TreeNode<T>(data);
            Add(node, root);
        } else {
            root = new TreeNode<T>(data);
            size++;
        }
    }

    T Remove(T data) override {
        TreeNode<T> *node = FindNode(data, root);

        /* Data not found */
        if (node == nullptr) {
            return 0;
        }

        TreeNode<T>* parent = node->GetParent();

        /* Is it the left or right child? */
        bool left = (node == parent->GetLeft());

        /* Cases */
        /* Case 0: node has no children */
        if(node->GetLeft() == nullptr && node->GetRight() == nullptr) {
            RemoveCaseZero(node, left, parent);
        }

        /* Case 1: node has only a left child */
        if(node->GetLeft() != nullptr && node->GetRight() == nullptr) {
            RemoveCaseOne(node, left, parent);
        }

        /* Case 2: node has only a right child */
        if(node->GetLeft() == nullptr && node->GetRight() != nullptr) {
            RemoveCaseTwo(node, left, parent);
        }

        /* Case 3: node has a left and right child */
        if(node->GetLeft() != nullptr && node->GetRight() != nullptr) {
            TreeNode<T>* min = node->GetRight()->GetLeft();
            while(min->GetLeft() != nullptr) min = min->GetLeft();

            Swap(node, min);
            parent = node->GetParent();
            if(node->GetLeft() == nullptr) {
                if(node->GetRight() == nullptr) {
                    return RemoveCaseZero(node, true, parent);
                }
            }
        }
    }

    TreeNode<T> *FindNode(T data, TreeNode<T> *node) override {
        int cmp = data == node->GetData();

        if (cmp > 0) {
            return FindNode(data, node->GetRight());
        } else if (cmp < 0) {
            return FindNode(data, node->GetLeft());
        } else {
            return node;
        }
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
        vector<TreeNode<T> *> queue;
        queue.emplace_back(root);
        int size = queue.size();
        while (size != 0) {
            for (TreeNode<T> *node : queue) {
                cout << node->GetData() << "\t";
                if(node->GetLeft() != nullptr) {
                    queue.emplace_back(node->GetLeft());
                }
                if(node->GetRight() != nullptr) {
                    queue.emplace_back(node->GetRight());
                }
            }
            cout << endl;
            for(int i = 0; i < size; i++) {
                auto front = (vector<TreeNode<int>*>::const_iterator)queue.begin();
                queue.erase(front);
            }
            size = queue.size();
        }
    }

    bool IsBalanced() override {
        return false;
    }
};


#endif //BINARYTREES_BINARYSEARCHTREE_H
