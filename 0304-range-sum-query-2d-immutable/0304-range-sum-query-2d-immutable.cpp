class NumMatrix {
    vector<vector<int>> prefix;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = (int)matrix.size();
        int cols = (int)matrix[0].size();

        // Size (rows+1) × (cols+1) — extra row/col
        prefix.assign(rows+1, vector<int>(cols+1, 0));

        // Prefix banao
        for(int i = 1; i <= rows; i++){
            for(int j = 1; j <= cols; j++){
                prefix[i][j] = matrix[i-1][j-1]
                             + prefix[i-1][j]
                             + prefix[i][j-1]
                             - prefix[i-1][j-1];
            }
        }
    }

    int sumRegion(int r1, int c1, int r2, int c2) {
        // 0-indexed to 1-indexed convert
        return prefix[r2+1][c2+1]
             - prefix[r1][c2+1]
             - prefix[r2+1][c1]
             + prefix[r1][c1];
    }
};