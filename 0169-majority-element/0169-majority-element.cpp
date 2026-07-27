class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int>countMap;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            countMap[nums[i]]++;

            if(countMap[nums[i]] > n/2){
                return nums[i];
            }

        }
        return -1;
    }
};