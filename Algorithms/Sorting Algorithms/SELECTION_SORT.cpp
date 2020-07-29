//Average-case complexity: T(n)= n(n − 1)/2 = О(n²), M(n)=O(1)


template <typename T>
void SELECTION_SORT(T* array, int n) {
    T min;
    for(int i=0; i<n-1; i++) {
        min = i;
        for (int j=i+1; j<n; j++) {
            if (array[j] < array[min]) {
                min = j;
            }
        }
        swap(array[min],array[i]);
    }
}
