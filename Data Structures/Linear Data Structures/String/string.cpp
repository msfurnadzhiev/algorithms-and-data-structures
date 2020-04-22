#include "String.h"

const int INITIAL_CAPACITY = 64;

/* ----- Constructors ----- */

String::String() : _data(new char[1]{'\0'}), _length(0), _capacity(1) {}

String::String(const char *str) {
   init(str,strlen(str));
}

String::String(String const &other) {
    init(other._data,other._length);
}

String& String::operator=(const String &other) {
    if(this != &other) {
        if(other._length > _capacity) {
            reserve(other._capacity);
        }
        _length = other._length;
        strncpy(_data,other._data,_length);
    }
    return *this;
}

String::String(String &&other) noexcept {
    move(other);
    other.clear();
}

String& String::operator=(String &&other) noexcept {
    if(this != &other) {
        delete[] _data;
        move(other);
        other.clear();
    }
    return *this;
}

String::~String() {
    delete[] _data;
}


/*-------- Accessors ---------*/

char* String::data() const {
    return _data;
}

char String::operator[](unsigned const index) {
    if(index < 0 || index >= _length) raise(SIGSEGV);   //without check -> undefined behavior
    return *(_data + index);
}


/* -------- Capacity -------- */

bool String::empty() const {
    return _length == 0;
}

void String::clear() {
    _data = nullptr;
    _length = 0;
}

unsigned long String::length() const {
    return _length;
}

unsigned long String::capacity() const {
    return _capacity;
}

void String::reserve(size_t n) {

    if(n > _capacity) {

        char *temp = new char[n];

        for (int i = 0; i < _length; i++) {
            temp[i] = _data[i];
        }

        delete[] _data;

        _data = temp;
        _capacity = n;
    }
}

void String::resize(size_t new_size, char val) {

    reserve(new_size);

    for(size_t i = _length; i < new_size; i++) {
        _data[i] = val;
    }
    _length = new_size;
}



/* ------- Modifiers ------- */

void String::swap(String &object) {
    String temp = *this;
    *this = object;
    object = temp;
}

void String::push_back(const char &val) {

    if(_capacity == 0) {
        reserve(INITIAL_CAPACITY);
    }
    else if(_length == _capacity) {
        reserve(2*_capacity);
    }

    _data[_length++] = val;
}

void String::pop_back() {
    if(_length == 0) return;
    _length--;
}

String& String::operator+=(const String &other) {
    concat(other);
    return *this;
}

String& String::operator+=(const char *str) {
    concat(str, strlen(str));
    return *this;
}



/*---------- Non-member function overloads -----------*/

ostream& operator<<(ostream &out, const String &str) {
    out << str._data;
    return out;
}

istream& operator>>(istream& in, String &str) {
    delete[] str._data;
    str._data = new char[str._capacity];
    in.getline(str._data,str._capacity);
    return in;
}

String operator+(const String &object_1, const String &object_2) {
    String temp = object_1;
    temp += object_2;
    return temp;
}

String operator+(const String &object, const char *str) {
    String temp = object;
    temp += str;
    return temp;
}

String operator+(const char *str, const String &object) {
    String temp;
    temp += str;
    temp += object;
    return temp;
}



/*------------- Help Functions ------------*/

void String::init(const char *str, const size_t n) {
    _length = n;
    _capacity = n + INITIAL_CAPACITY;
    _data = new char[_capacity];
    assert(_data != nullptr);
    strncpy(_data,str,_length);
    _data[_length] = '\0';
}

void String::move(String &other) {
    _length = other._length;
    _capacity = other._capacity;
    _data = other._data;
}

void String::concat(char const *str, unsigned long n) {
    if(_capacity - _length < n) {
        reserve(n + INITIAL_CAPACITY);
    }
    _length += n;
    for(int i=0; i < n; i++) {
        _data[_length + i] = str[i];
    }
}

void String::concat(const String &other) {
    concat(other._data,other._length);
}