class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n     = (int)nums.size();
        int total = 1 << n;  // 2^n subsets

        // result array — total subsets, har subset mein max n elements
        vector<vector<int>> result;

        for(int mask = 0; mask < total; mask++){

            // current subset banao
            vector<int> subset;

            for(int i = 0; i < n; i++){

                // i-th bit set hai mask mein?
                if(mask & (1<<i)){
                    subset.push_back(nums[i]);
                }
            }

            result.push_back(subset);
        }

        return result;
    }
};