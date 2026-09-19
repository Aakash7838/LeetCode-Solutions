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

        int max = nums[0];
        int min = nums[0];

        for(int i = 0; i < n; i++){
            if(nums[i] > max){
                max = nums[i];
            }else if(nums[i] < min){
                min = nums[i];
            }
        }

        return gcd(min, max);
    }
};