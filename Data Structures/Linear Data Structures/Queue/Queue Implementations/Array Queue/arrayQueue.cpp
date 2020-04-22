#include <iostream>
#include "arrayQueue.h"
using namespace std;

template <typename T>
void ArrayQueue<T>::copyQueue(const ArrayQueue<T>& other_queue) {
    queue_size = other_queue.queue_size;
    data = new T[queue_size];
    assert(data != NULL);
    for (int i = 0; i < queue_size; i++) {
        data[i] = other_queue.arr[i];
    }
    queue_len = other_queue.queue_len;
    front = other_queue.front;
    rear = other_queue.rear;
}

template <typename T>
void ArrayQueue<T>::deleteQueue() {
    delete[] data;
}

template <typename T>
ArrayQueue<T>::ArrayQueue(int size)
{
    if (size <= 0) {
        queue_size = SIZE;
    }
    else {
        queue_size = size;
    }
    data = new T[queue_size];
    assert(data != NULL);
    front = 0;
    rear = 0;
    queue_len = 0;
}

template <typename T>
ArrayQueue<T>::ArrayQueue(const ArrayQueue<T>& r) {
    copyQueue(r);
}

template <typename T>
ArrayQueue<T>& ArrayQueue<T>::operator=(const ArrayQueue<T>& other_queue) {
    if (this != &other_queue) {
        deleteQueue();
        copyQueue(other_queue);
    }
    return *this;
}

template <typename T>
ArrayQueue<T>::~ArrayQueue() {
    deleteQueue();
}

template <typename T>
ostream& operator<<(ostream &os,const ArrayQueue<T>& queue) {
    if(queue.empty()) {
        cerr << "The queue is empty.\n";
    }
    int len = 0;
    while (len < queue.queue_len) {
        os << queue.data[len++] << endl;
    }
    return os;
}

template <typename T>
istream& operator>>(istream &is,ArrayQueue<T>& queue) {
    if (!queue.full()) {
        is >> queue.data[queue.rear];
        queue.queue_len++;
        queue.rear++;
        queue.rear = queue.rear % queue.queue_size;
    }
    else {
        cout << "The queue is full.\n";
        exit(1);
    }
    return is;
}

template <typename T>
bool ArrayQueue<T>::empty() const {
    return queue_len == 0;
}

template <typename T>
bool ArrayQueue<T>::full() const {
    return queue_len == queue_size;
}

template <typename T>
void ArrayQueue<T>::push(const T& x) {
    if (!full()) {
        data[rear] = x;
        queue_len++;
        rear++;
        rear = rear % queue_size;
    }
    else {
        cout << "The queue is full.\n";
        exit(1);
    }
}

template <typename T>
void ArrayQueue<T>::pop(T& x) {
    if (!empty()) {
        x = data[front];
        queue_len--;
        front++;
        front = front % queue_size;
    }
    else {
        cout << "The queue is empty.\n";
        exit(1);
    }
}

template <typename T>
void ArrayQueue<T>::head(T& x) const {
    if (!empty()) {
        x = data[front];
    }
    else {
        cout << "The queue is empty.\n";
        exit(1);
    }
}

