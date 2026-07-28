class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans(2);
        unordered_map<int, int> visitedElement;

        for(int i = 0; i < nums.size(); i++){
            int currElement = nums[i];
            int numToFind = target-currElement;

            if(visitedElement.count(numToFind)){
                ans[0] = visitedElement[numToFind];
                ans[1] = i;
                return ans;
            }
            visitedElement[currElement] = i;
        }
        return ans;
    }
};