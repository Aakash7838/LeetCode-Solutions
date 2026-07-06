class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int right = n-1; 
        int left = 0;

        vector<int>result(2, -1);

        while(left <= right){
            int mid = left + (right - left)/2;

            if(nums[mid] == target){
                result[0] = mid;
                right = mid-1;
            }else if(nums[mid] > target){
                right = mid-1;
            }else{
                left = mid + 1;
            }
        }

        right = n-1;
        left = 0;

        while(left <= right){
            int mid = left + (right - left)/2;

            if(nums[mid] == target){
                result[1] = mid;
                left = mid + 1;
            }else if(nums[mid] > target){
                right = mid-1;
            }else{
                left = mid + 1;
            }
        }

        return result;
    }
};