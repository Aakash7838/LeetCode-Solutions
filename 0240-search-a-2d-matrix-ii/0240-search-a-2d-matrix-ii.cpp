class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = (int)matrix.size();
        int cols = (int)matrix[0].size();

        // Top-right se shuru
        int row = 0;
        int col = cols - 1;

        while(row < rows && col >= 0){

            if(matrix[row][col] == target){
                return true;  // mila!
            }
            else if(matrix[row][col] > target){
                col--;  // left jao
            }
            else{
                row++;  // neeche jao
            }
        }

        return false;
    }
};