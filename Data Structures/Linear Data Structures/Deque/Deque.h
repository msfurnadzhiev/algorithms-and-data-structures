#pragma once
#include <iostream>

const int INITIAL_CAPACITY = 32;

class Deque {

    double *_container = nullptr; //allocated memory
    double *_data = nullptr;
    size_t _capacity = 0;
    size_t _size = 0;

    void copy(const Deque & other);
    void erase();

public:

    /* Constructors */
    Deque();
    explicit Deque(size_t n);
    Deque(const Deque &other);
    Deque & operator=(const Deque &other);
    ~Deque();

    /* Capacity */
    bool empty() const;
    size_t size() const;
    size_t capacity() const;
    void reserve(size_t n);

    /* Element access */
    double & at(size_t index) const;
    double & operator[](size_t index) const;
    double & front() const;
    double & back() const;
    double * data() const;
    double * container() const; //temp

    /* Modifiers */
    void push_back(double value);
    void push_front(double value);
    void pop_back();
    void pop_front();
    void clear();

};

