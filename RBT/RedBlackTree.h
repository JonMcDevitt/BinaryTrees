//
// Created by jon_m on 11/1/2017.
//

#ifndef BINARYTREES_REDBLACKTREE_H
#define BINARYTREES_REDBLACKTREE_H

#include "../BinarySearchTree.h"
#include "RBTNode.h"

template<class T>
class RedBlackTree : public BinarySearchTree<T> {
private:
    RBTNode<T> *FindNode(T data, RBTNode<T> *pNode) {
        int cmp;
        RBTNode<T> *node = new RBTNode<T>(data);
        while (pNode->GetData() != NULL) {
            cmp = node->CompareTo(pNode);
            if (cmp < 0) {
                pNode = static_cast<RBTNode<T> *>(pNode->GetLeft());
            } else if (cmp > 0) {
                pNode = static_cast<RBTNode<T> *>(pNode->GetRight());
            } else {
                return pNode;
            }
        }

        /* Not found */
        return nullptr;
    }

public:
    RedBlackTree() {
        root = new RBTNode<T>();
        static_cast<RBTNode<T> *>(root)->SwapColour();
    }

    void FixBalance(RBTNode<T> *pNode) {

    }

    void Insert(RBTNode<T> *node, RBTNode<T> *pNode) {
        int cmp;
        while (pNode->GetData() != NULL) {
            cmp = node->CompareTo(pNode);

            if (cmp < 0) {
                pNode = static_cast<RBTNode<T> *>(pNode->GetLeft());
            } else if (cmp > 0) {
                pNode = static_cast<RBTNode<T> *>(pNode->GetRight());
            } else {
                /* Found data therefore duplicate therefore invalid */
                return;
            }
        }

        /* Reached a black leaf */
        bool isLeft = pNode->GetParent()->GetLeft()->CompareTo(pNode) == 0;

        if (isLeft) {
            pNode->GetParent()->SetLeft(node);
        } else {
            pNode->GetParent()->SetRight(node);
        };

        node->SetParent(pNode->GetParent());
        pNode->SetParent(nullptr);
    }

    void Insert(T data) {
        if (root != nullptr) {
            RBTNode<T> *node = new RBTNode<T>(data);
            Insert(node, static_cast<RBTNode<T> *>(root));
            FixBalance(node);
        } else {
            root = new RBTNode(data);
        }
    }

    void Delete(T data) {
        RBTNode<T> *node = FindNode(data);

        /* Do deletion stuff */
    }

    RBTNode<T> *FindNode(T data) override {
        return FindNode(data, static_cast<RBTNode<T> *>(root));
    }
};


#endif //BINARYTREES_REDBLACKTREE_H
