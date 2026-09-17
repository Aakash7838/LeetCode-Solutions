class Solution {
public:

    bool checkDFS(int node, int col, vector<int>& color, vector<vector<int>>& graph){
        color[node] = col;
        for(int neighbor : graph[node]){
            if(color[neighbor] == -1){
                if(!checkDFS(neighbor, 1-col, color, graph)){
                    return false;
                }
            }else if(color[neighbor] == col){
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);

        for(int i = 0; i < V; i++){
            if(color[i] == -1){
                if(checkDFS(i, 0, color, graph) == false){
                    return false; 
                }
            }
        }
        return true;
    }
};