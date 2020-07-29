//Average-case complexity: T(n)=О(n²), M(n)=O(1)

template <typename T>
void INSERTION_SORT(T* array, int n) {
    int key = 0, j = 0;
    for (int i = 1; i < n; i++) {
        key = array[i];
        j = i-1;
        while (j>=0 && array[j]>key) {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }
}
