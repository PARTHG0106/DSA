class Solution {
public:
    static vector<int> findDegrees(vector<vector<int>>& matrix) {
        const int n=matrix.size();
        vector<int> deg(n, 0);
        for(int i=1; i<n; i++) 
            for(int j=0; j<i; j++){
                bool is1=matrix[i][j];
                deg[i]+=is1;
                deg[j]+=is1;
            }
        return deg;
    }
};