class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int n = nums.size();

        int sum = 0;

        // First Window
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }

        int maxSum = sum;

        // Slide Window
        for (int i = k; i < n; i++) {

            sum += nums[i];      // Add new element
            sum -= nums[i - k];  // Remove old element

            maxSum = max(maxSum, sum);
        }

        return (double)maxSum / k;
    }
};