class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int INF = m + n;

        vector<vector<int>> ans(m, vector<int>(n, INF));

        // Top-left -> Bottom-right
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 0) ans[i][j] = 0;
                else {
                    if(i > 0)
                        ans[i][j] = min(ans[i][j], ans[i-1][j] + 1);
                    if(j > 0)
                        ans[i][j] = min(ans[i][j], ans[i][j-1] + 1);
                }
            }
        }

        // Bottom-right -> Top-left
        for(int i = m-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {
                if(i < m-1)
                    ans[i][j] = min(ans[i][j], ans[i+1][j] + 1);
                if(j < n-1)
                    ans[i][j] = min(ans[i][j], ans[i][j+1] + 1);
            }
        }

        return ans;
    }
};
