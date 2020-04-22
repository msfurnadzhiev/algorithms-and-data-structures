
//Average-case complexity: T(n)=О(log(n)), M(n)=O(1)


//for arrays
template <typename T>
int BINARY_SEARCH(T x, T* A, int n) {
    int middle, left = 0, right = n-1;
    if(x < A[left]) { return -1; }
    if(x == A[left]) { return 0; }
    if(x > A[right]) { return n; }
    while(right - left > 1) {
        middle = (left + right) / 2;
        if(A[middle] == x ){
            return middle;
        }        
	if(x <= A[middle]) {
            right = middle;
        }
        else {
            left = middle;
        }
    }
    return -1;
}


//for files
template <typename T>
long BINARY_SEARCH_IN_FILE(fstream& file, T x) {
    file.seekg(0, ios::end);

    long  n = file.tellg()/sizeof(T);
    T a_left, a_right, a_middle;
    long middle, left = 0, right = n-1;

    file.seekg(left*sizeof(T));
    file.read((char*)& a_left, sizeof(T));
    file.seekg(right*sizeof(T));
    file.read((char*)& a_right, sizeof(T));

    if(x < a_left) { return -1; }

    if(x == a_left) { return 0; }

    if(x > a_right) { return n;}

    while(right - left > 1) {
        middle = (left + right) / 2;
        file.seekg(middle*sizeof(T));
        file.read((char*)& a_middle, sizeof(T));
        if(x <= a_middle) { right = middle; }
        else { left = middle; }
    }
    return right;
}
