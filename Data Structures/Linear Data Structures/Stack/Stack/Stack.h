#ifndef HELPSTRUCTURES_STACK_H
#define HELPSTRUCTURES_STACK_H
#include <iostream>
#include <fstream>
using namespace std;

#define INITIAL_CAPACITY 64

template <typename T>
class Stack {
    T* data;
    int top_index;
    size_t capacity;

    void reserve();
    void erase();
    void copy(Stack const&);

public:
    Stack();
    Stack(Stack const&);
    Stack& operator=(Stack const &);
    ~Stack();


    bool empty() const;
    bool full() const;
    T top() const;
    void push(T const& x);
    T pop();

};

#endif //HELPSTRUCTURES_STACK_H

