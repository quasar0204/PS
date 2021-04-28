class Solution {
public:
    void solve(vector<string> &ret, string &str, int l, int r) {
        if (l == 0 && r == 0) {
            ret.push_back(str);
            return;
        }
        
        if (l > 0) {
            str.push_back('(');
            solve(ret, str, l - 1, r);
            str.pop_back();
        }
        if (l < r) {
            str.push_back(')');
            solve(ret, str, l, r - 1);
            str.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        string tmp = "";
        
        solve(ret, tmp, n, n);
        
        return ret;
    }
};