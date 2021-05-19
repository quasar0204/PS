class Solution {
public:
    vector<vector<int>> adj;
    
    int diff(string &a, string &b) {
        int ret = 0;
        for (int i = 0; i < a.size(); i++) 
            if (a[i] != b[i]) ret++;
        
        return ret;
    }
    
    int solve(int s, int e) {
        queue<int> q;
        q.push(s);
        vector<int> visit(s + 1);
        visit[s] = 1;
        
        while(!q.empty()) {
            int here = q.front();
            int cost = visit[here];
            q.pop();
            
            for (auto there : adj[here]) {
                if (visit[there]) continue;
                if (there == e) return cost + 1;
                
                visit[there] = cost + 1;
                q.push(there);
            }
        }
        
        return 0;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        
        int n = wordList.size();
        int e = -1;
        adj.resize(n + 1);
        
        for (int i = 0; i < n; i++) {
            if (wordList[i] == endWord) e = i;
            for (int j = 0; j < n; j++) 
                if (diff(wordList[i], wordList[j]) == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }        
        }
        
        if (e == -1) return 0;
        
        return solve(n - 1, e);
    }
};