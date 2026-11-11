class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size(), i = 0, j = 0, s = 0;
        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int> (m, 0));
        for (i = 0; i < n; i++) {
            if (board[i][0] == 'O'){
                q.push({i, 0});
                vis[i][0] = 1;
            }
            if(board[i][m - 1] == 'O'){
                q.push({i, m - 1});
                vis[i][m - 1] = 1;
            }
        }
        for (j = 0; j < m; j++) {
            if (board[0][j] == 'O'){
                q.push({0, j});
                vis[0][j] = 1;
            }
            if(board[n - 1][j] == 'O'){
                q.push({n - 1, j});
                vis[n - 1][j] = 1;
            }
        }
        int delRow[] = {-1, 0, 1, 0}, delCol[] = {0, 1, 0, -1};
        while(!q.empty()){
            s = q.size();
            while(s--){
                i = q.front().first;
                j = q.front().second;
                q.pop();
                for(int a = 0; a < 4; a++){
                    int nr = i + delRow[a], nc = j + delCol[a];
                    if(nr < 0 || nc < 0 || nr >= n || nc >= m || vis[nr][nc]) continue;
                    if(board[nr][nc] == 'O'){
                        vis[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }
        }
        for(i = 0; i < n; i++){
            for(j = 0; j < m; j++){
                if(board[i][j] == 'O' && !vis[i][j]) board[i][j] = 'X';
            }
        }
        return;
    }
};