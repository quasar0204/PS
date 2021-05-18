class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret = {{1}};
        
        for (int i = 0; i < numRows - 1; i++) {
            vector<int> cur;
            
            cur.push_back(ret[i][0]);
            
            for (int j = 0; j < (int)ret[i].size() - 1; j++) 
                cur.push_back(ret[i][j] + ret[i][j + 1]);
            
            cur.push_back(ret[i][ret[i].size() - 1]);
            
            ret.push_back(cur);
        }
        
        return ret;
    }
};