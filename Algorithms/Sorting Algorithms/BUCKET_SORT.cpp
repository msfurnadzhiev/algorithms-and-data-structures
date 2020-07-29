// Average-case complexity: T(n)=О(n), M(n)=O(n).

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Sorting algorithm for floating point numbers which are in range from 0.0 to 1.0
void BUCKET_SORT(float A[], int n) {

    vector<vector<float>> B;
    B.reserve(n);

    // Put array elements in different buckets
    for(int i=0; i<n; i++) {
        B[(int)(n*A[i])].push_back(A[i]);
    }

    // Sort individual buckets
    for(int i=0; i<n; i++) {
        sort(B[i].begin(),B[i].end());
    }

    int index = 0;
    for(int i=0; i<n; i++) {
        for (float b : B[i]) {
            A[index++] = b;
        }
    }
}
