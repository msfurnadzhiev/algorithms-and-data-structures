#include "Vector.h"

const int INITIAL_CAPACITY = 64;

/* ----- Constructors ----- */

template <typename T>
Vector<T>::Vector() : _size(0), _capacity(0) {
    _data = new T[_capacity];
}

template <typename T>
Vector<T>::Vector(size_t n, T val) : _data(new T[n]), _size(n), _capacity(n) {
    for(int i=0; i < _size; i++) {
        _data[i] = val;
    }
}

template <typename T>
Vector<T>::Vector(const Vector &other) {
    _size = other._size;
    _capacity = other._capacity;
    _data = new T[_capacity];
    for(int i=0; i < _size; i++) {
        _data[i] = other._data[i];
    }
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector &other) {

    if(this != &other) {
        if(other._size > _capacity) {
            reserve(other._capacity);
        }
        _size = other._size;
        for (int i = 0; i < _size; i++) {
            _data[i] = other._data[i];
        }
    }

    return *this;
}

template <typename T>
Vector<T>::Vector(Vector && other) noexcept {
    _size = other._size;
    _capacity = other._capacity;
    _data = other._data;
    other.clear();
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector &&other) noexcept {

    if(this != &other) {
        delete[] _data;
        _size = other._size;
        _capacity = other._capacity;
        _data = other._data;
        other.clear();
    }
    return *this;
}

template <typename T>
Vector<T>::~Vector() {
    delete[] _data;
}


/*-------- Accessors ---------*/

template <typename T>
T* Vector<T>::data() const {
    return _data;
}

template <typename T>
T& Vector<T>::operator[](unsigned index) {
    if(index < 0 || index >= _size) raise(SIGSEGV);
    return _data[index];
}


/* -------- Capacity -------- */

template <typename T>
size_t Vector<T>::size() const {
    return _size;
}

template <typename T>
size_t Vector<T>::capacity() const {
    return _capacity;
}

template <typename T>
void Vector<T>::reserve(size_t n) {

    if(n > _capacity) {

        T *temp = new T[n];

        for (int i = 0; i < _size; i++) {
            temp[i] = _data[i];
        }

        delete[] _data;

        _data = temp;
        _capacity = n;
    }
}

template <typename T>
void Vector<T>::resize(size_t new_size, T val) {
    
    reserve(new_size);
    
    for(size_t i = _size; i < new_size; i++) {
        _data[i] = val;
    }
    _size = new_size;
}

template <typename T>
bool Vector<T>::empty() const {
    return (_size == 0);
}


/* ----- Modifiers ----- */

template <typename T>
void Vector<T>::clear() {
    _size = 0;
    _data = nullptr;
}

template <typename T>
void Vector<T>::swap(Vector &other) {
    Vector<T> temp = *this;
    *this = other;
    other = temp;
}

template <typename T>
void Vector<T>::push_back(const T &val) {

    if(_capacity == 0) {
        reserve(INITIAL_CAPACITY);
    }
    else if(_size == _capacity) {
        reserve(2*_capacity);
    }

    _data[_size++] = val;
}

template <typename T>
void Vector<T>::pop_back() {
    if(_size == 0) return;
    _size--;
}


/*------ Help Functions -----*/

template <typename T>
void Vector<T>::copy(const Vector &other) {
    _size = other._size;
    _capacity = other._capacity;
    _data = new T[_capacity];
    for(int i=0; i < _size; i++) {
        _data[i] = other._data[i];
    }
}


