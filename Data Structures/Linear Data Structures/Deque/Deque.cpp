#include "Deque.h"


/* --------- Constructors --------- */

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
        copy(other);
    }
    return *this;
}

Deque::~Deque() {
    erase();
}


/* --------- Capacity --------- */

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

    //if buffer == nullptr then new throw std::bad_alloc()
    double *buffer = new double[n];

    size_t buffer_front = (n - _size) / 2;

    for(size_t i = 0; i < _size; i++) {
        buffer[buffer_front + i] = _container[ _front + i];
    }

    delete[] _container;
    _container = buffer;
    _capacity = n;
    _front = buffer_front;
}


/* --------- Element access --------- */

double & Deque::operator[](const size_t index) {
    return _container[_front + index];
}

const double & Deque::operator[](const size_t index) const {
    return _container[_front + index];
}

double & Deque::at(const size_t index) {
    if(index < 0 || index >= _size)
        throw std::out_of_range("Deque::at() : index out of range");
    return _container[_front + index];
}

const double & Deque::at(const size_t index) const {
    return const_cast<Deque*>(this)->at(index);
}

double & Deque::front() const {
    if(empty())
        throw std::out_of_range("Deque::front() : deque is empty!");
    return _container[_front];
}

double & Deque::back() const {
    if(empty())
        throw std::out_of_range("Deque::front() : deque is empty!");
    return _container[_front + _size - 1];
}

double * Deque::data() const {
    return (_container + _front);
}


/* --------- Modifiers --------- */

void Deque::push_back(double value) {
    if(!_container) {
        reserve(INITIAL_CAPACITY);
    }
    else if((_front + _size) == _capacity) {
        reserve(_capacity * EXPANSION_FACTOR);
    }
    _container[_front + _size] = value;
    _size++;
}

void Deque::push_front(double value) {
    if(_capacity == 0) {
        reserve(INITIAL_CAPACITY);
    }
    else if(_front == 0) {
        reserve(_capacity * EXPANSION_FACTOR);
    }
    _container[--_front] = value;
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
    _front++;
}

void Deque::clear(bool erase_flag) {
    if(erase_flag) {
        erase();
        _container = nullptr;
        _capacity = 0;
    }
    _front = _capacity/2;
    _size = 0;
}


/* --------- Comparisons --------- */

bool operator==(const Deque &deque1, const Deque &deque2) {
    if(deque1._size != deque2._size) {
        return false;
    }
    for(int i=0; i< deque1._size; i++) {
        if(deque1[i] != deque2[i]) {
            return false;
        }
    }
    return true;
}

bool operator!=(const Deque &deque1, const Deque &deque2) {
    return !(deque1 == deque2);
}

/* --------- Help Functions --------- */

void Deque::copy(const Deque &other) {
    if(_capacity < other._capacity) {
        reserve(other._capacity);
    }
    _size = other._size;
    _front = other._front;
    for(int i=0; i<_size; i++) {
        _container[_front + i] = other._container[_front + i];
    }
}

void Deque::erase() {
    delete[] _container;
}