#include <iostream>
#include "arrayStack.h"
using namespace std;

const int INITIAL_CAPACITY = 64;

template <typename T>
void ArrayStack<T>::deleteStack() {
    delete[] data;
}

template <typename T>
void ArrayStack<T>::copy(T const* other) {
    for(int i=0; i < capacity; i++) {
        data[i] = other[i];
    }
}

template <typename T>
void ArrayStack<T>::copyStack(ArrayStack const& other_stack ) {
    this->topIndex = other_stack.topIndex;
    this>capacity = other_stack.capacity;
    data = new T[capacity];
    copy(other_stack.data);
}

template <typename T>
void ArrayStack<T>::resize() {
    int* oldStackPtr = data;
    data = new T[2*capacity];
    copy(oldStackPtr);
    capacity *= 2;
    delete[] oldStackPtr;
}

template <typename T>
ArrayStack<T>::ArrayStack() : topIndex(-1), capacity(INITIAL_CAPACITY) {	//Default constructor...
    data = new T[capacity];
}

template <typename T>
ArrayStack<T>::ArrayStack(ArrayStack<T> const& other_stack) {	   //Copy constructor..
    copyStack();
}

template <typename T>
ArrayStack<T>& ArrayStack<T>::operator=(ArrayStack const & other_stack) {	//Copy assigment operator...
    if(this != &other_stack) {
        deleteStack();
        copyStack(other_stack);
    }
    return *this;
}

template <typename T>
ArrayStack<T>::~ArrayStack() {       //Destructor...
    deleteStack();
}

template <typename T>
ostream& operator<<(ostream &os,ArrayStack<T>& stack) {
    if(stack.empty()) {
        cerr << "The stack is empty.\n";
    }
    int index = stack.topIndex;
    while (index > -1) {
        os << stack.data[index--] << endl;
    }
    return os;
}

template <typename T>
istream& operator>>(istream &is,ArrayStack<T>& stack) {
    if(stack.full()) {
        stack.resize();
    }
    is >> stack.data[++stack.topIndex];
    return is;
}

template <typename T>
bool ArrayStack<T>::empty() const {
    return topIndex == -1;
}

template <typename T>
bool ArrayStack<T>::full() const {
    return topIndex == capacity - 1;
}

template <typename T>
T ArrayStack<T>::pop() {
    if(empty()) {
        cerr << "The stack is empty.\n";
        return T();
    }
    return data[topIndex--];
}

template <typename T>
T ArrayStack<T>::top() const {
    if(empty()) {
        cerr << "The stack is empty.\n";
        return T();
    }
    return data[topIndex];
}

template <typename T>
void ArrayStack<T>::push(T const& x) {
    if(full()) {
        resize();
    }
    data[++topIndex] = x;
}
