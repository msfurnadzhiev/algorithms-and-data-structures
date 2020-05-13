#include <iostream>
using namespace std;

struct Node {
    int data;
    unsigned char height;
    Node *left, *right;
};

struct Tree {
    Node *root = nullptr;
};

unsigned char height(Node *node) {
    return node ? node->height : static_cast<unsigned char>(0);
}

int balance_factor(Node *node) {
    return height(node->right) - height(node->left);
}

void fix_height(Node *&node) {
    unsigned char left = height(node->left);
    unsigned char right = height(node->right);
    node->height = (left>right ? left : right) + static_cast<unsigned char>(1);
}

void left_rotation(Node *&node) {
    Node *temp = node;
    node = node->right;
    temp->right = node->left;
    node->left = temp;

    fix_height(temp);
    fix_height(node);
}

void right_rotation(Node *&node) {
    Node *temp = node;
    node = node->left;
    temp->left = node->right;
    node->right = temp;

    fix_height(temp);
    fix_height(node);
}

void balance(Node *&node) {
    fix_height(node);
    if(balance_factor(node) == 2) {
        if(balance_factor(node->right) < 0) {
            right_rotation(node->right);
        }
        left_rotation(node);
    }
    if(balance_factor(node) == -2) {
        if(balance_factor(node->left) > 0) {
            left_rotation(node->left);
        }
        right_rotation(node);
    }
}

void insert_node(Node *&root, int x) {
    if(!root) {
        root = new Node;
        root->data = x;
        root->height = 1;
        root->right = root->left = nullptr;
        return;
    }
    if(x < root->data) {
        insert_node(root->left,x);
    }
    else {
        insert_node(root->right,x);
    }
    balance(root);
}

void print(Node *root) {
    if(root) {
        print(root->left);
        cout << root->data << "(" << (int)root->height << ") ";
        print(root->right);
    }
}

