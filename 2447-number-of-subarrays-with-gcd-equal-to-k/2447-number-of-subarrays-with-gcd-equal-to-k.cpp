class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0; 

        for(int i = 0; i < n; i++){
            int currentGCD = 0; 

            for(int j = i; j < n; j++){
                currentGCD = gcd(currentGCD, nums[j]);
                
                if(currentGCD == k){
                    count++;
                }
            }
        }
        return count;
    }
};