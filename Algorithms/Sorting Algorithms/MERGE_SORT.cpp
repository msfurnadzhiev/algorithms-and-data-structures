// Average-case complexity: T(n)=О(n.log(n)), M(n)=O(n)

template <typename T>
void MERGE(T* A, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    T* L = new T[n1];
    T* R = new T[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = A[left + i];
    }

    for (int j = 0; j < n2; j++) {
        R[j] = A[middle + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k++] = L[i++];
        } else {
            A[k++] = R[j++];
        }
    }

    while (i < n1) {
        A[k++] = L[i++];
    }

    while (j < n2) {
        A[k++] = R[j++];
    }
}

template <typename T>
void MERGE_SORT(T* A,int left, int right) {
    if(left < right) {
        int middle = (left+right)/2;
        MERGE_SORT(A,left,middle);
        MERGE_SORT(A,middle+1,right);
        MERGE(A,left,middle,right);
    }
}


