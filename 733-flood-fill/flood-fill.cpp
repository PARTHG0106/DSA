class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image.empty()) return image;
        int ini = image[sr][sc], m = image.size(), n = image[0].size(), i = sr, j = sc;
        if(ini == color) return image;
        image[sr][sc] = color;
        // colorFill(ini, m, n, sr, sc, image, color);
        queue<pair<int, int>> q;
        q.push({sr, sc});
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if(i - 1 >= 0 && image[i - 1][j] == ini) image[i - 1][j] = color, q.push({i - 1, j});  
            if(j - 1 >= 0 && image[i][j - 1] == ini) image[i][j - 1] = color, q.push({i, j - 1});  
            if(i + 1 < m && image[i + 1][j] == ini) image[i + 1][j] = color, q.push({i + 1, j});  
            if(j + 1 < n && image[i][j + 1] == ini) image[i][j + 1] = color, q.push({i, j + 1});  
        }
        return image;
    }
};