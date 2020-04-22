#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<vector<int>> Graph;

//Average-case time complexity:   T(n)=О(|V|+|E|)
//Average-case space complexity:  M(n)=O(|V|)
void BREADTH_FIRST_SEARCH(Graph& G, int s) {
    
    int graphSize = G.size();

    int* color = new int[graphSize]; //1=WHITE, 2=GREY, 3=BLACK
    //int* distance = new int[n];
    //int* previous = new int[n];

    for (int i = 0; i < graphSize; i++) {
        color[i] = 1;
        //distance[i] = INT32_MAX;
        //previous[i] = -1;
    }

    color[s] = 2;
    //distance[s] = 0;

    queue<int> Q;
    Q.push(s);

    while (!Q.empty()) {
        int x = Q.front();
        Q.pop();
        for (int v : G[x]){
            if (color[v] == 1) {
                color[v] = 2;
                //previous[v] = x;
                //distance[v] = distance[x] + 1;
                Q.push(v);
            }
        }
        color[x] = 3;
        cout << x << " ";
    }
    delete[] color;
}

int main() {

    Graph G = {{1},{2,3,4},{5},{6},{7,8},{6,9,10},{7},{},{},{10},{11},{}};

    BREADTH_FIRST_SEARCH(G,0);

    return 0;
}


