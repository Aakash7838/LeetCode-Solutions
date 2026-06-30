class Solution {
public:
    int reverse(int n) {
        long long int r = 0,  min = INT_MIN, max=INT_MAX ;;

        while( n!=0){
            int ID = n%10;
            if (r < min/10 || r > max/10 ) return 0 ;
            r *= 10;
            r += ID;
            n = n/10;
        }
        return r;
        
    }
};