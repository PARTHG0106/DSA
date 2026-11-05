class Solution {
public:
    void dfs(int n, int i, vector<int> &visited, vector<vector<int>> &isConnected){
        if(visited[i]) return;
        visited[i] = 1;
        for(int j = 0; j < n; j++){
            if(isConnected[i][j] == 1) dfs(n, j, visited, isConnected);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), provinces = 0;
        vector<int> visited(n, 0);
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                provinces++;
                dfs(n, i, visited, isConnected);
            }
        }
        return provinces;
    }
};