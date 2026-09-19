class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int xorVal = 0;

        for(int i = 0; i < n; i++){
            xorVal = xorVal ^ nums[i];
        }

        return xorVal;
    }
};