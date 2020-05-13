
//Average-case complexity: T(n)=О(log(n)), M(n)=O(1)


//in arrays
template <typename T>
int BINARY_SEARCH(T* A, int n, T x) {
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




//in files
template <typename T>
long BINARY_SEARCH_IN_FILE(ifstream& fd, T x) {
    fd.seekg(0, ios::end);
    int  n = fd.tellg()/sizeof(T);
    
    T a_left, a_right, a_middle;
    long middle, left = 0, right = n-1;

    fd.seekg(left*sizeof(T));
    fd.read((char*)& a_left, sizeof(T));
    
    fd.seekg(right*sizeof(T));
    fd.read((char*)& a_right, sizeof(T));
    
    if(x < a_left) { return -1; }
    if(x == a_left) { return 0; }
    if(x > a_right) { return n;}

    while(right - left > 1) {
        middle = (left + right) / 2;
        fd.seekg(middle*sizeof(T));
        fd.read((char*)& a_middle, sizeof(T));
        if(x <= a_middle) { 
            right = middle; 
        }
        else { 
            left = middle; 
        }
    }
    return -1;
}

