class Solution {
public:

    int fib(int n) {

        if(n <= 1){
            return n;
        }
        int first = 0;
        int second = 1;
        int result = 0;

        for(int i = 2; i <= n; i++){
            result = first + second;
            first = second;
            second = result;
        }

        return result;
    }
};