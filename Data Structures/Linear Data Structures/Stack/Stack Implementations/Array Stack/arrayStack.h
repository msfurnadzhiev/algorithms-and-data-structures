#ifndef ARRAYSTACK_ARRAYSTACK_H
#define ARRAYSTACK_ARRAYSTACK_H

template <typename T>
class ArrayStack {
    T* data;
    int topIndex;
    int capacity;
    
    bool full() const;
    void resize();
    void copy(T const*);
    void deleteStack();
    void copyStack(ArrayStack const&);

public:
    ArrayStack();					//Default constructor...
    ArrayStack(ArrayStack const&);			//Copy constructor...
    ArrayStack& operator=(ArrayStack const &);		//Copy assignment operator...
    ~ArrayStack();					//Destructor...

    template  <typename U>
    friend istream& operator>>(istream&, ArrayStack<U>&);	//Overload operator>>...

    template <typename U>
    friend ostream& operator<<(ostream& os, const ArrayStack<U>&);	//Overload operator<<...

    bool empty() const;
    void push(T const& x);
    T pop();
    T top() const;
};

#endif //ARRAYSTACK_ARRAYSTACK_H

