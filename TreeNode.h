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
    explicit TreeNode<T>(T data) : T(data) {
        left = right = parent = nullptr;
    }

    explicit TreeNode<T>(TreeNode<T>* node) {
        left = node->GetLeft();
        right = node->GetRight();
        parent = node->GetParent();
        data = node->GetData();
    }

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

    void SetData(T data) {
        this->data = data;
    }

    void SetLeft(TreeNode<T>* left) {
        this->left = left;
    }

    void SetRight(TreeNode<T>* right) {
        this->right = right;
    }

    void SetParent(TreeNode<T>* parent) {
        this->parent = parent;
    }

    bool operator == (const TreeNode<T>* node) const {
        return this->data == node->data;
    }

    bool operator <= (const TreeNode<T>* node) {
        return this->data <= node->data;
    }

    bool operator >= (const TreeNode<T>* node) {
        return this->data >= node->data;
    }

    bool operator < (const TreeNode<T>* node) {
        return this->data < node->data;
    }

    bool operator > (const TreeNode<T>* node) {
        return this->data > node->data;
    }

    int CompareTo(TreeNode<T>* node) {
        if(this < node) {
            return -1;
        } else if(this > node) {
            return 1;
        }
        return 0;
    }
};


#endif //BINARYTREES_TREENODE_H
