#include <iostream>
#include <random>
#include <ctime>
#include <set>

#include "BinarySearchTree.h"

using namespace std;

int main() {
    auto numbers = new BinarySearchTree<int>();
    auto errors = new vector<string>();

    constexpr std::size_t NSEEDS = 5;
    std::uint32_t seeds[NSEEDS] = {0};

    try {
        std::random_device rdev;
        if (rdev.entropy() < 0.05) throw std::runtime_error("not a random device");
        for (auto &s : seeds) s = rdev();
        std::cout << "seeds generated with a random device\n";
    }
    catch (const std::exception &) {
        std::cout << "no random device / bogus random device / random device has no entropy\n";
        auto t = time(nullptr);
        for (std::size_t i = 0; i < NSEEDS; ++i)
            if (seeds[i] == 0) seeds[i] = t * (i + 3);
    }

    std::seed_seq seed_seq(seeds, seeds + NSEEDS);
    std::mt19937 generator(seed_seq);
    std::uniform_int_distribution<int> dist(1, 100);

    auto * uniqueNums = new set<int>();

    /* Test adding and fill up tree. */
    for (int i = 1; i <= 20; i++) {
        int val = dist(generator);
        uniqueNums->insert(val);
    }

    for (int uniqueNum : *uniqueNums) {
        numbers->Add(uniqueNum);
    }

    cout << "Current weight: " << numbers->Size() << endl;
    cout << "Current height: " << numbers->Height() << endl;
    numbers->PrintLevelOrder();
    cout << endl;

    /* Assert that there are 20 values which were added */
    if (numbers->Size() != uniqueNums->size()) {
        errors->emplace_back("Error: not all numbers have been added.");
    }

    int num = dist(generator);
    numbers->Add(num);
    while (numbers->FindNode(num) == nullptr) {
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

    if (numbers->FindNode(num) != nullptr) {
        errors->emplace_back("Error: value not removed from tree.");
    }

    for (unsigned int i = 0; i < errors->size(); i++) {
        cout << errors->operator[](i) << endl;
    }

    return 0;
}