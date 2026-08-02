class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        long long int num = 0;
        long long int result = 0;
        int sign = 1;
        stack<int> st;

        for(int i = 0; i < n; i++){
            if(isdigit(s[i])){
                num = num*10 + (s[i] - '0');
            }else if(s[i] == '+'){
                result += sign * num;
                num = 0;
                sign = 1;
            }else if(s[i] == '-'){
                result += sign * num;
                num = 0;
                sign = -1;
            }else if(s[i] == '('){
                st.push(result);
                st.push(sign);
                result = 0;
                sign = 1;
            }else if(s[i] == ')'){
                result += sign*num;
                num = 0;
                result *= st.top();
                st.pop();
                result += st.top();
                st.pop();
            }
        }
        return result + sign * num;
    }
};