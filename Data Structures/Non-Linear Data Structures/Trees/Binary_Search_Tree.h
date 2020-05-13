#ifndef TREES_BINARYSEARCHTREE_H
#define TREES_BINARYSEARCHTREE_H

#include <iostream>
using namespace std;


struct Node {
    int data;
    Node *left, *right;
};

class BinarySearchTree {

    Node* root = nullptr;

    Node* find(const Node *, int const &) const;
    void insert(Node *&, int const &) const;
    bool erase(Node *&, int const &) const;
    void print(const Node *) const;


public:
    Node* get_root() const;
    Node* find_node(int const &);
    void insert_node(int const &);
    bool erase_node(int const &);
    void print_tree() const;
};


Node* BinarySearchTree::find(const Node *root, int const &x) const {
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

void BinarySearchTree::insert(Node *&root, int const &x) const {
    if(!root) {
        root = new Node;
        root->data = x;
        root->left = root->right = nullptr;
        return;
    }
    if(x < root->data) {
        insert(root->left, x);
    }
    else {
        insert(root->right, x);
    }
}

bool BinarySearchTree::erase(Node *&root, int const &x) const {
    if(!root) {
        return false;
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
            temp = root->right;
            while(temp->left) {
                temp = temp->left;
            }
            root->data = temp->data;
            erase(root->right, temp->data);
        }
        return true;
    }
}

void BinarySearchTree::print(const Node *root) const {
    if(root) {
        print(root->left);
        cout << root->data << " ";
        print(root->right);
    }
}


//Application Programming Interface

Node* BinarySearchTree::get_root() const {
    return this->root;
}

Node* BinarySearchTree::find_node(int const &x) {
    return find(this->root, x);
}

void BinarySearchTree::insert_node(int const &x) {
    insert(this->root, x);
}

bool BinarySearchTree::erase_node(int const &x) {
    return erase(this->root, x);
}

void BinarySearchTree::print_tree() const {
    print(this->root);
}

#endif //TREES_BINARYSEARCHTREE_H

