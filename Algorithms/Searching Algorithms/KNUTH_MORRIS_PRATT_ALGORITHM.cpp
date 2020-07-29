#include <iostream>
#include <string.h>
using namespace std;


void COMPUTE_PREFIX_FUNCTION(string P, int* prefix) {
    int k=0;
    for(int i=1; i<P.length(); i++) {
        while(k>0 && P[k]!=P[i]) {
            k = prefix[k];
        }
        if(P[k]==P[i]) {
            k = k + 1;
        }
        prefix[i]=k;
    }
}

//String Matching Algorithm
//Average-case complexity: T(n,m)=О(n), M(n,m)=O(m)
void KNUTH_MORRIS_PRATT_ALGORITHM(string T, string P) {
    int n = T.length(), m = P.length();
    int* prefix = new int[m];
    COMPUTE_PREFIX_FUNCTION(P,prefix);

    int k = 0;
    for(int i=0; i<n;i++) {
        cout << i << " " << k << endl;
        while(k>0 && P[k]!=T[i]) {
            k = prefix[k-1];
        }
        if(P[k]==T[i]) {
            k = k + 1;
        }
        if(k==m) {
            cout << i-m+1 << endl;
            k = prefix[k];
        }
    }
}

int main() {

    string T = "cozacocacolacococacola";
    string P = "cocacola";

    KNUTH_MORRIS_PRATT_ALGORITHM(T, P); //4, 14

    return 0;
}
