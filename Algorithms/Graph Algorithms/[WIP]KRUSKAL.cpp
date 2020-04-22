#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <list>
using namespace std;

typedef vector<pair<pair<int,int>,double>> Matrix;

Matrix Graph = {{{0,1},2},{{1,2},6},{{1,3},5},{{1,4},3},{{2,5},3},{{3,6},10},{{4,7},9},{{4,8},2},{{5,6},6},{{5,9},2},{{5,10},7},{{6,7},1},{},{},{{9,10},4},{{10,11},8},{}};


void KRUSKAL(Matrix& G, int n) {

    for(int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            if (G[j].second < G[i].second) {
                swap(G[j],G[i]);
            }
        }
    }

    vector<pair<pair<int,int>,double>> MST; //Minimum spanning tree

    for (int k = 0; k < G.size(); ++k) {
        
    }

}


int main() {

    KRUSKAL(Graph,12);
    return 0;
}
