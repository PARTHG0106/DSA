class Solution {
public:
    void searchLand(int m, int n, int i, int j, vector<vector<int>> &visited, vector<vector<char>>& grid){
        if(visited[i][j] || grid[i][j] == '0') return;
        // while(i + 1 < m || j + 1 < n){
            visited[i][j] = 1;
            if(i + 1 < m)searchLand(m, n, i + 1, j, visited, grid);
            if(i - 1 >= 0)searchLand(m, n, i - 1, j, visited, grid);
            if(j + 1 < n)searchLand(m, n, i, j + 1, visited, grid);
            if(j - 1 >= 0) searchLand(m, n, i, j - 1, visited, grid);
        // }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), islands = 0;
        vector<vector<int>> visited(m, vector<int> (n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '0' || visited[i][j]) continue;
                islands++;
                searchLand(m, n, i, j, visited, grid);
            }
        }
        return islands;
    }
};