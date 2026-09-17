class Solution {
public:

    char isLower(char ch){
        if(ch >= 'A' && ch <= 'Z'){
            return ch + 32;
        }

        return ch;
    }

    bool isAlpha(char ch){
        if(ch >= '0' && ch <= '9' || isLower(ch) >= 'a' && isLower(ch) <= 'z'){
            return true;
        }
        return false;
    }

    bool isPalindrome(string s) {
        int st = 0;
        int end = s.size()-1;

        while(st <= end){
            if(!isAlpha(s[st])){
                st++;
                continue;
            }

            if(!isAlpha(s[end])){
                end--;
                continue;
            }

            if(isLower(s[st]) != isLower(s[end])){
                return false;
            }
            st++;
            end--;
        }

        return true;
        
    }
};