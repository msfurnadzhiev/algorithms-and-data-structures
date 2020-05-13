#ifndef _QUEUE_H
#define _QUEUE_H

#include <iostream>
#include <cassert>

#define QUEUE_SIZE 64

template <typename T>
class Queue {
    T *data = nullptr;
    int capacity = 0;
    int size = 0;
    int front = 0;
    int back = 0;
    
    

    void copy(const Queue &);
    void erase();

public:
    explicit Queue(int = QUEUE_SIZE);
    Queue(const Queue &);
    Queue &operator=(const Queue &);
    ~Queue();

    bool empty() const;
    bool full() const;
    void push(const T &);
    void pop(T &);
    void head(T &) const;
};
};
#endif //_QUEUE_H

