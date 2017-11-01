//
// Created by jon_m on 10/26/2017.
//

#ifndef BINARYTREES_BINARYSEARCHTREE_H
#define BINARYTREES_BINARYSEARCHTREE_H

#include <cmath>
#include <iostream>

#include "BinaryTree.h"

using namespace std;

template<class T>
class BinarySearchTree;

template<class T>
class BinarySearchTree : BinaryTree<T> {
protected:
    TreeNode<T> *root;

/** bool Add(TreeNode node, TreeNode pNode, int currHeight, int maxHeight)
 *
 *  Algorithm
 *      Add a node to the tree. If the node's value exceeds the value of pNode, add to right; if the value is less
 *      than the value of pNode, then add to the left. If it is a duplicate, discard.
 *
 *      --WE DO NOT ALLOW FOR DUPLICATES IN THIS BINARY TREE--
 *
 *      Problem 1: tracking whether a new level has been added at each level. Rather than brute force it and do a
 *          recursive recalculation, it is best to update it in a single recursion. We track whether a new level
 *          has been added by comparing the number of levels we have descended for the addition (currHeight) to the
 *          current height of the tree. If we have descended further than the current height of the tree, then we
 *          have added a new level.
 *
 *      Problem 2: Height and Balance are mutually exclusive. While the balance of a tree is based on the balance of
 *          its subtrees, the height is updated separately from the balance.
 *
 *  @param TreeNode<T>* node - The node we want to add
 *  @param TreeNode<T>* pNode - The node we are currently comparing to
 *  @param int currHeight - Tracker for the number of levels we have traversed
 *  @param int maxHeight - The height of the tree
 * */
bool Add(TreeNode<T> *node, TreeNode<T> *pNode, int currHeight, int maxHeight) {
    if (pNode == nullptr) {
        return false;
    }

    int cmp = node->CompareTo(pNode);
    bool isNewLevel;
    int currLevel;

    if (cmp < 0) {
        cout << "Adding " << node->GetData() << " to left of " << pNode->GetData() << endl;
        if (pNode->GetLeft() != nullptr) {
            currLevel = pNode->GetHeight();
            isNewLevel = Add(node, pNode->GetLeft(), currHeight + 1, maxHeight);

            if (isNewLevel) {
                int leftHeight = pNode->GetLeft()->GetHeight(), rightHeight = 0;
                if (pNode->GetRight() != nullptr) {
                    rightHeight = pNode->GetRight()->GetHeight();
                }
                pNode->ResetHeight();
                pNode->AddHeight(max(rightHeight, leftHeight));
            }

            return currLevel <= pNode->GetHeight();
        } else {
            pNode->SetLeft(node);
            node->SetParent(pNode);

            for (TreeNode<T> *temp = pNode; temp != nullptr; temp = temp->GetParent()) {
                cout << temp->GetData() << ".weight++" << endl;
                temp->IncWeight();
            }

            return pNode->GetRight() == nullptr;
        }
    } else if (cmp > 0) {
        cout << "Adding " << node->GetData() << " to right of " << pNode->GetData() << endl;
        if (pNode->GetRight() != nullptr) {
            currLevel = pNode->GetHeight();
            isNewLevel = Add(node, pNode->GetRight(), currHeight + 1, maxHeight);

            if (isNewLevel) {
                int leftHeight = 0, rightHeight = pNode->GetRight()->GetHeight();
                if (pNode->GetLeft() != nullptr) {
                    leftHeight = pNode->GetLeft()->GetHeight();
                }
                pNode->ResetHeight();
                pNode->AddHeight(max(leftHeight, rightHeight));
            }

            return currLevel <= pNode->GetHeight();
        } else {
            pNode->SetRight(node);
            node->SetParent(pNode);

            for (TreeNode<T> *temp = pNode; temp != nullptr; temp = temp->GetParent()) {
                cout << temp->GetData() << ".weight++" << endl;
                temp->IncWeight();
            }

            return pNode->GetLeft() == nullptr;
        }
    } else {
        return false;
    }
}

private:

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

    /* Actual Functions */

    T RemoveCaseZero(TreeNode<T> *node, bool isLeft, TreeNode<T> *parent) {
        if (isLeft) {
            parent->SetLeft(nullptr);
        } else {
            parent->SetRight(nullptr);
        }
        node->SetParent(nullptr);
    }

    T RemoveCaseOne(TreeNode<T> *node, bool isLeft, TreeNode<T> *parent) {
        if (left) {
            parent->SetLeft(node->GetLeft());
        } else {
            parent->SetRight(node->GetLeft());
        }
        node->GetLeft()->SetParent(parent);

        node->SetLeft(nullptr);
        node->SetParent(nullptr);
    }

    T RemoveCaseTwo(TreeNode<T> *node, bool isLeft, TreeNode<T> *parent) {
        if (left) {
            parent->SetLeft(node->GetRight());
        } else {
            parent->SetRight(node->GetRight());
        }
        node->GetRight()->SetParent(parent);

        node->SetParent(nullptr);
        node->SetRight(nullptr);
    }

