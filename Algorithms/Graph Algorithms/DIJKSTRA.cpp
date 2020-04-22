//Average-case performance: 	  T(n)=О(|V|log(|V|)+|E|)
//Average-case space complexity:  M(n)=O(|V|)

typedef vector<pair<pair<int,int>,double>> Matrix;

Matrix Graph = {{{0,1},2},{{1,2},6},{{1,3},5},{{1,4},3},{{2,5},3},{{3,6},10},{{4,7},9},{{4,8},2},{{5,6},6},{{5,9},2},{{5,10},7},{{6,7},1},{},{},{{9,10},4},{{10,11},8},{}}; //vector<pair<pair<vertex,vertex>,weight>>


vector<double> DIJKSTRA(Matrix& G, int n, int source) {
    vector<double> distance(n);
    list<int> L;

    for (int v = 0; v < n; v++) {
        distance[v] = INT32_MAX; //distance[v] = infinity;
        L.push_back(v);
    }

    distance[source] = 0;


    while(!L.empty()) {
        int min_dist = L.back();
        for (int i = 0; i < L.size(); i++) {
            int x = L.back();
            L.pop_back();
            L.push_front(x);
            if(distance[x] <= distance[min_dist]) {
                min_dist = x;
            }
        }
        L.remove(min_dist);


        for (int j = 0; j < G.size(); j++) {
            if(G[j].first.first == min_dist) {
                double temp = distance[min_dist] + G[j].second;
                if(temp < distance[G[j].first.second]) {
                    distance[G[j].first.second] = temp;
                }
            }
        }
    }

    return distance;
}

