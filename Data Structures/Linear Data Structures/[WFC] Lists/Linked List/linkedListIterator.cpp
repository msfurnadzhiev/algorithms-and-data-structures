#ifndef LINKEDLIST_LINKEDLISTITERATOR_H
#define LINKEDLIST_LINKEDLISTITERATOR_H
#include "LinkedList.h"

/* the iterator pattern is a design pattern in which an iterator is used
   to traverse a container and access the container's elements */

//help class LinkedListIterator
template <typename T>
class LinkedListIterator {

    Node<T>* ptr;

public:
    friend class LinkedList<T>;
    LinkedListIterator(Node<T>* _ptr = nullptr): ptr(_ptr) {}

    bool valid() const {
        return ptr != nullptr;
    }

    LinkedListIterator<T> next() const {
        if (!valid()) {
            return *this;
        }
        return LinkedListIterator(ptr->next);
    }

    T& get() const {
        if (!valid()) {
            return 0;
        }
        return ptr->data;
    }

    bool operator==(LinkedListIterator const& it) const {
        return ptr == it.ptr;
    }

    bool operator!=(LinkedListIterator const& it) const {
        return !(*this == it);
    }

    // *it <-> it.get()
    T& operator*() const {
        return get();
    }

    // it++ <-> it = it.next()
    LinkedListIterator operator++(int) {
        LinkedListIterator prev = *this;
        ++(*this);
        return prev;
    }

    // ++it <-> it = it.next()
    LinkedListIterator& operator++() {
        return *this = next();
    }

    // it <-> it.valid()
    operator bool() const {
        return valid();
    }
};


#endif //LINKEDLIST_LINKEDLISTITERATOR_H

