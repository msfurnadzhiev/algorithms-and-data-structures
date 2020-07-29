// Average-case complexity: T(n)=О(nlog(n)), M(n)=1

template <typename T>
void HEAPIFY(T* array, int n, int index) {
    int largest = index;
    int left = 2*index + 1;
    int right = 2*index + 2;

    if(left < n && array[left] > array[largest]) {
        largest = left;
    }

    if(right < n && array[right] > array[largest]) {
        largest = right;
    }

    if(largest != index) {
        swap(array[index],array[largest]);
        HEAPIFY(array,n,largest);
    }
}

template <typename T>
void HEAPSORT(T* A, int n) {

    //build max-heap
    for(int i=n/2-1; i>=0; i--) {
        HEAPIFY(A,n,i);
    }

    //heapsort
    for(int i=n-1; i>=0; i--) {
        swap(A[0],A[i]);
        HEAPIFY(A,i,0);
    }
}

