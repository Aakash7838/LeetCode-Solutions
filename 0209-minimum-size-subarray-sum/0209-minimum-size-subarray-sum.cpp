class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int windowSum = 0;
        int minLen = n+1;

        for(int i = 0; i < n; i++){
            windowSum += nums[i];

            while(windowSum >= target){
                int len = i - left + 1;
                minLen = min(minLen, len);
                windowSum -= nums[left];
                left++;
            }
        }

        return minLen == n+1 ? 0 : minLen;
    }
};