class Solution {
public:
    int gcd(int a, int b){

        while(b != 0){
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    int findGCD(vector<int>& nums) {
        int n = nums.size();

        int minVal = nums[0];
        int maxVal = nums[0];

        for(int i = 0; i < n; i++){
            if(nums[i] < minVal){
                minVal = nums[i];
            }
            if(nums[i] > maxVal){
                maxVal = nums[i];
            }
        }

        return gcd(minVal, maxVal);
    }
};