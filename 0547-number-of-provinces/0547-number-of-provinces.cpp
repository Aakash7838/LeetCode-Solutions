class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DSU dsu(n);
        int components = n;

        for(int i = 0; i < n; i++){
            for(int j = i+ 1; j < n; j++){
                if(isConnected[i][j] == 1){
                    if(dsu.unite(i, j)){
                        components--;
                    }
                }
            }
        }

        return components;
    }

    struct DSU {
        vector<int>parent, rank;

        DSU(int n): parent(n), rank(n, 0){
            for(int i = 0; i < n; i++){
                parent[i] = i;
            }
        }

        int find(int x){
            if(parent[x] != x){
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }

        bool unite(int x, int y){
            int rx=find(x), ry = find(y);
            if(rx == ry) return false;
            if(rank[rx] < rank[ry]) parent[rx] = ry;
            else if(rank[rx] > rank[ry]) parent[ry] = rx;
            else{parent[ry] = rx; rank[rx]++;}
            return true;
        }
    };
};