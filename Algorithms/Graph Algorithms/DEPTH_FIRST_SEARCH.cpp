#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> Graph;

//Average-case time complexity:   T(n)=О(|V|+|E|)
//Average-case space complexity:  M(n)=O(|V|)
void DEPTH_FIRST_SEARCH(Graph& G, int s) {

    static vector<int> visited(G.size(),false);

    visited[s] = true;
    cout << s << " ";

    for (int v : G[s]) {
        if(!visited[v]) {
            DEPTH_FIRST_SEARCH(G,v);
        }
    }
}


int main() {

    Graph G = {{1},{2,3,4},{5},{6},{7,8},{6,9,10},{7},{},{},{10},{11},{}};

    DEPTH_FIRST_SEARCH(G,0);

    return 0;
}


