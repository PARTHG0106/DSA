class Solution {
public:
    void traverse(int n, int node, vector<int>& vis, vector<vector<int>>& isConnected){
        for(int i = 1; i < n + 1; i++){
            if(isConnected[node - 1][i - 1] == 1 && vis[i] == 0){
                vis[i] = 1;
                traverse(n, i, vis, isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), province = 0;
        vector<int> vis(n + 1, 0);
        for(int i = 1; i < n + 1; i++){
            if(!vis[i]){
                province++;
                traverse(n, i, vis, isConnected);
            }
        }
        return province;
    }
};