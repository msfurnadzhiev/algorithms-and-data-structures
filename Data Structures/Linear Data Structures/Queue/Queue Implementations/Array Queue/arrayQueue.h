#ifndef ARRAYQUEUE_ARRAYQUEUE_H
#define ARRAYQUEUE_ARRAYQUEUE_H

const int SIZE = 100;
template <typename T>
class ArrayQueue {
    int front;
    int rear;
    int queue_size;
    int queue_len;
    T *data;

    void copyQueue(const ArrayQueue &);
    void deleteQueue();

public:
    ArrayQueue(int = SIZE);			//Default constructor...
    ArrayQueue(const ArrayQueue &);		//Copy constructor...
    ArrayQueue &operator=(const ArrayQueue &);  //Copy assignment operator...
    ~ArrayQueue();				//Destructor...

    template  <typename U>
    friend istream& operator>>(istream&, ArrayQueue<U>&);	//Overload operator>>...

    template <typename U>
    friend ostream& operator<<(ostream& os, const ArrayQueue<U>&);	//Overload operator<<...

    bool empty() const;
    bool full() const;
    void push(const T &);
    void pop(T &);
    void head(T &) const;
};
#endif //ARRAYQUEUE_ARRAYQUEUE_H

