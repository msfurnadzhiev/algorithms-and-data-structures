#ifndef _LSTACK_H
#define _LSTACK_H
#include <iostream>
#include <cassert>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node<T>* next;
};

template <typename T>
class Stack {

    Node<T>* top = nullptr;
    void erase();
    void copy(const Stack<T>&);

public:
    Stack();
    Stack(const Stack<T> &);
    Stack& operator= (const Stack<T> &);
    ~Stack();


    void push(T const&);
    void pop(T&);           //T pop();
    bool empty() const;
    void peek(T&);          //T peek() const;
};

#endif //_LSTACK_H

