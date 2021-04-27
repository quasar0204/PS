class Solution {
public:
    int one(int idx, string& s) {
        int ret = 0;
        
        while(idx - ret >= 0 && idx + ret < s.size() && s[idx - ret] == s[idx + ret]) {
            ret++;
        }
        
        return ret - 1;
    }
    
    int two(int l, int r, string& s) {
        int ret = 0;
        
        if (s[l] != s[r]) return -1;
        
        while(l - ret >= 0 && r + ret < s.size() && s[l - ret] == s[r + ret]) {
            ret++;
        }
        
        return ret;
    }
    
    string longestPalindrome(string s) {
        string ret;
        int idx, mxn;
        mxn = -1;
        
        for (int i = 0; i < s.size(); i++) {
            int cur = one(i, s);
            
            if (cur > mxn) {
                mxn = cur;
                idx = i;
            }
        }
        
        ret = s.substr(idx - mxn, 2 * mxn + 1);
        
        mxn = -1;
        
        for (int i = 0; i < (int)s.size() - 1; i++) {
            int cur = two(i, i + 1, s);
            
            if (cur > mxn) {
                mxn = cur;
                idx = i;
            }
        }
        
        if (mxn * 2 > (int)ret.size()) {
            ret = s.substr(idx - mxn + 1, 2 * mxn);
        }
        
        return ret;
    }
};