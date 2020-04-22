#ifndef TESTPROJECT_STRING_H
#define TESTPROJECT_STRING_H

#include <iostream>
#include <string.h>
#include <cassert>
#include <csignal>
using namespace std;

class String {

    char *_data;
    unsigned long _length;
    unsigned long _capacity;

    /*------------- Help Functions ------------*/

    void init(const char *, const size_t);

    void move(String &);

    void concat(const char *, unsigned long);

    void concat(const String &);

public:

    /* ----- Constructors ----- */

    String();

    explicit String(char const *);

    //Copy constructor...
    String(String const &);

    //Copy assignment operator...
    String& operator=(const String &);

    //Move constructor...
    String(String &&) noexcept;

    //Move assignment operator...
    String& operator=(String &&) noexcept;

    ~String();


    /*-------- Accessors ---------*/

    char* data() const;

    char operator[](unsigned);


    /* -------- Capacity -------- */

    bool empty() const;

    void clear();

    unsigned long length() const;

    unsigned long capacity() const;

    void reserve(size_t);

    void resize(size_t, char = '\0');


    /* ------- Modifiers ------- */

    void swap(String &);

    void push_back(const char &);

    void pop_back();

    String& operator+=(const String &);

    String& operator+=(const char *);


    /*---------- Non-member function overloads -------------*/

    friend String operator+(const  String &, const String &);

    friend String operator+(const String &, const char *);

    friend String operator+(const char *, const String &);

    friend ostream& operator<<(ostream &, const String &);

    friend istream& operator>>(istream &, String &);


};

#endif //TESTPROJECT_STRING_H

