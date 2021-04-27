class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ret, cur, l, r;
        int check[256] = {};
        ret = cur = l = r = 0;
        
        for (; r < s.size(); r++) {
            check[s[r]]++;
            
            if (check[s[r]] > 1) {
                ret = max(ret, r - l);
                while(check[s[r]] > 1) {
                    check[s[l++]]--;
                }
            }
        }
        
        ret = max(ret, r - l);
        
        return ret;
    }
};