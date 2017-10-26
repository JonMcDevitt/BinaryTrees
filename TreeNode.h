//
// Created by jon_m on 10/26/2017.
//

#ifndef BINARYTREES_TREENODE_H
#define BINARYTREES_TREENODE_H

template <class T>
class TreeNode {
private:
    T data;
    TreeNode<T> *left, *right, *parent;

public:
    TreeNode<T>* GetLeft() {
        return left;
    }

    TreeNode<T>* GetRight() {
        return right;
    }

    TreeNode<T>* GetParent() {
        return parent;
    }

    T GetData() {
        return data;
    }

    void setData(T data) {
        this->data = data;
    }

    void setLeft(TreeNode<T>* left) {
        this->left = left;
    }

    void setRight(TreeNode<T>* right) {
        this->right = right;
    }

    void setParent(TreeNode<T>* parent) {
        this->parent = parent;
    }
};


#endif //BINARYTREES_TREENODE_H
