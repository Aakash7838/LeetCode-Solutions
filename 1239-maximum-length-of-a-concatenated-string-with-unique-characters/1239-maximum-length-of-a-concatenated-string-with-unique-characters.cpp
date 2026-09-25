class Solution {
public:

    int ans = 0;

    void backtrack(vector<string>& arr, int index, int usedMask, int length){
        ans = max(ans, length);

        for(int i = index; i < arr.size(); i++){
            int stringMask = 0;
            bool valid = true;

            for(char c : arr[i]){
                int bit = 1 << (c - 'a');

                if(stringMask & bit){
                    valid = false;
                    break;
                }

                stringMask |= bit;
            }

            if(!valid){
                continue;
            }

            if((usedMask & stringMask) == 0){
                backtrack(arr, i+1, usedMask | stringMask, length + arr[i].size());
            }


        }
    }

    int maxLength(vector<string>& arr) {
        backtrack(arr, 0, 0, 0);
        return ans;
    }
};