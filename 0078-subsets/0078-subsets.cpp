class Solution {
public:
    vector<vector<int>>result;
    void backtrack(vector<int>& nums, int start, vector<int>& curr){
        result.push_back(curr);

        for(int i = start; i < (int)nums.size(); i++){
            curr.push_back(nums[i]);
            backtrack(nums, i+1, curr);
            curr.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>curr;
        backtrack(nums, 0, curr);
        return result;
    }
};