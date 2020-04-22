//Average-case performance: 	  T(n)=О(|V|³)
//Average-case space complexity:  M(n)=O(|V|³)

typedef vector<pair<pair<int,int>,double>> Matrix;

Matrix Graph = {{{0,1},2},{{1,2},6},{{1,3},5},{{1,4},3},{{2,5},3},{{3,6},10},{{4,7},9},{{4,8},2},{{5,6},6},{{5,9},2},{{5,10},7},{{6,7},1},{},{},{{9,10},4},{{10,11},8},{}};


vector<vector<double>> FLOYD_WARSHALL(Matrix& G, int n) {

    vector<vector<double>> distance(n,vector<double>(n,INT32_MAX));

    for (int i = 0; i < n; ++i) {
        distance[i][i] = 0;
    }

    for (auto& e : G) {
        distance[e.first.first][e.first.second] = e.second;
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if(distance[i][j] > distance[i][k] + distance[k][j]){
                    distance[i][j] = distance[i][k] + distance[k][j];
                }
            }
        }
    }
    return distance;
}

