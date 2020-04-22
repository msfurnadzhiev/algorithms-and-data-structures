#include <iostream>
#include <algorithm>
using namespace std;

/*  Find the sum of contiguous subarray within a
    one-dimensional array of numbers which has the largest sum. */

int KADANE_ALGORITHM(int* A, int n) {

    int max_sum = 0, temp_sum = 0;
    for(int i=0; i<n; i++) {
        temp_sum += A[i];
        if(temp_sum > max_sum) {
            max_sum = temp_sum;
        }
        if(temp_sum < 0) {
            temp_sum = 0;
        }
    }

    return max_sum;
}


int main() {

    int A[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << KADANE_ALGORITHM(A,9);

    return 0;
}
