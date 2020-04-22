#ifndef STACK_STACK_H
#define STACK_STACK_H
#include <iostream>
using namespace std;

template <typename T>
struct node {
    T data;
    node<T>* next;
};

template <typename T>
class Stack {

    node<T>* top;
    void deleteStack();
    void copyStack(const Stack<T>&);

public:
    Stack();                                //Default constructor...
    Stack(const Stack<T> &);                //Copy constructor...
    Stack& operator= (const Stack<T> &);    //Copy assignment operator...
    ~Stack();                               //Destructor...

    template  <typename U>
    friend istream& operator>>(istream&, Stack<U>&);  		//Overload operator>>...

    template <typename U>
    friend ostream& operator<<(ostream& os, const Stack<U>&);	//Overload operator<<...

    void push(T const&);    //T pop();
    void pop(T&);
    bool empty() const;
    void peek(T&);          //T top() const;
    void print();
};

#endif //STACK_STACK_H

