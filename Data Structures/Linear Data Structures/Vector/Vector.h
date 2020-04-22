#ifndef TESTPROJECT_VECTOR_H
#define TESTPROJECT_VECTOR_H
#include <iostream>
#include <cassert>
#include <csignal>
using namespace std;


template <typename T>
class Vector {

    T* _data;
    size_t _size;
    size_t _capacity;

    void copy(const Vector &);

public:

    /* ----- Constructors ----- */

    Vector();

    explicit Vector(size_t, T = T());

    //Copy constructor...
    Vector(const Vector &);

    //Copy assignment operator...
    Vector& operator=(const Vector &);

    //Move constructor...
    Vector(Vector &&) noexcept;

    //Move assignment operator...
    Vector& operator=(Vector &&) noexcept;

    ~Vector();


    /*-------- Accessors ---------*/

    T* data() const;

    T & operator[](unsigned);


    /* -------- Capacity -------- */

    bool empty() const;

    size_t capacity() const;

    size_t size() const;

    void reserve(size_t n);

    void resize(size_t, T = T());


    /* ----- Modifiers ----- */

    // Removes all elements from the Vector (capacity is not changed)
    void clear();

    void push_back(const T&);

    void pop_back();

    void swap(Vector&);

    //void erase();

};


#endif //TESTPROJECT_VECTOR_H

