class Solution {
public:

    int numEnclaves(vector<vector<int>>& grid) {
        int ans = 0, n = grid.size(), m = grid[0].size();

        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++){
            if(grid[i][0] == 1){
                q.push({i, 0});
                grid[i][0] = 0;
            }
            if(grid[i][m - 1] == 1){
                q.push({i, m - 1});
                grid[i][m - 1] = 0;
            }
        }
        for(int j = 0; j < m; j++){
            if(grid[0][j] == 1){
                q.push({0, j});
                grid[0][j] = 0;
            }
            if(grid[n - 1][j] == 1){
                q.push({n - 1, j});
                grid[n - 1][j] = 0;
            }
        }

        int delRow[] = {-1, 0, 1, 0}, delCol[] = {0, 1, 0, -1};
        while(!q.empty()){
            auto [a, b] = q.front();
            q.pop();
            for(int x = 0; x < 4; x++){
                int nr = a + delRow[x], nc = b + delCol[x];
                if(nr < 0 || nc < 0 || nr >= n || nc >= m || !grid[nr][nc]) continue;
                q.push({nr, nc});
                grid[nr][nc] = 0;
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1) ans++;
            }
        }
        return ans;
    }
};