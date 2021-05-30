class Solution {
public:
    int uniquePaths(int m, int n) {
        long long ret = 1;
        long long up = m + n - 1;
        
        for (int i = 1; i < min(m, n); i++)
            ret *= (up - i);
        for (long long i = 1; i < min(m, n); i++)
            ret /= i;
        
        return ret;
    }
};