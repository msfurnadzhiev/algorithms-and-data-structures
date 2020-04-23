#ifndef STRUCTURES_VECTOR_H
#define STRUCTURES_VECTOR_H
#include <iostream>
#include <cassert>
#include <csignal>
using namespace std;

#define INITIAL_CAPACITY 64

template <typename T>
class Vector {

    T* _data = nullptr;
    size_t _size = 0;
    size_t _capacity = 0;

    void assign(size_t, T = T());
    void assign(T *, size_t);
    void move(Vector &) const;
public:

    /* ----- Constructors ----- */

    Vector();
    Vector(size_t, T = T());
    Vector(const Vector &);                 //Copy constructor...
    Vector(Vector &&) noexcept;             //Move constructor...
    ~Vector();

    Vector& operator=(const Vector &);      //Copy assignment operator...
    Vector& operator=(Vector &&) noexcept;  //Move assignment operator...

    /*-------- Accessors ---------*/

    T* data() const;
    const T & operator[](size_t) const;
    const char & front() const;
    const char & back() const;


    /* -------- Capacity -------- */

    bool empty() const;
    void clear();
    size_t capacity() const;
    size_t size() const;
    void reserve(size_t n);
    void resize(size_t, T = T());


    /* ----- Modifiers ----- */

    void push_back(const T&);
    T pop_back();
    void swap(Vector&);
};


#endif //STRUCTURES_VECTOR_H
