class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size(), minsC = 0, fresh = 0;
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2) q.push({i, j});
                else if(grid[i][j] == 1) fresh++;
            }
        }
        int delRow[] = {-1, 0, 1, 0}, delCol[] = {0, -1, 0, 1};
        while(!q.empty() && fresh){
            int sz = q.size();
            while(sz--){
                int f = q.front().first;
                int s = q.front().second;
                q.pop();
                for(int i = 0; i < 4; i++){
                    int r = f + delRow[i], c = s + delCol[i];
                    if(r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1){
                        grid[r][c] = 2;
                        q.push({r, c});
                        fresh--;
                    }
                }
            }
            minsC++;
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return (fresh == 0) ? minsC : -1;
    }
};