#include <iostream>
#include "Queue.h"
using namespace std;

template <typename T>
void Queue<T>::deleteQueue() {
    node<T>* temp;
    while(front != nullptr) {
        temp = front;
        front = front->next;
        delete temp;
    }
}

template <typename T>
void Queue<T>::copyQueue(const Queue<T>& basic_queue) {
    front = rear = nullptr;

    if(!basic_queue.empty()) {
        node<T>* temp = basic_queue.front;

        while(temp) {
            this->enqueue(temp->data);
            temp = temp->next;
        }
    }
}

template <typename T>
Queue<T>::Queue() {    //Default constructor...
    front = nullptr;
    rear = nullptr;
}

template <typename T>
Queue<T>::Queue(const Queue<T>& basic_queue){    //Copy constructor...
    copyQueue(basic_queue);
}

template <typename T>
Queue<T> & Queue<T>::operator=(const Queue<T>& basic_queue) {   //Copy assignment operator...
    if(this != &basic_queue){
        deleteQueue();
        copyQueue(basic_queue);
    }
}

template <typename T>
Queue<T>::~Queue() {   //Destructor...
    deleteQueue();
}

template <typename T>
istream& operator>>(istream& is, Queue<T>& queue) {
    node<T>* temp = new node<T>;
    is >> temp->data;
    temp->next = nullptr;

    if(queue.front == nullptr) {
        queue.front = temp;
        queue.rear = temp;
    }

    else {
        queue.rear->next = temp;
        queue.rear = temp;
    }
    return is;
}

template <typename T>
ostream& operator<<(ostream& os, const Queue<T>& queue) {
    node<T>* i = queue.front;
    while(i != nullptr) {
        os << i->data <<endl;
        i = i->next;
    }
    return os;
}

template <typename T>
void Queue<T>::enqueue(const T& x) {
    node<T>* temp = new node<T>;
    temp->data = x;
    temp->next = nullptr;

    if(front == nullptr) {
        front = temp;
        rear = temp;
    }
    else {
        rear->next = temp;
        rear = temp;
    }
}

template <typename T>
void Queue<T>::dequeue(T& x) {

    if(!empty()) {
        x = front->data;
        node<T>* temp = front;
        front = front->next;
        delete temp;
    }
    else {
        cerr << "The queue is empty\n";
    }
}

template <typename T>
bool Queue<T>::empty() const {
    return front == nullptr;
}

template <typename T>
void Queue<T>::head(T& a) {
    if(!empty()) {
        a = front->data;
    }
    else {
        cerr << "The queue is empty\n" << endl;
    }
}
