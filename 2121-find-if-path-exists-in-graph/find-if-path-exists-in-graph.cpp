class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source == destination) return true;
        vector<int> adj[n + 1];
        for(auto& x : edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        queue<int> q;
        vector<int> vis(n + 1, 0);
        q.push(source);
        vis[source] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int x : adj[node]){
                if(x == destination) return true;
                else if(!vis[x]) q.push(x), vis[x] = 1;
            }
        }
        return false;
    }
};