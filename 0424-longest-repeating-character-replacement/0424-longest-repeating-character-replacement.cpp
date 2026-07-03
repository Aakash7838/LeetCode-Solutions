class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int freq[26] = {0};
        int maxFreq = 0;
        int left = 0;

        for(int right = 0; right < n; right++){
            freq[s[right] - 'A']++;

            if(freq[s[right] - 'A'] > maxFreq){
                maxFreq = freq[s[right] - 'A'];
            }

            int windowSum = right - left + 1;
            if(windowSum - maxFreq > k){
                freq[s[left] - 'A']--;
                left++;
            }
        }

        return n-left;
    }
};