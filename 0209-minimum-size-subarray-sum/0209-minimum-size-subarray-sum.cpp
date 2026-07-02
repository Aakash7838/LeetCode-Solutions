class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int windowSum = 0;
        int minLen = n+1;

        for(int right = 0; right < n; right++){
            windowSum += nums[right];

            while(windowSum >= target){
                int len = right - left + 1;
                if(len < minLen){
                    minLen = len;
                }
                windowSum -= nums[left];
                left++;
            }
        }
        return minLen == n+1 ? 0 : minLen;
    }
};