#include "Deque.h"


/* --------- Constructors --------- */

Deque::Deque() {
    reserve(INITIAL_CAPACITY);
}

Deque::Deque(size_t n) {
    reserve(n);
}

Deque::Deque(const Deque & source) {
    copy(source);
}

Deque & Deque::operator=(const Deque & source) {
    if(this != &source){
        copy(source);
    }
    return *this;
}

Deque::~Deque() noexcept {
    erase();
}


/* --------- Capacity --------- */

bool Deque::empty() const noexcept{
    return m_size == 0;
}

size_t Deque::size() const noexcept {
    return m_size;
}

size_t Deque::capacity() const noexcept {
    return m_capacity;
}

void Deque::reserve(size_t n) {

    if(n <= m_capacity) return;

    //if buffer == nullptr then new throw std::bad_alloc()
    double * buffer = new double[n];

    size_t buffer_front = (n - m_size) / 2;

    for(size_t i = 0; i < m_size; i++) {
        buffer[buffer_front + i] = m_container[ m_front + i];
    }

    delete[] m_container;
    m_container = buffer;
    m_capacity = n;
    m_front = buffer_front;
}


/* --------- Element access --------- */

double & Deque::operator[](const size_t index) noexcept {
    return m_container[m_front + index];
}

const double & Deque::operator[](const size_t index) const noexcept{
    return m_container[m_front + index];
}

double & Deque::at(const size_t index) {
    if(index < 0 || index >= m_size)
        throw std::out_of_range("Deque::at() : index out of range");
    return m_container[m_front + index];
}

const double & Deque::at(const size_t index) const {
    return const_cast<Deque*>(this)->at(index);
}

double & Deque::front() {
    if(empty())
        throw std::logic_error("Deque::front() : deque is empty!");
    return m_container[m_front];
}

const double & Deque::front() const {
    if(empty())
        throw std::logic_error("Deque::front() : deque is empty!");
    return m_container[m_front];
}

double & Deque::back() {
    if(empty())
        throw std::logic_error("Deque::front() : deque is empty!");
    return m_container[m_front + m_size - 1];
}

const double & Deque::back() const {
    if(empty())
        throw std::logic_error("Deque::front() : deque is empty!");
    return m_container[m_front + m_size - 1];
}

double * Deque::data() noexcept {
    return (m_container + m_front);
}

const double * Deque::data() const noexcept {
    return (m_container + m_front);
}


/* --------- Modifiers --------- */

void Deque::push_back(double value) {
    if(!m_container) {
        reserve(INITIAL_CAPACITY);
    }
    else if((m_front + m_size) == m_capacity) {
        reserve(m_capacity * EXPANSION_FACTOR);
    }
    m_container[m_front + m_size] = value;
    m_size++;
}

void Deque::push_front(double value) {
    if(m_capacity == 0) {
        reserve(INITIAL_CAPACITY);
    }
    else if(m_front == 0) {
        reserve(m_capacity * EXPANSION_FACTOR);
    }
    m_container[--m_front] = value;
    m_size++;
}

//if deque is empty return exception
void Deque::pop_back() {
    if(empty()) {
        return;
    }
    m_size--;
}

void Deque::pop_front() {
    if(empty()) {
        return;
    }
    m_size--;
    m_front++;
}

void Deque::clear(bool erase_flag) noexcept {
    if(erase_flag) {
        erase();
        m_container = nullptr;
        m_capacity = 0;
    }
    m_front = m_capacity/2;
    m_size = 0;
}


/* --------- Comparisons --------- */

bool operator==(const Deque & alpha, const Deque & beta) noexcept {
    if(alpha.m_size != beta.m_size) {
        return false;
    }
    for(int i=0; i< alpha.m_size; i++) {
        if(alpha[i] != beta[i]) {
            return false;
        }
    }
    return true;
}

bool operator!=(const Deque & alpha, const Deque & beta) noexcept {
    return !(alpha == beta);
}


/* --------- Help Functions --------- */

void Deque::copy(const Deque & source) {
    if(m_capacity < source.m_capacity) {
        reserve(source.m_capacity);
    }
    m_size = source.m_size;
    m_front = source.m_front;
    for(int i=0; i<m_size; i++) {
        m_container[m_front + i] = source.m_container[m_front + i];
    }
}

void Deque::erase() noexcept {
    delete[] m_container;
}
