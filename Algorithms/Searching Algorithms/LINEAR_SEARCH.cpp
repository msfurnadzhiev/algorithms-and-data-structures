
//Average-case complexity: T(n)=О(n), M(n)=O(1)


//in arrays
template <typename T>
int LINEAR_SEARCH(T* A, int n, T x) {
    for (int i = 0; i < n; i++) {
        if(A[i] == x) {
            return i;
        }
    }
    return -1;
}



//in files
template <typename T>
long LINEAR_SEARCH_IN_FILE(ifstream& fd, T x) {
    fd.seekg(0, ios::end);
    int n = fd.tellg()/sizeof(T);
    cout << n << endl;
    for(int i=0; i<n; i++) {
        T a;
        fd.seekg(i*sizeof(T));
        fd.read((char*) &a, sizeof(T));
        if(x == a) {
            return i;
        }
    }
    return -1;
}