    void Swap(TreeNode<T> *node1, TreeNode<T> *node2) {
        TreeNode<T> *temp = new TreeNode<T>(node1);

        node1->SetLeft(node2->GetLeft());
        node1->SetRight(node2->GetRight());
        node1->SetParent(node2->GetParent());

        node2->SetLeft(temp->GetLeft());
        node2->SetRight(temp->GetRight());
        node2->SetParent(temp->GetParent());
    }

    int CountNodes(TreeNode<T> *pNode) {
        if (pNode == nullptr) {
            return 0;
        }
        return 1 + CountNodes(pNode->GetLeft()) + CountNodes(pNode->GetRight());
    }

    TreeNode<T> *FindNode(T data, TreeNode<T> *node) override {
        if (node == nullptr) {
            return nullptr;
        }

        int cmp = (new TreeNode<T>(data))->CompareTo(node);

        if (cmp > 0) {
            return FindNode(data, node->GetRight());
        } else if (cmp < 0) {
            return FindNode(data, node->GetLeft());
        } else {
            return node;
        }
    }

public:
    explicit BinarySearchTree() {
        root = nullptr;
    }

    explicit BinarySearchTree(T data) {
        root = new TreeNode<T>(data);
    }

    explicit BinarySearchTree(TreeNode<T> *root) {
        this->root = root;
    }

    int Size() override {
        return root->GetWeight();
    }

    int Height() override {
        return root->GetHeight();
    }

    /** Add(T data)
     *
     *  Function Requirements
     *      What do we want? We want to add in a node. When adding in a node, we need to update our height, and we need
     *      to keep track of whether or not we have added a new level to any subtree we inhabit up the tree.
     *
     *      This is the user-facing Add function, so the deep algorithm will not be detailed here. Instead we add to the
     *      tree if it is not empty, or set the tree if it is.
     *
     *  @param T - the data we are adding to the tree
     * */
    TreeNode<T>* Add(T data) override {
        if (root != nullptr) {
            TreeNode<T> *node = new TreeNode<T>(data);
            bool newLevel = Add(node, root, 1, root->GetHeight());
            if (newLevel) root->IncHeight();
            return node;
        } else {
            root = new TreeNode<T>(data);
            return root;
        }
    }

    T Remove(T data) override {
        T retData;
        TreeNode<T> *node = FindNode(data, root);

        if (node == nullptr) {
            return 0;
        }
        TreeNode<T> *parent = node->GetParent();

        bool isLeft = node == parent->GetLeft();

        if (node->GetLeft() == nullptr && node->GetRight() == nullptr) {
            retData = RemoveCaseZero(node, isLeft, parent);
        } else if (node->GetLeft() != nullptr && node->GetRight() == nullptr) {
            retData = RemoveCaseOne(node, isLeft, parent);
        } else if (node->GetLeft() == nullptr && node->GetRight() != nullptr) {
            retData = RemoveCaseTwo(node, isLeft, parent);
        } else {
            TreeNode<T> *temp = node->GetRight();

            while (temp->GetLeft() != nullptr) {
                temp = temp->GetLeft();
            }

            Swap(node, temp);
            parent = node->GetParent();
            if (node->GetRight() != nullptr) {
                retData = RemoveCaseTwo(node, true, parent);
            } else {
                retData = RemoveCaseZero(node, true, parent);
            }
        }

        while (parent != nullptr) {
            parent->ResetWeight();
            int rightHeight = 0, leftHeight = 0;

            if (parent->GetRight() != nullptr) {
                parent->AddWeight(parent->GetRight()->GetWeight());
                rightHeight = parent->GetRight()->GetHeight();
            }
            if (parent->GetLeft() != nullptr) {
                parent->AddWeight(parent->GetLeft()->GetWeight());
                leftHeight = parent->GetLeft()->GetHeight();
            }

            parent->ResetHeight();
            parent->AddHeight(max(rightHeight, leftHeight));

            parent = parent->GetParent();
        }

        return retData;
    }

    virtual TreeNode<T> *FindNode(T data) {
        return FindNode(data, root);
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
                if (node->GetLeft() != nullptr) {
                    queue.emplace_back(node->GetLeft());
                }
                if (node->GetRight() != nullptr) {
                    queue.emplace_back(node->GetRight());
                }
            }
            cout << endl;
            for (int i = 0; i < size; i++) {
                auto front = (vector<TreeNode<int> *>::const_iterator) queue.begin();
                queue.erase(front);
            }
            size = queue.size();
        }
    }

    bool IsBalanced(TreeNode<T> *pNode) {
        if (pNode == nullptr) {
            return true;
        }
        return abs(root->GetLeft()->GetHeight() - root->GetRight()->GetHeight()) < 2 &&
               IsBalanced(pNode->GetLeft()) && IsBalanced(pNode->GetRight());

    }

    bool IsBalanced() override {
        if (root == nullptr) {
            return true;
        }
        return abs(root->GetLeft()->GetHeight() - root->GetRight()->GetHeight()) < 2 &&
               IsBalanced(root->GetLeft()) && IsBalanced(root->GetRight());
    }
};


#endif //BINARYTREES_BINARYSEARCHTREE_H
