#ifndef BS_TREE_H
#define BS_TREE_H

#include "bs_tree_node.h"

class bs_tree {
    public:
        bs_tree();
        ~bs_tree();
        
        void add(const int new_value);
        void remove(const int old_value);
        void inorder_traversal(bs_tree_node *current);
        bs_tree_node* get_root() const;

    private:
        bs_tree_node * root;
        void find_node(const int old_value, bs_tree_node** current, bs_tree_node** save_prev);
        void find_successor(const int old_value, bs_tree_node* successor);
};

#endif