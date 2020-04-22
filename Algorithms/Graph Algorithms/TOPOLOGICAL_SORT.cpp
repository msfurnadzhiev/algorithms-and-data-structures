//Topological sort with DFS and work with graph (adjacency list)


list<int> sort_order;
vector<int> color(1024,1);

void DFS_VISIT(Matrix& G, int n, int v) {
    color[v] = 2;
    for (int u : G[v]){
        if(color[u]==1) {
            DFS_VISIT(G,n,u);
        }
    }
    color[v] = 3;
    sort_order.push_front(v);
}

void TOPOLOGICAL_SORT(Matrix& G, int n) {
    for (int i = 0; i < n; ++i) {
        if (color[i] == 1) {
            DFS_VISIT(G, n, i);
        }
    }
    for(int a : sort_order) {
        cout << a << " ";
    }
}

