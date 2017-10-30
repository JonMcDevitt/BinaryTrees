#include <iostream>
#include <random>

#include "BinarySearchTree.h"

using namespace std;

int main() {
    auto numbers = new BinarySearchTree<int>();
    auto errors = new vector<string>();

    random_device m_seed;
    mt19937 generator(m_seed());
    uniform_int_distribution<int> dist(1, 100);

    /* Test adding and fill up tree. */
    cout << "Adding to tree" << endl;
    for(int i = 1; i <= 20; i++) {
        int val = dist(generator);
        numbers->Add(val);
    }

    cout << "Done adding" << endl;

    numbers->PrintLevelOrder();

    /* Assert that there are 20 values which were added */
    if(numbers->Size() != 20) {
        errors->emplace_back("Error: not all numbers have been added.");
    }

    for(unsigned int i = 0; i < errors->size(); i++) {
        cout << errors->operator[](i) << endl;
    }

    return 0;
}