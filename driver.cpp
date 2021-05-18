#include "bs_tree.h"

int main() {
    bs_tree tree;

    //test add function and search function
    tree.add(20);
    tree.add(10);
    tree.add(30);
    tree.add(5);
    tree.add(8);
    tree.add(25);
    tree.add(40);
    tree.inorder_traversal(tree.get_root());

    //test remove function
    tree.remove(40);

    return 0;
}