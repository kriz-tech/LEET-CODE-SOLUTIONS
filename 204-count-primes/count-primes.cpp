class Solution {
public:
    int countPrimes(int n) {
        vector<int>primes;
        vector<int>lp(n+1, 0);

        for(int i = 2; i < n; i++){
            if(lp[i] == 0){
                lp[i] = i;
                primes.push_back(i);
            }
            for(int p : primes){
                if(p > lp[i] || p * i >= n) break;
                lp[p * i] = p;
            }
        }
        return primes.size();
    }
};