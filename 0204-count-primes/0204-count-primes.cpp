class Solution {
public:
    int countPrimes(int n) {
        
        vector<bool>primes(n+1, true);
        int count = 0;

        for(int i = 2; i < n; i++){
            if(primes[i] == true){
                count++;
            }
            if(primes[i] == true){
                for(int j = i*2; j < n; j = j + i){
                    primes[j] = false;
                }
            }
        }
        return count;
    }
};