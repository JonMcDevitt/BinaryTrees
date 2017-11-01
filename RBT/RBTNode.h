//
// Created by jon_m on 11/1/2017.
//

#ifndef BINARYTREES_RBTNODE_H
#define BINARYTREES_RBTNODE_H

#include "../TreeNode.h"

template<class T>
class RBTNode : public TreeNode<T> {
private:
    enum class Colour {
        BLACK,
        RED
    };

    Colour colour;

public:
    explicit RBTNode() : TreeNode() {
        colour = Colour::RED;
    }

    explicit RBTNode(T data) : TreeNode(data) {
        colour = Colour::RED;

        RBTNode<T>* left = new RBTNode<T>();
        RBTNode<T>* right = new RBTNode<T>();

        SetLeft(left);
        SetRight(right);

        left->SetParent(this);
        left->SwapColour();
        right->SetParent(this);
        right->SwapColour();
    }

    explicit RBTNode(T data, bool colour) : TreeNode(data) {
        this->colour = (colour) ? Colour::BLACK : Colour::RED;
    }

    explicit RBTNode(RBTNode<T>* node) : TreeNode(node) {
        this->colour = node->colour;
    }

    bool IsBlack() {
        return (colour == Colour::BLACK);
    }

    void SwapColour() {
        colour = (colour == Colour::BLACK) ? Colour::RED : Colour::BLACK;
    }
};


#endif //BINARYTREES_RBTNODE_H
