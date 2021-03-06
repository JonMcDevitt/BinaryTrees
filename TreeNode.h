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
    int height; /* The number of levels our subtree goes down */
    int weight; /* The combined weights of our subtrees and ourselves */

public:
    explicit TreeNode(T data) {
        this->data = data;
        left = right = parent = nullptr;
        height = 1;
        weight = 1;
    }

    explicit TreeNode(TreeNode<T>* node) {
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

    int GetHeight() const {
        return height;
    }

    int GetWeight() const {
        return weight;
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

    void IncWeight() {
        weight++;
    }

    void IncHeight() {
        height++;
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
        if(data < node->data) {
            return -1;
        } else if(data > node->data) {
            return 1;
        }
        return 0;
    }

    void DecWeight() {
        weight--;
    }

    void ResetWeight() {
        weight = 1;
    }

    void AddWeight(int num) {
        weight += num;
    }

    void ResetHeight() {
        height = 1;
    }

    void AddHeight(int num) {
        height += num;
    }
};


#endif //BINARYTREES_TREENODE_H
