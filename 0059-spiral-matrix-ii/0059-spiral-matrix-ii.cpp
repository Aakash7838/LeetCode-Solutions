class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n == 0){
            return {};
        }

        int m = n;

        vector<vector <int>> matrix(m , vector<int>(n));

        int top = 0;
        int down = m - 1; 
        int left = 0;
        int right = n - 1;

        int counter = 1; 

        while(left <= right && top <= down){
            for(int i = left; i <= right; i++){
                matrix[top][i] = counter++;
            }
            top++;

            for(int j = top; j <= down; j++){
                matrix[j][right] = counter++;
            }
            right--;

            if(top <= down){
                for(int i = right; i >= left; i--){
                    matrix[down][i] = counter++;
                }
                down--;
            }
            
            if(left <= right){
                for(int j = down; j >= top; j--){
                    matrix[j][left] = counter++;
                }
                left++;
            }
        
        }
        return matrix;
    }
};