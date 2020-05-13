
#ifndef MINHEAP_H
#define MINHEAP_H


struct Node {
    long element;
    int parent_index;
};

void swap(Node* x, Node* y) {
    Node temp = *x;
    *x = *y;
    *y = temp;
}

class MinHeap {
public:
    Node* heap;
    int heap_size;

    MinHeap(Node a[], int size) {
        heap_size = size;
        heap = a;
        int index = (heap_size-1)/2;
        while(index >= 0) {
            heapify(index);
            index--;
        }
    }

    void heapify(int index) {
        int l = get_left(index);
        int r = get_right(index);
        int smallest = index;
        if (l < heap_size && heap[l].element < heap[index].element)
            smallest = l;
        if (r < heap_size && heap[r].element < heap[smallest].element)
            smallest = r;
        if (smallest != index) {
            swap(&heap[index], &heap[smallest]);
            heapify(smallest);
        }
    }

    int get_left(int index) { return (2 * index + 1); }

    int get_right(int index) { return (2 * index + 2); }

    Node get_root() {  return heap[0]; }

    void replace_root(Node x)
    {
        heap[0] = x;
        heapify(0);
    }
};


#endif //MINHEAP_H

