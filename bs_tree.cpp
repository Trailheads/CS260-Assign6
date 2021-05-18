#include "bs_tree.h"
#include <iostream>

bs_tree::bs_tree() {
    root = nullptr;
}


bs_tree::~bs_tree() {

}


void bs_tree::add(const int new_value) {
    if(root == nullptr) {
        root->set_root(&root, new_value);
    }
    else {
        bs_tree_node * current = root;
        bs_tree_node * save_prev;

        while(current != nullptr) {
            save_prev = current;

            if(new_value <= current->get_value()) {
                current = current->get_left();
            }
            else {
                current = current->get_right();
            }
        }

        if(new_value <= save_prev->get_value()) {
            save_prev->set_left(new_value);
        }
        else {
            save_prev->set_right(new_value);
        }
    }
}


void bs_tree::remove(const int old_value) {
    if(root == nullptr) {
        std::cout << "A tree is not formed, its root needs to be assigned." << std::endl;
        return;
    }

    bs_tree_node * current = root;
    bs_tree_node * save_prev = root;
    find_node(old_value, &current, &save_prev);

    bs_tree_node * remove_node = current; 
    bs_tree_node * save_left = remove_node->get_left();
    bs_tree_node * save_right = remove_node->get_right();
    find_successor(old_value, current);

    
    //connect successor node to parent node
    if(current->get_value() <= save_prev->get_value()) {
        *save_prev->get_left() = *current;
    }
    else {
        *save_prev->get_right() = *current;
    }
    
    //connect removed node's children to successor
    *current->get_left() = *save_left;
    *current->get_right() = *save_right;

    delete remove_node;
}


void bs_tree::find_node(const int old_value, bs_tree_node** current, bs_tree_node** save_prev) {
    while((*current)->get_value() != old_value || current == nullptr) {
        save_prev = current;

        if(old_value <= (*current)->get_value() ) {
            *current = (*current)->get_left();
        }
        else {
            *current = (*current)->get_right();
        }
    }

    if(current == nullptr) {
        std::cout << "\nThe value '" << old_value << "' is not in the tree." << std::endl;
        return;
    }
}


void bs_tree::find_successor(const int old_value, bs_tree_node* current) {
    //Check if the current node is a leaf
    if(current->get_left() == nullptr && current->get_right() == nullptr) {
        return;
    }

    while(current != nullptr) {
        //Check if the old_value is to the left of the root, then rightmost leaf is successor
        if(current->get_value() < root->get_value()) {
            current = current->get_right();
        }

        //Check if the old_value is to the right of the root, then leftmost lead is successor
        if(current->get_value() > root->get_value()) {
            current = current->get_left();
        }
    }
}


void bs_tree::inorder_traversal(bs_tree_node *current) {
    if(current->get_left() != nullptr) {
        inorder_traversal(current->get_left());
    }
    
    std::cout << current->get_value() << std::endl;

    if(current->get_right() != nullptr) {
        inorder_traversal(current->get_right());
    }
}


bs_tree_node* bs_tree::get_root() const {
    return root;
}