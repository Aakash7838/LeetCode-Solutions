class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int st = 0; 
        int e = nums.size()-1;

        while(st < e){
            int mid = st + (e - st)/2;

            if(nums[mid] < nums[mid+1]){
                st = mid + 1;
            }else{
                e = mid;
            }
        }
        return st;
    }
};