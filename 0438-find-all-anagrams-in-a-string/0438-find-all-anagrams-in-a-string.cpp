class Solution {
public:
    bool isEqual(int a[], int b[]){
        for(int i = 0; i < 26; i++){
            if(a[i] != b[i]){
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<int>result(n);
        int index = 0;

        if(m > n){
            return {};
        }

        int sFreq[26] = {0};
        int pFreq[26] = {0};   

        for(int i = 0; i < m; i++){
            pFreq[p[i] - 'a']++;
        }  

        for(int i = 0; i < m; i++){
            sFreq[s[i] -  'a']++;
        }   

        if(isEqual(pFreq,sFreq)){
            result[index] = 0;
            index++;
        }

        for(int i = m; i < n; i++){
            sFreq[s[i] - 'a']++;

            sFreq[s[i-m] - 'a']--;

            if(isEqual(pFreq,sFreq)){
                result[index] = i-m+1;
                index++;
            }
        }
        result.resize(index);
        return result;
    }
};