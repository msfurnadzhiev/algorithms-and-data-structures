//Average-case complexity: T(n)=О(n²), M(n)=O(1)


template <typename T>
void BUBBLE_SORT(T* array, int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if(array[j] > array[j+1]) {
                swap(array[j],array[j+1]);
            }
        }
    }
}

