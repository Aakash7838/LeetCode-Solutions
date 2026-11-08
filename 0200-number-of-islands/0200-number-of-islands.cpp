class Solution {
public:

    int n, m;
    
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    void dfs(int row, int col, vector<vector<char>>& grid){

        grid[row][col] = '0';

        for(int i = 0; i < 4; i++){
            int nrow = row + dr[i];
            int ncol = col + dc[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1'){
                dfs(nrow, ncol, grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();

        int count = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1'){
                    count++;

                    dfs(i, j, grid);
                }
            }
        }
        return count;
    }
};