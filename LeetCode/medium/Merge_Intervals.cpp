class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ret;
        
        sort(intervals.begin(), intervals.end());
        
        int l = -1, r = -1;
        
        for (auto it : intervals) {
            if (l == -1) {
                l = it[0];
                r = it[1];
            }
            else if (r < it[0]) {
                ret.push_back({l, r});
                l = it[0];
                r = it[1];
            }
            else {
                r = max(r, it[1]);
            }
        }
        
        ret.push_back({l, r});
        
        return ret;
    }
};