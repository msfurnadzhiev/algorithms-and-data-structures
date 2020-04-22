// Average-case complexity: T(n)=О(nlog(n)), M(n)=1

template <typename T>
int PARTITION_HOARE(T* A,int left,int right) {
    T pivot = A[left];
    int i = left - 1, j = right + 1;

    while(true) {
        do {
            i++;
        } while(A[i]<pivot);

        do {
            j--;
        } while(A[j]>pivot);

        if(i<j) {
            swap(A[i],A[j]);
        }
        else {
            return j;
        }
    }
}

template <typename T>
void QUICK_SORT(T* A, int left, int right) {
    if(left < right) {
        int partition_index = PARTITION_HOARE(A,left,right);

    QUICK_SORT(A,left,partition_index);
    QUICK_SORT(A,partition_index+1,right);

    }
}

