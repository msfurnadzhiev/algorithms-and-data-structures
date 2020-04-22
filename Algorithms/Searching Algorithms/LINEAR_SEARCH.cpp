
//Average-case complexity: T(n)=О(n), M(n)=O(1)


//for arrays
template <typename T>
int LINEAR_SEARCH(T x, T* A, int n) {
    int i;
    for (i = 0; i < n; i++) {
        if(A[i] == x) {
            break;
        }
    }
    return i;
}


//for files
template <typename T>
long LINEAR_SEARCH_IN_FILE(fstream& file, T x) {
    file.seekg(0, ios::end);
    long n = file.tellg()/sizeof(T);
    long i = -1; T a;
    do {
        i++;
        file.seekg(i*sizeof(T));
        file.read((char*)& a, sizeof(T));
    } while(i<n-1 && x != a);

    if(x == a) {
        return i;
    }
    return n;
}

