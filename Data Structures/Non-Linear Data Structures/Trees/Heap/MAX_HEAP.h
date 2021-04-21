#ifndef _MAX_HEAP_H
#define _MAX_HEAP_H

template <typename T>
class Heap {
    T* heap;
    int heap_size;

public:
    int LEFT(int index) { return (2 * index + 1); }

    int RIGHT(int index) { return (2 * index + 2); }

    int PARENT(int index) { return (index / 2); }

    void MAX_HEAPIFY(int index) {
        int l = LEFT(index);
        int r = RIGHT(index);
        int largest = index;
        if(l < heap_size && heap[l] > heap[index]) {
            largest = l;
        }
        if(r < heap_size && heap[r] > heap[largest]) {
            largest = r;
        }
        if(largest != index) {
            swap(heap[index], heap[largest]);
            MAX_HEAPIFY(largest);
        }
    }

    void BUILD_MAX_HEAP(T* A, int n) {
        heap_size = n;
        heap = A;
        int index = (heap_size-1)/2;
        while(index >= 0) {
            MAX_HEAPIFY(index);
            index--;
        }
    }

    void HEAPSORT(T* A, int n) {
        BUILD_MAX_HEAP(A,n);
        for(int i = n-1; i>= 0; i--) {
            swap(A[0],A[i]);
            MAX_HEAPIFY(i);
        }
    }


};

#endif //_MAX_HEAP_H
