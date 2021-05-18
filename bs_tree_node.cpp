#include "bs_tree_node.h"
#include <iostream>


bs_tree_node::bs_tree_node() {
    value = 0;
    left = nullptr;
    right = nullptr;
}


bs_tree_node::~bs_tree_node() {

}


void bs_tree_node::set_value(const int new_value) {
    this->value = new_value;
}


int bs_tree_node::get_value() const {
    return value;
}


void bs_tree_node::set_root(bs_tree_node** root, const int new_value) {
    *root = new bs_tree_node;
    (*root)->set_value(new_value);
}


void bs_tree_node::set_left(const int new_value) {
    bs_tree_node *new_node = new bs_tree_node;
    new_node->set_value(new_value);
    this->left = new_node;
}


bs_tree_node* bs_tree_node::get_left() const {
    if(left == nullptr) {
        return nullptr;
    }
    else {
        return left;
    }
}


void bs_tree_node::set_right(const int new_value) {
    bs_tree_node * new_node = new bs_tree_node;
    new_node->set_value(new_value);
    right = new_node;
}


bs_tree_node* bs_tree_node::get_right() const {
        if(right == nullptr) {
        return nullptr;
    }
    else {
        return right;
    }
}