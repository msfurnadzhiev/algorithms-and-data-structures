#include "LStack.h"

template <typename T>
Stack<T>::Stack(Stack<T> const &other) {
    copy(other);
}

template <typename T>
Stack<T> & Stack<T>::operator= (const Stack<T> &other) {
    if (this != &other) {
        erase();
        copy(other);
    }
    return *this;
}

template <typename T>
Stack<T>::~Stack() {
    erase();
}


template <typename T>
void Stack<T>::push(const T &a) {

    Node<T>* t = top;
    top = new Node<T>;
    assert(top != nullptr);
    top->data = a;
    top->next = t;

}

template <typename T>
void Stack<T>::pop(T &a) {

    if(empty()) {
        cerr << "\nThe stack is empty\n";
        return;
    }

    a = top->data;
    Node<T>* t = top;
    top = top->next;
    delete t;
}

/*template <typename T>
T Stack<T>::pop() {
    if(empty()) {
        cerr << "\nThe stack is empty\n";
        return T();
    }
    Node<T>* temp = top;
    top = top->next;
    T x = temp->data;
    delete temp;
    return x;
} */

template <typename T>
bool Stack<T>::empty() const {
    return top == nullptr;
}

template <typename T>
void Stack<T>::peek(T &a) {
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
void Stack<T>::erase() {
    Node<T>* temp;
    while(top != nullptr) {
        temp = top;
        top = top->next;
        delete temp;
    }
}

template <typename T>
void Stack<T>::copy(const Stack<T>& basic_stack) {
    if(basic_stack.top != nullptr) {
        Node<T>* i = basic_stack.top;
        Node<T>* t = nullptr;
        Node<T>* n = nullptr;

        top = new Node<T>;
        assert(top != nullptr);
        top->data = i->data;
        top->next = t;
        t = top;
        i = i->next;
        while(i != nullptr) {
            n = new Node<T>;
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

