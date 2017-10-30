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
    for(int i = 1; i <= 20; i++) {
        int val = dist(generator);
        numbers->Add(val);
    }

    numbers->PrintLevelOrder();
    cout << endl;

    /* Assert that there are 20 values which were added */
    if(numbers->Size() != 20) {
        errors->emplace_back("Error: not all numbers have been added.");
    }

    int num = dist(generator);
    numbers->Add(num);
    while(numbers->FindNode(num) == nullptr) {
        num = dist(generator);
        numbers->Add(num);
    }

    cout << "Current weight: " << numbers->Size() << endl;
    cout << "Current height: " << numbers->Height() << endl;
    numbers->PrintLevelOrder();
    cout << endl;

    numbers->Remove(num);

    cout << "Current weight: " << numbers->Size() << endl;
    cout << "Current height: " << numbers->Height() << endl;
    numbers->PrintLevelOrder();
    cout << endl;

    if(numbers->FindNode(num) != nullptr) {
        errors->emplace_back("Error: value not removed from tree.");
    }

    for(unsigned int i = 0; i < errors->size(); i++) {
        cout << errors->operator[](i) << endl;
    }

    return 0;
}