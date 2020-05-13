#include <iostream>
#include "Queue.h"
using namespace std;

template <typename T>
Queue<T>::Queue(int initial_capacity)
{
    capacity = initial_capacity;
    data = new T[capacity];
    assert(data != nullptr);
    front = 0;
    back = 0;
    size = 0;
}

template <typename T>
Queue<T>::Queue(const Queue<T> &other){
    copy(other);
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue<T> &other) {
    if (this != &other) {
        erase();
        copy(other);
    }
    return *this;
}

template <typename T>
Queue<T>::~Queue() {
    erase();
}


template <typename T>
bool Queue<T>::empty() const {
    return size == 0;
}

template <typename T>
bool Queue<T>::full() const {
    return size == capacity;
}

template <typename T>
void Queue<T>::push(const T& x) {
    if (full()) {
        cout << "The queue is full.\n";
        return;
    }
        data[back] = x;
        size++;
        back++;
        back = back % capacity;
}

template <typename T>
void Queue<T>::pop(T& x) {
    if (empty()) {
    	cout << "The queue is empty.\n";
    }
        x = data[front];
        size--;
        front++;
        front = front % capacity;
}

template <typename T>
void Queue<T>::head(T& x) const {
    if (empty()) {
        cout << "The queue is empty.\n";
    }
    x = data[front];
}


template <typename T>
void Queue<T>::copy(const Queue<T>& other_queue) {
    capacity = other_queue.capacity;
    data = new T[capacity];
    assert(data != nullptr);
    for (int i = 0; i < capacity; i++) {
        data[i] = other_queue.arr[i];
    }
    size = other_queue.size;
    front = other_queue.front;
    back = other_queue.back;
}

template <typename T>
void Queue<T>::erase() {
    delete[] data;
}

