class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    ans[i][j] = 0;
                }
            }
        }
        int delRow[] = {-1, 0, 1, 0}, delCol[] = {0, 1, 0, -1}, dist = 0, s = 0;
        while(!q.empty()){
            s = q.size();
            dist++;
            while(s--){
                int i = q.front().first, j = q.front().second;
                q.pop();
                for(int it = 0; it < 4; it++){
                    int nrow = i + delRow[it], ncol = j + delCol[it];
                    if (nrow < 0 || ncol < 0 || nrow >= m || ncol >= n || ans[nrow][ncol] != -1) continue;
                    ans[nrow][ncol] = dist;
                    q.push({nrow, ncol});
                }
            }
        }
        return ans;
    }
};