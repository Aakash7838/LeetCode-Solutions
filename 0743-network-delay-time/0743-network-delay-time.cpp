class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n + 1);

        for(auto& edge : times){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            graph[u].push_back({v,w});
        }

        const int INF = 1e9;

        vector<int>dist(n+1, INF);
        dist[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0, k});

        while(!pq.empty()){
            auto[currentDist, node] = pq.top();
            pq.pop();

            if(currentDist > dist[node])
                continue;
            
            for(auto [neighbor, weight] : graph[node]){
                int newDist = currentDist + weight;

                if(newDist < dist[neighbor]){
                    dist[neighbor] = newDist;

                    pq.push({newDist, neighbor});
                }
            }
        }
        int ans = 0;

        for(int i = 1; i <= n; i++){
            if(dist[i] == INF){
                return -1;
            }
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};