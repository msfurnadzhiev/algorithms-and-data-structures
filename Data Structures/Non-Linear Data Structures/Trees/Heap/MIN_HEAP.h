#ifndef _MIN_HEAP_H
#define _MIN_HEAP_H

template <typename T>
class Heap {
    T* heap;
    int heap_size;

public:
    int LEFT(int index) { return (2 * index + 1); }

    int RIGHT(int index) { return (2 * index + 2); }

    int PARENT(int index) { return (index / 2); }

    void MIN_HEAPIFY(int index) {
        int l = LEFT(index);
        int r = RIGHT(index);
        int smallest = index;
        if(l < heap_size && heap[l] < heap[index]) {
            smallest = l;
        }
        if(r < heap_size && heap[r] < heap[smallest]) {
            smallest = r;
        }
        if(smallest != index) {
            swap(heap[index], heap[smallest]);
            MIN_HEAPIFY(smallest);
        }
    }

    void BUILD_MIN_HEAP(T* A, int n) {
        heap_size = n;
        heap = A;
        int index = (heap_size-1)/2;
        while(index >= 0) {
            MIN_HEAPIFY(index);
            index--;
        }
    }
};

#endif //_MIN_HEAP_H
