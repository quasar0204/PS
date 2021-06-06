class Solution {
public:
    vector<vector<bool>> visit;
    const int dr[4] = {-1, 0, 1, 0};
    const int dc[4] = {0, 1, 0, -1};
    
    void color(int r, int c, vector<vector<char>>& board, vector<vector<bool>>& visit) {
        queue<pair<int, int>> q;
        q.push({r, c});
        visit[r][c] = true;
        vector<pair<int, int>> tmp;
        bool flag = true;
        
        while(!q.empty()) {
            int y = q.front().first;
            int x = q.front().second;
            tmp.push_back(q.front());
            q.pop();
            
            for (int i = 0; i < 4; i++) {
                int ny = y + dr[i];
                int nx = x + dc[i];
                
                if (ny < 0 || nx < 0 || ny >= board.size() || nx >= board[0].size()) {
                    flag = false;
                    continue;
                }
                
                if (visit[ny][nx]) continue;
                if (board[ny][nx] == 'X') continue;
                
                visit[ny][nx] = true;
                q.push({ny, nx});
            }
        }
        
        if (flag) 
            for (auto p : tmp) 
                board[p.first][p.second] = 'X';
       
    }
    void solve(vector<vector<char>>& board) {
        visit.resize(board.size(), vector<bool>(board[0].size(), false));
        
        for (int y = 0; y < board.size(); y++)
            for (int x = 0; x < board[0].size(); x++)
                if (board[y][x] == 'O' && visit[y][x] == false)
                    color(y, x, board, visit);
          
    }
};