#ifndef TREES_REDBLACKTREE_H
#define TREES_REDBLACKTREE_H

#include <iostream>
using namespace std;

enum Color {RED, BLACK};

struct Node {
    int data;
    bool color;
    Node *parent;
    Node *left, *right;
};

class RedBlackTree {

    Node *root = nullptr;

    void left_rotation(Node *&, Node *&);
    void right_rotation(Node *&, Node *&);
    void fix_violation(Node *&, Node *&);
    Node* find(Node *, int const &) const;
    Node* insert(Node *&, int const &) const;
    Node* erase(Node *&, int const &) const;
    void print(const Node *) const;

public:
    Node* get_root() const;
    Node* find_node(int const &);
    void insert_node(int const &);
    bool erase_node(int const &);
    void print_tree() const;
};

void RedBlackTree::left_rotation(Node *&root, Node *&node) {
    Node *temp = node->right;
    node->right = temp->left;
    temp->left = node;

    if(node->right) {
        node->right->parent = node;
    }
    temp->parent = node->parent;

    if(!node->parent) {
        root = temp;
    }
    else if(node == node->parent->right) {
        node->parent->right = temp;
    }
    else {
        node->parent->left = temp;
    }

    node->parent = temp;
}

void RedBlackTree::right_rotation(Node *&root, Node *&node) {
    Node *temp = node->left;
    node->left = temp->right;
    temp->right = node;

    if(node->left) {
        node->left->parent = node;
    }
    temp->parent = node->parent;

    if(!node->parent) {
        root = temp;
    }
    else if(node == node->parent->left) {
        node->parent->left = temp;
    }
    else {
        node->parent->right = temp;
    }

    node->parent = temp;
}

void RedBlackTree::fix_violation(Node *&root, Node *&node) {

    Node *parent = nullptr, *grandparent = nullptr;

    while((node != root) && (node->color != BLACK) && (node->parent->color == RED)) {
        parent = node->parent;
        grandparent = parent->parent;

        //Case A : Left Right Case
        if (parent == grandparent->left) {
            Node *uncle = grandparent->right;

            //Case A.1 : Red Uncle
            if (uncle != nullptr && uncle->color == RED) {
                grandparent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                node = grandparent;
            }
            else {
                //Case A.2.1 : Black Uncle(triangle)
                if (node == parent->right) {
                    left_rotation(root,parent);
                    node = parent;
                    parent = node->parent;
                }
                //Case A.2.2 : Black Uncle(line)
                right_rotation(root,grandparent);
                grandparent = parent->right;
                swap(parent->color, grandparent->color);
                node = parent;
            }
        }
        else {
            Node *uncle = grandparent->left;

            //Case B : Right Left Case

            //Case B.1 : Red Uncle
            if (uncle != nullptr && uncle->color == RED) {
                grandparent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                node = grandparent;
            }
            else {
                //Case B.2.1 : Black Uncle(triangle)
                if (node == parent->left) {
                    right_rotation(root,parent);
                    node = parent;
                    parent = node->parent;
                }
                //Case B.2.2 : Black Uncle(line)
                left_rotation(root,grandparent);
                swap(parent->color, grandparent->color);
                node = parent;
            }
        }
    }
    root->color = BLACK;
}

Node* RedBlackTree::find(Node *root, int const &x) const {
    if(!root) {
        return nullptr;
    }
    if(x < root->data) {
        return find(root->left, x);
    }
    else if(x > root->data){
        return find(root->right,x);
    }
    return root;
}

Node* RedBlackTree::insert(Node *&root, int const &x) const {
    if(!root) {
        root = new Node;
        root->data = x;
        root->color = RED;
        root->parent = nullptr;
        root->left = root->right = nullptr;
        return root;
    }

    Node *node = root;
    if(x < root->data) {
        node = insert(root->left,x);
        root->left->parent = root;
    }
    else if(x > root->data) {
        node = insert(root->right, x);
        root->right->parent = root;
    }
    return node;
}

Node* RedBlackTree::erase(Node *&root, int const &x) const{
    if(!root) {
        return nullptr;
    }
    if(x < root->data) {
        return erase(root->left,x);
    }
    else if(x > root->data) {
        return erase(root->right,x);
    }
    else {
        Node* temp;
        if(!root->left) {
            temp = root;
            root = root->right;
            delete temp;
        }
        else if(!root->right) {
            temp = root;
            root = root->left;
            delete temp;
        }
        else {
            temp = root->left;
            while(temp->right) {
                temp = temp->right;
            }
            root->data = temp->data;
            erase(root->left, temp->data);
        }
        return root;
    }
}

void RedBlackTree::print(const Node *root) const {
    if(root) {
        print(root->left);
        cout << root->data;
        if (root->parent) {
            cout << "(" << root->parent->data << ")";
        }
        cout << "(" << (root->color ? "BLACK" : "RED") << ") ";
        print(root->right);
    }
}

//Application Programming Interface

Node* RedBlackTree::get_root() const {
    return this->root;
}

Node* RedBlackTree::find_node(int const &x) {
    return find(this->root,x);
}

void RedBlackTree::insert_node(int const &x) {
    Node *new_node = insert(this->root,x);
    fix_violation(this->root,new_node);
}

bool RedBlackTree::erase_node(int const &x) {
    Node *temp = erase(this->root,x);
    if(temp) {
        fix_violation(this->root,temp);
        return true;
    }
    return false;
}

void RedBlackTree::print_tree() const {
    print(this->root);
}

#endif //TREES_REDBLACKTREE_H

