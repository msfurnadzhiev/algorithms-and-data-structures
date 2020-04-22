#include <iostream>
#include "CircularLinkedList.h"
using namespace std;

template <typename T>
void CircularLinkedList<T>::iterStart(Node<T> *tempNode) {
    if(tempNode) {
        current = tempNode;
        return;
    }
    if(tail) {
        current = tail->next;
    }
    else {
        current = nullptr;
    }
}

template <typename T>
Node<T>* CircularLinkedList<T>::iter() {
    if(!current) {
        return nullptr;
    }

    Node<T>* tempNode = current;
    if(current == tail) {
        current = nullptr;
    }
    else if (current) {
        current = current->next;
    }
    return tempNode;
}

template <typename T>
void CircularLinkedList<T>::deleteList() {
    iterStart();
    Node<T>* tempNode = iter();
    while(tempNode) {
        delete tempNode;
        tempNode = iter();
    }
    tail = nullptr;
}

template <typename T>
void CircularLinkedList<T>::copyList(CircularLinkedList<T> const & list) {
    tail = nullptr;
    Node<T>* tempNode = list.tail;
    if(tempNode) {
        tempNode = tempNode->next;
        while(tempNode != list.tail) {
            addNodeToEnd(tempNode->data);
            tempNode = tempNode->next;
        }
        addNodeToEnd(tempNode->data);
    }
}

template <typename T>
CircularLinkedList<T>::CircularLinkedList() {
    tail = nullptr;
}

template <typename T>
CircularLinkedList<T>::~CircularLinkedList() {
    deleteList();
}

template <typename T>
CircularLinkedList<T>::CircularLinkedList(CircularLinkedList<T> const & list) {
    copyList(list);
}

template <typename T>
CircularLinkedList<T>& CircularLinkedList<T>::operator=(CircularLinkedList<T> const & list) {
    if(this != &list) {
        deleteList();
        copyList(list);
    }
    return *this;
}

template <typename T>
void CircularLinkedList<T>::addNodeToEnd(const T & x) {
    Node<T>* newNode = new Node<T>;
    newNode->data = x;

    if(tail) {
        newNode->next = tail->next;
    }
    else {
        tail = newNode;
    }
    tail->next = newNode;
    tail = tail->next;
}

template <typename T>
void CircularLinkedList<T>::deleteNode(Node<T>* delNode, T& x) {
    if(!delNode) {
        cerr << "Invalid pointer!";
        return;
    }
    x = delNode->data;

    if(tail == tail->next) {
        tail = nullptr;
        delete delNode;
        return;
    }

    Node<T>* prevNode = tail;
    while(prevNode->next != delNode) {
        prevNode = prevNode->next;
    }

    prevNode->next = delNode->next;
    if(delNode == tail) {
        tail = prevNode;
    }
    delete delNode;
}

template <typename T>
void CircularLinkedList<T>::print() {
    iterStart();
    Node<T>* tempNode = iter();
    while(tempNode) {
        cout << tempNode->data << " ";
        tempNode = iter();
    }
    cout << endl;
}


