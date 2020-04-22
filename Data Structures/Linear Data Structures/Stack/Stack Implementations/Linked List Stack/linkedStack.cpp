#include <iostream>
#include <cassert>
#include "Stack.h"

template <typename T>
void Stack<T>::deleteStack() {
    node<T>* temp;
    while(top != nullptr) {
        temp = top;
        top = top->next;
        delete temp;
    }
}

template <typename T>
void Stack<T>::copyStack(const Stack<T>& basic_stack) {
    if(basic_stack.top != nullptr) {
        node<T>* i = basic_stack.top;
        node<T>* t = nullptr;
        node<T>* n = nullptr;

        top = new node<T>;
        assert(top != nullptr);
        top->data = i->data;
        top->next = t;
        t = top;
        i = i->next;
        while(i != nullptr) {
            n = new node<T>;
            assert(n != nullptr);
            n->data = i->data;
            t->next = n;
            t = n;
            i = i->next;
        }
        t->next = nullptr;
    }
    else {
        top = nullptr;
    }
}

template <typename T>
Stack<T>::Stack () {    //Default constructor...
    top = nullptr;
}

template <typename T>
Stack<T>::Stack(Stack<T> const& basic_stack) {    //Copy constructor...
    copyStack(basic_stack);
}

template <typename T>
Stack<T> & Stack<T>::operator= (const Stack<T> & basic_stack) {    //Copy assignment operator...
    if (this != &basic_stack) {
        deleteStack();
        copyStack(basic_stack);
    }
    return *this;
}

template <typename T>
Stack<T>::~Stack() {    //Destructor...
    deleteStack();
}

template <typename T>
ostream& operator<<(ostream &os, const Stack<T>& stack) {
    node<T>* i = stack.top;
    while(i != nullptr) {
        os << (i->data) << endl;
        i = i->next;
    }

    return os;
}

template <typename T>
ostream& operator<<(ostream &os, const Stack<T>& stack) {
    node<T>* i = stack.top;
    while(i != nullptr) {
        os << (i->data) << endl;
        i = i->next;
    }

    return os;
}

template <typename T>
istream& operator>>(istream &is,Stack<T>& stack) {
    node<T>* t = stack.top;
    stack.top = new node<T>;
    assert(stack.top != nullptr);
    is >> stack.top->data;
    stack.top->next = t;
    return is;
}

template <typename T>
void Stack<T>::push(const T& a) {

    node<T>* t = top;
    top = new node<T>;
    assert(top != nullptr);
    top->data = a;
    top->next = t;

}

/*template <typename T>
T Stack<T>::pop() {
    if(empty()) {
        cerr << "\nThe stack is empty\n";
        return 0;
    }
    node<T>* temp = top;
    top = top->next;
    T x = temp->data;
    delete temp;
    return x;
} */

template <typename T>
void Stack<T>::pop(T& a) {

    if(top != nullptr) {
        a = top->data;
        node<T>* t = top;
        top = top->next;
        delete t;
    }

    else {
        cerr << "\nThe stack is empty\n";
    }

}

template <typename T>
bool Stack<T>::empty() const {
    return top == nullptr;
}

template <typename T>
void Stack<T>::peek(T& a) {
    a = top->data;
}

/*template <typename T>
T Stack<T>::peek() const {
     if(empty()) {
        cerr << "\nThe stack is empty\n";
        return 0;
    }
    return top->data;
}
*/

template <typename T>
void Stack<T>::print() {
    node<T>* i = top;
    while(i != nullptr){
        cout << i->data << endl;
        i = i->next;
    }
}
