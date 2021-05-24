class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        vector<int> indeg(n);
        int cnt = 0;
        
        for (int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indeg[prerequisites[i][0]]++;
        }
        
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (indeg[i] == 0) q.push(i);
        
        while(!q.empty()) {
            int here = q.front();
            cnt++;
            q.pop();
            
            for (auto there : adj[here]) 
                if (--indeg[there] == 0) q.push(there);
        }
        
        return cnt == n;
    }
};