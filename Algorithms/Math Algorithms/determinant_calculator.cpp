#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> determinant;

void get_cofactor(determinant& A, determinant& B, int s, int t, int n) {

    int rows=0, columns=0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++){
            if(i != s && j != t) {
                B[rows][columns++] = A[i][j];
                if(columns == n-1) {
                    columns = 0;
                    rows++;
                }
            }
        }
    }
}

int determinant_calculator(determinant& A, int n) {
    int D = 0;

    if(n == 1) {
        return A[0][0];
    }

    determinant B(n);
    for(vector<int>& b : B) {
        b.resize(n);
    }

    int sign = 1;
    for(int j=0; j<n; j++) {

        get_cofactor(A,B,0,j,n);
        D += sign * A[0][j] *  determinant_calculator(B,n-1);
        sign*=-1;
    }

    return D;
}

int main() {

    determinant A = {{1,0,2,-1},{3,0,0,5},{2,1,4,-3},{1,0,5,0}};
    cout << determinant_calculator(A,A.size());
    return 0;
}
