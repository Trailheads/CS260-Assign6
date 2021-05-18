#ifndef BS_TREE_NODE_H
#define BS_TREE_NODE_H

class bs_tree_node {
    private:
        int value;
        bs_tree_node *left;
        bs_tree_node *right;

    public:
        bs_tree_node();
        ~bs_tree_node();

        void set_value(const int new_value);
        int get_value() const;

        void set_root(bs_tree_node** root, const int new_value);

        void set_left(int new_value);
        bs_tree_node* get_left() const;

        void set_right(int new_value);
        bs_tree_node* get_right() const;
};

#endif