#include <iostream>
#include "LinkedList.h"
//#include "LinkedListIterator.cpp"
using namespace std;

template <typename T>
LinkedList<T>::LinkedList() {
    head = nullptr;
    tail = nullptr;
}


template <typename T>
LinkedList<T>::LinkedList(LinkedList<T> const & list) {
    copyList(list);
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T> const & list) {
    if(this != &list) {
        deleteList();
        copyList(list);
    }
    return *this;
}

template <typename T>
LinkedList<T>::~LinkedList(){
    deleteList();
}


template <typename T>
void LinkedList<T>::iterHead(Node<T>* temp) {
    if(temp) {
        this->current = temp;
    }
    else {
        this->current = this->head;
    }
}

template <typename T>
Node<T>* LinkedList<T>::iter() {
    Node<T>* temp = current;
    if (current) {
        current = current->next;
    }
    return temp;
}

template <typename T>
void LinkedList<T>::deleteList() {
    Node<T>* temp;
    while(head) {
        temp = head;
        head = head->next;
        delete temp;
    }

    tail = nullptr;
}

template <typename T>
void LinkedList<T>::copyList(LinkedList<T> const & list) {
    head = tail = nullptr;
    if(list.head) {
        Node<T>* temp = list.head;
        while(temp) {
            addNodeToTail(temp->data);
            temp = temp->next;
        }
    }
}

template <typename T>
void LinkedList<T>::addNodeToTail(T const & x) {
    Node<T>* newNode = new Node<T>;
    newNode->data = x;
    newNode->next = nullptr;

    if(tail) {
        tail->next = newNode;
    }
    else {
        head = newNode;
    }
    tail = newNode;
}

template <typename T>
void LinkedList<T>::addNodeAfter(Node<T>* temp, T const & x) {
    if(!temp) {
        cerr << "Incorrect index" << endl;
        return;
    }
    Node<T>* newNode = new Node<T>;
    newNode->data = x;
    newNode->next = temp->next;

    if(temp == tail) {
        tail = newNode;
    }

    temp->next = newNode;
}

template <typename T>
void LinkedList<T>::addNodeBefore(Node<T>* tempNode, T const & x) {
    if(!tempNode) {
        cerr << "Invalid pointer.";
        return;
    }

    Node<T>* newNode = new Node<T>;
    *newNode = *tempNode;

    if(tempNode == tail) {
        tail = newNode;
    }

    tempNode->data = x;
    tempNode->next = newNode;
}

template <typename T>
bool LinkedList<T>::deleteNodeAfter(Node<T>* tempNode, T& x) {
    if(!tempNode || !tempNode->next) {
        cerr << "Invalid pointer.";
        return false;
    }

    Node<T>* delNode = tempNode->next;
    x = delNode->data;
    tempNode->next = delNode->next;

    if(delNode == tail) {
        tail = tempNode;
    }

    delete delNode;
    return true;
}

template <typename T>
bool LinkedList<T>::deleteNode(Node<T>* delNode, T& x) {
    if(!delNode) {
        cerr << "Invalid pointer.";
        return false;
    }

    if(delNode == head) {
        x = delNode->data;
        if(head == tail) {
            head = tail = nullptr;
        }
        else {
            head = head->next;
        }
        delete delNode;
    }
    else {
        Node<T>* prevNode = head;
        while(prevNode->next != delNode) {
            prevNode = prevNode->next;
        }
        deleteNodeAfter(prevNode, x);
    }

    return true;
}

template <typename T>
bool LinkedList<T>::deleteNodeBefore(Node<T>* tempNode, T& x) {
    if(!tempNode || tempNode == head) {
        cerr << "Invalid pointer.";
        return false;
    }

    Node<T>* prevNode = head;
    while(prevNode->next != tempNode) {
        prevNode = prevNode->next;
    }

    deleteNode(prevNode,x);
    return true;
}

template <typename T>
void LinkedList<T>::print() {
    Node<T>* currNode = head;
    while (currNode) {
        cout << currNode->data << " ";
        currNode = currNode->next;
    }
    cout << endl;
}

template <typename T>
int LinkedList<T>::lengthList() {
    int n = 0;
    Node<T>* currNode = head;
    while(currNode) {
        n++;
        currNode = currNode->next;
    }
    return n;
}

/*template <typename T>
int LinkedList<T>::lengthList() {
    int n = 0;
    iterhead();
    Node<T>* currNode = iter();
    while(currNode) {
        n++;
        currNode = iter();
    }
    return n;
}*/
