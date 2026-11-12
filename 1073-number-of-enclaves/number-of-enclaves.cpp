class Solution {
public:

    int numEnclaves(vector<vector<int>>& grid) {
        int ans = 0, n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        
        queue<pair<int, int>> q;
        int delRow[] = {-1, 0, 1, 0}, delCol[] = {0, 1, 0, -1};
        for(int i = 0; i < n; i++){
            if(!vis[i][0] && grid[i][0] == 1){
                q.push({i, 0});
                vis[i][0] = 1;
            }
            if(!vis[i][m - 1] && grid[i][m - 1] == 1){
                q.push({i, m - 1});
                vis[i][m - 1] = 1;
            }
        }
        for(int j = 0; j < m; j++){
            if(!vis[0][j] && grid[0][j] == 1){
                q.push({0, j});
                vis[0][j] = 1;
            }
            if(!vis[n - 1][j] && grid[n - 1][j] == 1){
                q.push({n - 1, j});
                vis[n - 1][j] = 1;
            }
        }

        while(!q.empty()){
            auto [a, b] = q.front();
            q.pop();
            for(int x = 0; x < 4; x++){
                int nr = a + delRow[x], nc = b + delCol[x];
                if(nr < 0 || nc < 0 || nr >= n || nc >= m || vis[nr][nc] || !grid[nr][nc]) continue;
                vis[nr][nc] = 1;
                q.push({nr, nc});
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && grid[i][j] == 1) ans++;
            }
        }
        return ans;
    }
};