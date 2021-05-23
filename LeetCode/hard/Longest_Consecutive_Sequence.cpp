class Solution {
public:
    const int INF = 1987654321;

    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        int ret = 1;

        for (auto num : nums)
            s.insert(num);

        if (s.size() <= 1) return s.size();

        int num = INF;
        int cur = 1;
        for (auto it = s.begin(); it != s.end(); it++) {
            if (num == INF)
                num = *it;
            else {
                if (*it != num + 1) {
                    cur = 1;
                    num = *it;
                    continue;
                }
                num = *it;
                cur++;
                ret = max(ret, cur);
            }
        }

        return ret;
    }
};