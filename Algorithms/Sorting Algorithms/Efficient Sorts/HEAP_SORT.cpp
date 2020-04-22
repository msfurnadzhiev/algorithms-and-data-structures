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
void HEAP_SORT(T* array, int n) {
    for(int i=n/2-1; i>=0; i--) {
        HEAPIFY(array,n,i);
    }
    for(int i=n-1; i>=0; i--) {
        swap(array[0],array[i]);
        HEAPIFY(array,i,0);
    }
}

