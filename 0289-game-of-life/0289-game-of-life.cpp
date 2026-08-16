class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int rows = (int)board.size();
        int cols = (int)board[0].size();

        // 8 directions — sab neighbors
        int dx[] = {-1,-1,-1, 0, 0, 1, 1, 1};
        int dy[] = {-1, 0, 1,-1, 1,-1, 0, 1};

        // Step 1: Har cell ka next state calculate karo
        // Original values save karne ke liye extra matrix
        vector<vector<int>> next(rows, vector<int>(cols, 0));

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){

                // Live neighbors count karo
                int liveNeighbors = 0;

                for(int d = 0; d < 8; d++){
                    int ni = i + dx[d];
                    int nj = j + dy[d];

                    // Boundary check + live cell check
                    if(ni>=0 && ni<rows &&
                       nj>=0 && nj<cols &&
                       board[ni][nj] == 1){
                        liveNeighbors++;
                    }
                }

                // Rules apply karo
                if(board[i][j] == 1){
                    // Live cell
                    if(liveNeighbors == 2 || liveNeighbors == 3){
                        next[i][j] = 1;  // survive
                    } else {
                        next[i][j] = 0;  // dies
                    }
                } else {
                    // Dead cell
                    if(liveNeighbors == 3){
                        next[i][j] = 1;  // born
                    } else {
                        next[i][j] = 0;  // stays dead
                    }
                }
            }
        }

        // Step 2: Board update karo
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                board[i][j] = next[i][j];
            }
        }
    }
};