class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> result(m * n);
        
        int r = 0, c = 0;
        bool going_up = true;
        
        for (int i = 0; i < m * n; i++) {
            result[i] = mat[r][c];
            
            if (going_up) {
                if (c == n - 1) { 
                    r++; 
                    going_up = false; 
                } 
                else if (r == 0) { 
                    c++; 
                    going_up = false; 
                } 
                else { 
                    r--; 
                    c++; 
                }
            } else {
                if (r == m - 1) { 
                    c++; 
                    going_up = true; 
                } 
                else if (c == 0) { 
                    r++; 
                    going_up = true; 
                } 
                else { 
                    r++; 
                    c--; 
                }
            }
        }
        return result;
    }
};