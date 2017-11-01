cmake_minimum_required(VERSION 3.8)
project(BinaryTrees)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Test.cpp TreeNode.h BinaryTree.h BinarySearchTree.h RBT/RedBlackTree.h RBT/RBTNode.h)
add_executable(BinaryTrees ${SOURCE_FILES})