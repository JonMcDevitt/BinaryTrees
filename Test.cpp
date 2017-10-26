#include <iostream>
#include <random>
#include <ctime>

#include "BinarySearchTree.h"

using namespace std;

int main() {
    BinarySearchTree<int> *numbers= new BinarySearchTree<int>();
    auto errors = new vector<string>();

    srand((unsigned)time(0));
    random_device device;
    mt19937 mt(device);
    uniform_int_distribution<int> dist(1, 100);

    /* Test adding and fill up tree. */
    for(int i = 1; i <= 20; i++) {
        numbers->Add(dist(mt));
    }

    /* Assert that there are 20 values which were added */
    if(numbers->Size() != 20) {
        errors->emplace_back("Error: not all numbers have been added.");
    }


    return 0;
}