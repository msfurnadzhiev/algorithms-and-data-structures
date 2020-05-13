#include <iostream>
#include "doublyLinkedList.h"
using namespace std;

template <typename T>
void DoublyLinkedList<T>::deleteList() {
    Node<T>* tempNode;
    while(head) {
        tempNode = head;
        head = head->next;
        delete tempNode;
    }
    tail = nullptr;
}

template <typename T>
void DoublyLinkedList<T>::copyList(const DoublyLinkedList<T> & list) {
    head = tail = nullptr;
    if(list.head) {
        DoublyLinkedList<T>* tempNode = list.head;
        while(tempNode) {
            addNodeToTail(tempNode->data);
            tempNode = tempNode->next;
        }
    }
}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(DoublyLinkedList<T> const & list) {
    copyList(list);
}

template <typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(DoublyLinkedList<T> const & list) {
    if(this != &list) {
        deleteList();
        copyList(list);
    }
    return *this;
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    deleteList();
}

template <typename T>
void DoublyLinkedList<T>::iterHead(Node<T>* tempNode) {
    if(tempNode) {
        currentHead = tempNode;
    }
    else {
        currentHead = head;
    }
}

template <typename T>
Node<T>* DoublyLinkedList<T>::iterNext() {
    Node<T>* tempNode = currentHead;
    if(currentHead) {
        currentHead = currentHead->next;
    }
    return tempNode;
}

template <typename T>
void DoublyLinkedList<T>::iterTail(Node<T>* tempNode) {
    if(tempNode) {
        currentTail = tempNode;
    }
    else {
        currentTail = tail;
    }
}

template <typename T>
Node<T>* DoublyLinkedList<T>::iterPrev() {
    Node<T>* tempNode = currentTail;
    if(currentTail) {
        currentTail = currentTail->prev;
    }
    return tempNode;
}

template <typename T>
void DoublyLinkedList<T>::addNodeToTail(const T & x) {
    Node<T>* newNode = new Node<T>;
    newNode->data = x;
    newNode->next = nullptr;

    if(tail) {
        tail->next = newNode;
    }
    else {
        head = newNode;
    }
    newNode->prev = tail;
    tail = newNode;
}

template <typename T>
bool DoublyLinkedList<T>::deleteNode(Node<T>* delNode, T& x) {
    if(!delNode) {
        cerr << "Invalid pointer!";
        return false;
    }

    x = delNode->data;
    if(head == tail) {
        head = nullptr;
        tail = nullptr;
    }
    else if(delNode == head) {
        head = head->next;
        head->prev = nullptr;
    }
    else if(delNode == tail) {
        tail = delNode->prev;
        tail->next = nullptr;
    }
    else {
        delNode->prev->next = delNode->next;
        delNode->next->prev = delNode->prev;
    }
    delete delNode;

    return true;
}

template <typename T>
void DoublyLinkedList<T>::print() {
    Node<T>* tempNode = head;
    while(tempNode) {
        cout << tempNode->data << " ";
        tempNode = tempNode->next;
    }
    cout << endl;
}

template <typename T>
void DoublyLinkedList<T>::printReverse() {
    Node<T>* tempNode = tail;
    while(tempNode) {
        cout << tempNode->data << " ";
        tempNode = tempNode->prev;
    }
    cout << endl;
}

template <typename T>
int DoublyLinkedList<T>::length() {
    int n = 0;
    Node<T>* tempNode = head;
    while(tempNode) {
        n++;
        tempNode = tempNode->next;
    }
    return n;
}
