class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;

        for(int i = 0; i < k-1; i++){
            sum += nums[i];
        }

        int maxSum = INT_MIN;
        int l = 0;

        for(int i = k-1; i < n; i++){
            sum += nums[i];

            if(maxSum < sum){
                maxSum = sum;
            }

            sum -= nums[l];
            l++;

        }

        return (double)maxSum/k;
    }
};