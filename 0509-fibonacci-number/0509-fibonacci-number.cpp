class Solution {
public:
    int fib(int n, vector<int>& m){
        if(n <= 1){
            return n;
        }

        if(m[n] == -1){
            m[n] = fib(n-1)+ fib(n-2);
        }

        return m[n];

    }
    int fib(int n) {
        vector<int>m(n+1, -1);

        return fib(n, m);
    }
};