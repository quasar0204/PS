class Solution {
public:
    const int dr[4] = {0, 0, -1, 1};
    const int dc[4] = {-1, 1, 0, 0};
    
    void bfs(int Y, int X, vector<vector<char>>& grid, vector<vector<bool>>& visit) {
        int m = visit.size();
        int n = visit[0].size();
        visit[Y][X] = true;
        queue<pair<int,int>> q;
        
        q.push({Y, X});
        while(!q.empty()) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            
            for (int i = 0; i < 4; i++) {
                int ny = y + dr[i];
                int nx = x + dc[i];
                
                if (ny >= m || nx >= n || ny < 0 || nx < 0) continue;
                if (visit[ny][nx] || grid[ny][nx] == '0') continue;
                
                visit[ny][nx] = true;
                
                q.push({ny, nx});
            }
        }
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ret = 0;
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        
        for (int y = 0; y < m; y++)
            for (int x = 0; x < n; x++) 
                if (grid[y][x] == '1' && !visit[y][x]) {
                    ret++;
                    bfs(y, x, grid, visit);
                }
            
        
        return ret;
    }
};