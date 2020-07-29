template <typename T>
void SHELL_SORT_PHASE(T* array, int n, int gap) {
    for(int i=gap; i<n; i++) {
        T key = array[i];
        int j = i-gap;
        while(j>=0 && array[j]>key) {
            array[j+gap] = array[j];
            j -= gap;
        }
        array[j+gap] = key;
    }
}

template <typename T>
void SHELL_SORT(T* array, int n){
    static const int gaps[] = {1, 4, 10, 23, 57, 132, 301, 701};

    for(int i = sizeof(gaps)/ sizeof(gaps[0])-1; i >= 0; i--) {
        SHELL_SORT_PHASE(array, n, gaps[i]);
    }
}
