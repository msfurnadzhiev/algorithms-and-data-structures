// Average-case complexity: T(n)=О(n+k), M(n)=O(n+k), k is the range.

template <typename T>
void COUNTING_SORT(T* array, int n, int range) {
    T* count = new T[range+1];
    T* new_array = new T[n];

    for(int i=0; i<n; i++) {
        count[array[i]] += 1;
    }

    for(int i=1; i<=range+1; i++) {
        count[i] += count[i-1];
    }

    for(int i=0; i<n; i++) {
        new_array[count[array[i]]-1] = array[i];
        count[array[i]]--;
    }

    for(int i=0; i<n; i++) {
        array[i] = new_array[i];
    }

    delete[] new_array;
    delete[] count;
}
