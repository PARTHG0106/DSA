class Solution {
public:

    void dfs(int n, int m, int i, int j, vector<vector<int>> &vis, vector<vector<int>> &grid, int delRow[], int delCol[]){
        if(vis[i][j] || !grid[i][j]) return;
        vis[i][j] = 1;
        for(int x = 0; x < 4; x++){
            int nr = i + delRow[x], nc = j + delCol[x];
            if(nr < 0 || nc < 0 || nr >= n || nc >= m || vis[nr][nc]) continue;
            dfs(n, m, nr, nc, vis, grid, delRow, delCol);
        }
        return;
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int ans = 0, n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));

        int delRow[] = {-1, 0, 1, 0}, delCol[] = {0, 1, 0, -1};
        for(int i = 0; i < n; i++){
            if(!vis[i][0] && grid[i][0] == 1){
                dfs(n, m, i, 0, vis, grid, delRow, delCol);
            }
            if(!vis[i][m - 1] && grid[i][m - 1] == 1){
                dfs(n, m, i, m - 1, vis, grid, delRow, delCol);
            }
        }
        for(int j = 0; j < m; j++){
            if(!vis[0][j] && grid[0][j] == 1){
                dfs(n, m, 0, j, vis, grid, delRow, delCol);
            }
            if(!vis[n - 1][j] && grid[n - 1][j] == 1){
                dfs(n, m, n - 1, j, vis, grid, delRow, delCol);
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