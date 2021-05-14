class Solution {
public:
    const int mxn = 5050505;
    bool isNotPrime[5050505];
    
    void check() {
        for (int i = 2; i * i < mxn; i++) {
            if (isNotPrime[i]) continue;
            
            for (int j = i * i; j < mxn; j += i)
                isNotPrime[j] = true;
        }
    }
    
    int countPrimes(int n) {
        int ret = 0;
        
        check();
        for (int i = 2; i < n; i++)
            if (!isNotPrime[i]) ret++;
        
        return ret;
    }
};