#include "Deque.h"

/* Constructors */

Deque::Deque() {
    reserve(INITIAL_CAPACITY);
}

Deque::Deque(size_t n) {
    reserve(n);
}

Deque::Deque(const Deque &other) {
    copy(other);
}

Deque & Deque::operator=(const Deque &other) {
    if(this != &other){
        erase();
        copy(other);
    }
    return *this;
 }

Deque::~Deque() {
    erase();
}


/* Capacity */



bool Deque::empty() const {
    return _size == 0;
}

size_t Deque::size() const {
    return _size;
}

size_t Deque::capacity() const {
    return _capacity;
}

void Deque::reserve(size_t n) {

    if(n <= _capacity) return;

    _capacity = n;
    double *temp_container = new double[_capacity];
    double *temp_data = temp_container + ((_capacity / 2) - (_size / 2));

    for(size_t i = 0; i < _size; i++) {
        temp_data[i] = _data[i];
    }

    delete[] _container;

    _container = temp_container;
    _data = temp_data;

}


/* Element access */

double & Deque::operator[](size_t index) const {
    return _data[index];
}

double & Deque::at(size_t index) const {
    if(index < 0 || index >= _size) {
        std::cerr << "Deque::at() : index out of range" << std::endl;
        exit(1);
    }
    return _data[index];
}

double & Deque::front() const {
    if(empty()) {
        std::cerr << "Deque::front() : deque is empty!" << std::endl;
        exit(1);
    }
    return _data[0];
}

double & Deque::back() const {
    if(empty()) {
        std::cerr << "Deque::front() : deque is empty!" << std::endl;
        exit(1);
    }
    return _data[_size - 1];
}

double * Deque::data() const {
    return _data;
}

double * Deque::container() const {
    return _container;
}


/* Modifiers */

void Deque::push_back(double value) {
    if(_capacity == 0) {
        reserve(INITIAL_CAPACITY);
    }
    else if((_data + _size) == (_container + _capacity)) {
        reserve(_capacity * 2);
    }
    _data[_size++] = value;
}

void Deque::push_front(double value) {
    if(_capacity == 0) {
        reserve(INITIAL_CAPACITY);
    }
    else if(_data == _container) {
        reserve(_capacity * 2);
    }
    _data -= 1;
    _data[0] = value;
    _size++;
}

void Deque::pop_back() {
    if(_size == 0) {
        return;
    }
    _size--;
}

void Deque::pop_front() {
    _size--;
    _data += 1;
}

void Deque::clear() {
    _data = _container + _capacity/2;
    _size = 0;
}


/* ------ */
void Deque::copy(const Deque &other) {
    _capacity = other._capacity;
    _container = new double[_capacity];
    _size = other._size;
    _data = _container + (other._data - other._container);
    for(int i=0; i<_size; i++) {
        _data[i] = other._data[i];
    }
}

void Deque::erase() {
    delete[] _container;
}