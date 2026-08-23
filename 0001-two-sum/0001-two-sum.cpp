class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mpp;
        for(int i = 0; i < nums.size(); i++){
            int current = nums[i];
            int required = target - current;

            if(mpp.find(required) != mpp.end()){
                return {mpp[required], i};
            }
            mpp[current] = i;
        }
        return {};
    }
};