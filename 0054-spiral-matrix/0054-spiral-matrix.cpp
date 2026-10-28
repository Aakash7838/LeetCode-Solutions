class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> ans;

        int scol = 0;
        int ecol = m - 1;
        int srow = 0;
        int erow = n - 1;

        while (scol <= ecol && srow <= erow) {

            // Traverse top row: left to right
            for (int j = scol; j <= ecol; j++) {
                ans.push_back(matrix[srow][j]);
            }

            // Traverse right column: top to bottom
            for (int i = srow + 1; i <= erow; i++) {
                ans.push_back(matrix[i][ecol]);
            }

            // Traverse bottom row: right to left
            for (int j = ecol - 1; j >= scol && srow < erow; j--) {
                ans.push_back(matrix[erow][j]);
            }

            // Traverse left column: bottom to top
            for (int i = erow - 1; i > srow && scol < ecol; i--) {
                ans.push_back(matrix[i][scol]);
            }

            srow++;
            scol++;
            ecol--;
            erow--;
        }

        return ans;
    }
};