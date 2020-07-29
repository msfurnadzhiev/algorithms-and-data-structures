#include <iostream>
using namespace std;

// d is the number of characters in the  input alphabet
#define d 256

//Average-case complexity: T(n,m)=О(n+mv+cn/q), M(n,m)=O(m)
void RABIN_KARP_ALGORITHM(string T, string P, int q) {
    // q is a prime number

    int h=1, p=0, t=0;

    for(int i=0; i<P.size()-1; i++) {
        h = (d * h) % q;
    }

    for(int i=0; i<P.size(); i++) {
        p = (d * p + P[i]) % q;
        t = (d * t + T[i]) % q;
    }

    for(int i=0; i<= T.size() - P.size(); i++) {
        if(p == t) {
            int j;
            for(j=0; j<P.size(); j++) {
                if(T[i+j] != P[j]) {
                    break;
                }
            }
            if(j == P.size()) {
                cout << "Pattern found at index: " << i << endl;
            }
        }

        if(i < T.size()-P.size()) {
            t = (d * (t - T[i] * h) + T[i+P.size()]) % q;
            if(t < 0) {
                t = t + q;
            }
        }
    }
}

int main() {

    string T = "cozacocacolacococacola";
    string P = "cocacola";
    int q = 7;
    RABIN_KARP_ALGORITHM(T, P, q);

    return 0;
}
