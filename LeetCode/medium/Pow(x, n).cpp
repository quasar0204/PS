class Solution {
public:
    double solve(double x, long long n) {
        double ret = 1.0;
        
        if (n == 0) return ret;
        
        if (n % 2) 
            ret *= x;
        
        double half = solve(x, n / 2);
        
        return ret = ret * half * half;
    }
    
    double myPow(double x, long long n) {
        if (n >= 0) return solve(x, n);
        
        return (1.0 / solve(x, -n));
    }
};