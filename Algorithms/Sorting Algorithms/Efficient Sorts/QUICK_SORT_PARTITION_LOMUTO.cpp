
// Average-case complexity: T(n)=О(nlog(n)), M(n)=1

template <typename T>
int PARTITION_LOMUTO(T* A,int left,int right) {
    T pivot = A[right];
    int i = (left-1);

    for(int j=left; j<=right-1; j++) {
        if(A[j] <= pivot) {
            swap(A[++i],A[j]);
        }
    }
    swap(A[i+1],A[right]);
    return (i+1);
}

template <typename T>
void QUICK_SORT(T* A, int left, int right) {
    if(left < right) {
        int partition_index = PARTITION_LOMUTO(A,left,right);

    QUICK_SORT(A,left,partition_index-1);
    QUICK_SORT(A,partition_index+1,right);

    }
}

