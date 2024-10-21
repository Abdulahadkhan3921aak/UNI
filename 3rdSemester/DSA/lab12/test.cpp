#include <iostream>
#include "tree.hh"

class AVLTree {
private:
    tree<int> avlTree;

public:
    void insert(int key) {
        avlTree.insert(key);
    }

    void remove(int key) {
        avlTree.erase(key);
    }

    bool search(int key) {
        return avlTree.find(key) != nullptr;
    }

    void print() const {
        print_tree(avlTree.begin(), avlTree.end(), std::cout, [&](int const& i) { return std::to_string(i); });
        std::cout << std::endl;
    }
};

int main() {
    AVLTree avlTree;

    std::cout << "Inserting 50" << std::endl;
    avlTree.insert(50);
    avlTree.print();

    std::cout << "Inserting 30" << std::endl;
    avlTree.insert(30);
    avlTree.print();

    std::cout << "Inserting 70" << std::endl;
    avlTree.insert(70);
    avlTree.print();

    std::cout << "Inserting 20" << std::endl;
    avlTree.insert(20);
    avlTree.print();

    std::cout << "Inserting 40" << std::endl;
    avlTree.insert(40);
    avlTree.print();

    std::cout << "Inserting 60" << std::endl;
    avlTree.insert(60);
    avlTree.print();

    std::cout << "Inserting 50" << std::endl;
    avlTree.insert(50);
    avlTree.print();

    std::cout << "Key 40 found: " << (avlTree.search(40) ? "Yes" : "No") << std::endl;

    std::cout << "Removing 40" << std::endl;
    avlTree.remove(40);
    avlTree.print();

    std::cout << "Key 30 found: " << (avlTree.search(30) ? "Yes" : "No") << std::endl;
    std::cout << "Key 90 found: " << (avlTree.search(90) ? "Yes" : "No") << std::endl;

    avlTree.print();

    return 0;
}
