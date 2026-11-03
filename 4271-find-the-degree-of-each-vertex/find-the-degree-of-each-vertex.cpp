class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int n = matrix.size(), i = 0;
        vector<int> ans(n, 0);
        for(const auto& x : matrix){
            for (const auto& a : x) ans[i] += a;
            i++;
        }
        return ans;
    }
};