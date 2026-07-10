class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int n = nums.size();
        int x = -1;
        int y = -1;

        for(int i = 0; i <= n; i++){
            x = x^i;
        }
        for(int i = 0; i < n; i++){
            y = y^nums[i];
        }

        return x^y;
        
    }
};
