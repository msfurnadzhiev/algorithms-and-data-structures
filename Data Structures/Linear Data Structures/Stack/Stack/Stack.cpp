#include "Stack.h"

template <typename T>
Stack<T>::Stack() : top_index(-1), capacity(INITIAL_CAPACITY) {
    data = new T[capacity];
}

template <typename T>
Stack<T>::Stack(Stack<T> const& other) :  top_index(-1), capacity(INITIAL_CAPACITY)  {
    copy(other);
}

template <typename T>
Stack<T>& Stack<T>::operator=(Stack const & other_stack) {
    if(this != &other_stack) {
        erase();
        copy(other_stack);
    }
    return *this;
}

template <typename T>
Stack<T>::~Stack() {
    erase();
}

template <typename T>
bool Stack<T>::empty() const {
    return (top_index == -1);
}

template <typename T>
bool Stack<T>::full() const {
    return (top_index == capacity - 1);
}

template <typename T>
T Stack<T>::top() const {
    if(empty()) {
        cerr << "The stack is empty.\n";
        return T();
    }
    return data[top_index];
}

template <typename T>
T Stack<T>::pop() {
    if(empty()) {
        cerr << "The stack is empty.\n";
        return NULL;
    }
    return data[top_index--];
}

template <typename T>
void Stack<T>::push(T const& x) {
    if(full()) {
        reserve();
    }
    data[++top_index] = x;
}



template <typename T>
void Stack<T>::erase() {
    delete[] data;
}

template <typename T>
void Stack<T>::copy(Stack const& other) {
    top_index = other.top_index;
    capacity = other.capacity;
    data = new T[capacity];
    for(int i=0; i < capacity; i++) {
        data[i] = other[i];
    }
}

template <typename T>
void Stack<T>::reserve() {
    T* temp = data;
    capacity *= 2;
    data = new T[capacity];
    for(int i=0; i < capacity; i++) {
        data[i] = temp[i];
    }
    delete[] temp;
}

