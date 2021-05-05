class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        
        map<string,vector<string>> m;
        
        for(string str: strs) {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            m[tmp].push_back(str);
        }
        
        
        for (auto v : m) {
            ret.push_back(v.second);
        }
    
        return ret;
    }
};