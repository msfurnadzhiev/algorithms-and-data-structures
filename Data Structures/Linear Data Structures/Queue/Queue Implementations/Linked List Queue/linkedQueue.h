#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H


template <typename T>
struct node {
    T data;
    node<T>* next;
};

template <typename T>
class Queue {

    node<T>* front;
    node<T>* rear;

    void deleteQueue();
    void copyQueue(const Queue<T>&);

public:
    Queue();                                //Default constructor...
    Queue(const Queue<T>&);                 //Copy constructor...
    Queue& operator= (const Queue<T>&);     //Copy assignment operator...
    ~Queue();                               //Destructor...

    template <typename U>
    friend istream& operator>>(istream&, Queue<U>&);		//Overload operator>>...
			
    template <typename U>
    friend ostream& operator<< (ostream&, const Queue<U>&);	//Overload operator<<...

    bool empty() const;
    void enqueue(T const&);
    void dequeue(T&);
    void head(T&);
};

#endif //QUEUE_QUEUE_H

