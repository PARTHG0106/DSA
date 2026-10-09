class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();
        vector<int> col(c, 0), row(r, 0);
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(matrix[i][j] == 0) col[j] = 1, row[i] = 1;
            }
        }
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(col[j] == 1 || row[i] == 1)  matrix[i][j] = 0;
            }
        }
    }
};